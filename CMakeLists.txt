cmake_minimum_required(VERSION 3.1)
project(tangle)

# Set build type to RELEASE by default:
if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type provided, default to RELEASE.")
  set(CMAKE_BUILD_TYPE "RELEASE")
endif()

# Options can be turned on and off by providing cmake with a -DOPTIONNAME=ON (or OFF) argument.
# For example, to turn off benchmarks, build a shared library, and use sanitize flags in a DEBUG build:
#    cmake .. -DCMAKE_BUILD_TYPE=DEBUG -DTANGLE_BENCH=OFF -DBENCH_STATIC=OFF -DTANGLE_SANITIZE=ON
option(TANGLE_TEST      "Build tests" ON)
option(TANGLE_STATIC    "Builds a static library instead of a shared one" OFF)
option(TANGLE_SANITIZE  "Adds sanitive flags" OFF)

if(TANGLE_STATIC)
  set(TANGLE_LIB_NAME tangle_static)
  set(TANGLE_LIB_TYPE STATIC)
else()
  set(TANGLE_LIB_NAME tangle)
  set(TANGLE_LIB_TYPE SHARED)
endif()

include_directories(. include)

set(CMAKE_CXX_STANDARD 11) # cmake 3.1 supports '98', '11' or '14'. cmake 3.8 or later support '17'.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(TANGLE_SANITIZE)
  set(CMAKE_CXX_FLAGS "-fsanitize=address -fsanitize=undefined ${CMAKE_CXX_FLAGS}")
endif()

add_subdirectory(src)

if(TANGLE_TEST)
  enable_testing()
  add_subdirectory(test)
endif()

message(STATUS "")
message(STATUS "BUILD SUMMARY")
message(STATUS "  CMAKE_GENERATOR      : ${CMAKE_GENERATOR}")
message(STATUS "  Compiler ID          : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "  Build type           : ${CMAKE_BUILD_TYPE}")
message(STATUS "  Library name         : ${TANGLE_LIB_NAME}")
message(STATUS "  Library type         : ${TANGLE_LIB_TYPE}")
message(STATUS "  Build tests          : ${TANGLE_TEST}")
message(STATUS "  Sanitize flags       : ${TANGLE_SANITIZE}")
# message(STATUS "  Boost include dirs   : ${Boost_INCLUDE_DIRS}")
message(STATUS "")
