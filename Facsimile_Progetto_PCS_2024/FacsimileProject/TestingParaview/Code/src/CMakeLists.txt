list(APPEND src_headers ${CMAKE_CURRENT_SOURCE_DIR}/UCDUtilities.hpp)
list(APPEND src_sources ${CMAKE_CURRENT_SOURCE_DIR}/UCDUtilities.cpp)

list(APPEND src_headers ${CMAKE_CURRENT_SOURCE_DIR}/UCD_test.hpp)
#list(APPEND src_headers ${CMAKE_CURRENT_SOURCE_DIR}/example_unit_test.hpp)

list(APPEND src_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(src_paraview_sources ${src_sources} PARENT_SCOPE)
set(src_paraview_headers ${src_headers} PARENT_SCOPE)
set(src_paraview_includes ${src_includes} PARENT_SCOPE)
