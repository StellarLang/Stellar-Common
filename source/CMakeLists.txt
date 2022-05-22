set(CMAKE_CXX_STANDARD 20)

add_library(stellar chunk.cpp chunk.hpp value.cpp value.hpp ../test/disasm/main.cpp)
