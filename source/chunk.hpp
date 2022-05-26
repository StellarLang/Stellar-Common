#pragma once

#include <vector>
#include <cstdint>

#include "value.hpp"

namespace stellar {
    enum OpCode {
        OP_RETURN = 0x00,
        OP_CONSTANT = 0x01,
        OP_ADD = 0x02,
        OP_SUBTRACT = 0x03,
        OP_MULTIPLY = 0x04,
        OP_DIVIDE = 0x05,
        OP_NEGATE = 0x06,
        OP_NOT = 0x07,
    };

    class Chunk {
    public:
        void writeInstruction(OpCode instruction, int line);
        void writeByte(uint8_t byte, int line);
        void writeConstant(const Value& value, int line);
        size_t addConstant(const Value& value);

        [[maybe_unused]] std::vector<uint8_t> getCode();
        [[maybe_unused]] std::vector<Value> getConstants();
        [[maybe_unused]] std::vector<int> getLines();

        void disassemble(const std::string& name);
        size_t disassembleInstruction(size_t offset);
    private:
        size_t constantInstruction(const std::string& name, size_t offset);

        std::vector<uint8_t> code;
        std::vector<Value> constants;
        std::vector<int> lines;
    };
}
