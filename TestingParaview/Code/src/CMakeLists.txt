list(APPEND src_headers ${CMAKE_CURRENT_SOURCE_DIR}/UCDUtilities.hpp)
list(APPEND src_sources ${CMAKE_CURRENT_SOURCE_DIR}/UCDUtilities.cpp)

list(APPEND src_headers ${CMAKE_CURRENT_SOURCE_DIR}/UCD_test.hpp)
list(APPEND src_headers ${CMAKE_CURRENT_SOURCE_DIR}/example_unit_test.hpp)

list(APPEND src_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(src_sources ${src_sources} PARENT_SCOPE)
set(src_headers ${src_headers} PARENT_SCOPE)
set(src_includes ${src_includes} PARENT_SCOPE)
