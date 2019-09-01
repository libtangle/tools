add_subdirectory(gtest)

include_directories(./gtest/googletest/include)

set(test_src
  run_all.cpp
  lib_test.cpp
)

add_executable(test_tangle ${test_src})

target_link_libraries(test_tangle
  gtest
  ${TANGLE_LIB_NAME}
)

add_test(
  NAME tests
  COMMAND test_tangle
)
