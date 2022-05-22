#include "../../source/chunk.hpp"

int main() {
    stellar::Chunk chunk = stellar::Chunk();
    chunk.writeConstant(std::monostate(), 123); // write null constant
    chunk.writeInstruction(stellar::OP_RETURN, 123);
    chunk.writeConstant(false, 124);
    chunk.writeInstruction(stellar::OP_RETURN, 124);
    chunk.writeConstant(true, 125);
    chunk.writeInstruction(stellar::OP_RETURN, 125);
    chunk.writeConstant(1.2, 126);
    chunk.writeInstruction(stellar::OP_RETURN, 126);
    chunk.writeConstant("test", 127);
    chunk.writeInstruction(stellar::OP_RETURN, 127);
    chunk.disassemble("Test Chunk");
    return 0;
}
