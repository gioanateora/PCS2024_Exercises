list(APPEND dotProductSolution_headers ${CMAKE_CURRENT_SOURCE_DIR}/Utils.hpp)
list(APPEND dotProductSolution_sources ${CMAKE_CURRENT_SOURCE_DIR}/Utils.cpp)

list(APPEND dotProductSolution_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(dotProductSolution_sources ${dotProductSolution_sources} PARENT_SCOPE)
set(dotProductSolution_headers ${dotProductSolution_headers} PARENT_SCOPE)
set(dotProductSolution_includes ${dotProductSolution_includes} PARENT_SCOPE)
