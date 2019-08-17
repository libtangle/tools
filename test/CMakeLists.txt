add_subdirectory(gtest)

include_directories(./gtest/googletest/include)

set(test_src
  run_all.cpp
  foo_test.cpp
  bar_test.cpp
  answer_test.cpp
)

add_executable(test_nemo ${test_src})

target_link_libraries(test_nemo
  gtest
  ${NEMO_LIB_NAME}
  ${CMAKE_THREAD_LIBS_INIT}
  ${MATH_LIBS}
)

add_test(
  NAME tests
  COMMAND test_nemo
)
