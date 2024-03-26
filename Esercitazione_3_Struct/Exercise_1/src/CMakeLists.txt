list(APPEND classRational_headers ${CMAKE_CURRENT_SOURCE_DIR}/Rational.hpp)
list(APPEND classRational_sources ${CMAKE_CURRENT_SOURCE_DIR}/Rational.cpp)

list(APPEND classRational_headers ${CMAKE_CURRENT_SOURCE_DIR}/Utils.hpp)
list(APPEND classRational_sources ${CMAKE_CURRENT_SOURCE_DIR}/Utils.cpp)

list(APPEND classRational_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(classRational_sources ${classRational_sources} PARENT_SCOPE)
set(classRational_headers ${classRational_headers} PARENT_SCOPE)
set(classRational_includes ${classRational_includes} PARENT_SCOPE)
