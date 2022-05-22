#include "chunk.hpp"

std::vector<uint8_t> stellar::Chunk::getCode() {
    return this->code;
}

void stellar::Chunk::writeByte(uint8_t byte) {
    this->code.push_back(byte);
}

std::vector<stellar::Value> stellar::Chunk::getValues() {
    return this->values;
}
