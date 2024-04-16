list(APPEND triangularMesh_headers ${CMAKE_CURRENT_SOURCE_DIR}/Utils.hpp)
list(APPEND triangularMesh_sources ${CMAKE_CURRENT_SOURCE_DIR}/Utils.cpp)

list(APPEND triangularMesh_headers ${CMAKE_CURRENT_SOURCE_DIR}/TriangularMesh.hpp)

list(APPEND triangularMesh_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(triangularMesh_sources ${triangularMesh_sources} PARENT_SCOPE)
set(triangularMesh_headers ${triangularMesh_headers} PARENT_SCOPE)
set(triangularMesh_includes ${triangularMesh_includes} PARENT_SCOPE)
