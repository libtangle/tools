add_subdirectory(gtest)

include_directories(./gtest/googletest/include)

set(test_src
  run_all.cpp
  foo_test.cpp
  bar_test.cpp
  answer_test.cpp
)

add_executable(test_tangle ${test_src})

target_link_libraries(test_tangle
  gtest
  ${TANGLE_LIB_NAME}
  ${CMAKE_THREAD_LIBS_INIT}
  ${MATH_LIBS}
)

add_test(
  NAME tests
  COMMAND test_tangle
)
