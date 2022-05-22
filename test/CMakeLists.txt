set(CMAKE_CXX_STANDARD 20)

add_executable(disasmTest disasm/main.cpp)
target_link_libraries(disasmTest PRIVATE stellar)
target_include_directories(disasmTest PRIVATE ../source)