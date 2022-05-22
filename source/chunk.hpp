#pragma once

#include <vector>
#include <cstdint>

#include "value.hpp"

namespace stellar {
    enum OpCode {
        OP_RETURN = 0x00,
    };

    class Chunk {
    public:
        void writeByte(uint8_t);

        std::vector<uint8_t> getCode();
        std::vector<Value> getValues();
    private:
        std::vector<uint8_t> code;
        std::vector<Value> values;
    };
}
