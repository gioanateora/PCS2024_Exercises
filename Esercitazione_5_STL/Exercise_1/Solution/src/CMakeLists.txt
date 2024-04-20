list(APPEND triangularMeshSolution_headers ${CMAKE_CURRENT_SOURCE_DIR}/Utils.hpp)
list(APPEND triangularMeshSolution_sources ${CMAKE_CURRENT_SOURCE_DIR}/Utils.cpp)

list(APPEND triangularMeshSolution_headers ${CMAKE_CURRENT_SOURCE_DIR}/TriangularMesh.hpp)

list(APPEND triangularMeshSolution_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(triangularMeshSolution_sources ${triangularMeshSolution_sources} PARENT_SCOPE)
set(triangularMeshSolution_headers ${triangularMeshSolution_headers} PARENT_SCOPE)
set(triangularMeshSolution_includes ${triangularMeshSolution_includes} PARENT_SCOPE)
