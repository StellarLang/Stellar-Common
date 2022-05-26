#include "chunk.hpp"

#include <iostream>
#include <iomanip>

[[maybe_unused]] std::vector<uint8_t> stellar::Chunk::getCode() {
    return this->code;
}

void stellar::Chunk::writeByte(uint8_t byte, int line) {
    this->code.push_back(byte);
    this->lines.push_back(line);
}

[[maybe_unused]] std::vector<stellar::Value> stellar::Chunk::getConstants() {
    return this->constants;
}

void stellar::Chunk::writeInstruction(stellar::OpCode instruction, int line) {
    writeByte(instruction, line);
}

size_t stellar::Chunk::addConstant(const stellar::Value& value) {
    this->constants.push_back(value);
    return this->constants.size() - 1;
}

void stellar::Chunk::writeConstant(const stellar::Value& value, int line) {
    size_t index = addConstant(value);
    writeInstruction(OP_CONSTANT, line);
    writeByte(index, line);
}

void stellar::Chunk::disassemble(const std::string& name) {
    std::cout << "== " << name << " ==" << std::endl;

    for (size_t offset = 0; offset < code.size();) {
        offset = disassembleInstruction(offset);
    }
}

inline size_t simpleInstruction(const std::string& name, size_t offset) {
    std::cout << name << std::endl;
    return offset + 1;
}

size_t stellar::Chunk::constantInstruction(const std::string& name, size_t offset) {
    size_t constant = code.at(offset + 1);

    std::cout << std::setw(16) << std::setfill(' ') << std::left << name;
    std::cout << std::setw(4) << std::right << std::dec << constant;
    std::cout << " <";
    printValue(constants[constant]);
    std::cout << ">" << std::endl;

    return offset + 2;
}

size_t stellar::Chunk::disassembleInstruction(size_t offset) {
    std::cout << std::setfill('0') << std::setw(4) << std::dec << offset << " ";

    uint8_t byte = code[offset];
    if (offset > 0 &&
        lines[offset] == lines[offset - 1]) {
        std::cout << "   | ";
    } else std::cout << std::setfill(' ') << std::setw(4) << lines[offset] << " ";

    switch (byte) {
        case stellar::OP_RETURN: {
            return simpleInstruction("OP_RETURN", offset);
        }
        case stellar::OP_CONSTANT: {
            return constantInstruction("OP_CONSTANT", offset);
        }
        case stellar::OP_ADD: {
            return simpleInstruction("OP_ADD", offset);
        }
        case stellar::OP_SUBTRACT: {
            return simpleInstruction("OP_SUBTRACT", offset);
        }
        case stellar::OP_MULTIPLY: {
            return simpleInstruction("OP_MULTIPLY", offset);
        }
        case stellar::OP_DIVIDE: {
            return simpleInstruction("OP_DIVIDE", offset);
        }
        case stellar::OP_NEGATE: {
            return simpleInstruction("OP_NEGATE", offset);
        }
        case stellar::OP_NOT: {
            return simpleInstruction("OP_NOT", offset);
        }
        default: {
            std::cout << "Unknown instruction: " << std::hex << byte << std::endl;
            return offset + 1;
        }
    }
}

[[maybe_unused]] std::vector<int> stellar::Chunk::getLines() {
    return this->lines;
}

