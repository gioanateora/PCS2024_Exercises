list(APPEND example_headers ${CMAKE_CURRENT_SOURCE_DIR}/sqrt_dot.hpp)
list(APPEND example_headers ${CMAKE_CURRENT_SOURCE_DIR}/sqrt_dot_test.hpp)

list(APPEND example_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(example_sources ${example_sources} PARENT_SCOPE)
set(example_headers ${example_headers} PARENT_SCOPE)
set(example_includes ${example_includes} PARENT_SCOPE)
