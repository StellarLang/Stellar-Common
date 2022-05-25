set(CMAKE_CXX_STANDARD 20)

add_library(stellar-common SHARED chunk.cpp value.cpp)
set_target_properties(stellar-common PROPERTIES PUBLIC_HEADER "chunk.hpp;value.hpp")
install(
        TARGETS stellar-common
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include/stellar
)
