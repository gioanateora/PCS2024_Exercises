list(APPEND classRationalSolution_headers ${CMAKE_CURRENT_SOURCE_DIR}/Rational.hpp)
list(APPEND classRationalSolution_sources ${CMAKE_CURRENT_SOURCE_DIR}/Rational.cpp)

list(APPEND classRationalSolution_headers ${CMAKE_CURRENT_SOURCE_DIR}/Utils.hpp)
list(APPEND classRationalSolution_sources ${CMAKE_CURRENT_SOURCE_DIR}/Utils.cpp)

list(APPEND classRationalSolution_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(classRationalSolution_sources ${classRationalSolution_sources} PARENT_SCOPE)
set(classRationalSolution_headers ${classRationalSolution_headers} PARENT_SCOPE)
set(classRationalSolution_includes ${classRationalSolution_includes} PARENT_SCOPE)
