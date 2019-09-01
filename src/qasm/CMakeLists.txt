cmake_minimum_required(VERSION 3.1)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(PARSER parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
FLEX_TARGET(LEXER lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)

ADD_FLEX_BISON_DEPENDENCY(LEXER PARSER)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_executable(main ${BISON_PARSER_OUTPUTS} ${FLEX_LEXER_OUTPUTS})