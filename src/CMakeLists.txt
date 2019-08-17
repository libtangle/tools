# Source files (except the main for the executable):
set(tangle_src
  foo.cpp
  bar.cpp
  answer.cpp
)

# Compile the library
add_library(${TANGLE_LIB_NAME} ${TANGLE_LIB_TYPE} ${tangle_src})

# Compile the executable
add_executable(tangle_exe main.cpp)

# Link the executable to the tangle library
target_link_libraries(tangle_exe ${TANGLE_LIB_NAME})

# How and what to install
install(TARGETS ${TANGLE_LIB_NAME} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(TARGETS tangle_exe RUNTIME DESTINATION bin)
install(DIRECTORY ../include/tangle DESTINATION include)
