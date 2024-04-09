list(APPEND dotProduct_headers ${CMAKE_CURRENT_SOURCE_DIR}/Utils.hpp)
list(APPEND dotProduct_sources ${CMAKE_CURRENT_SOURCE_DIR}/Utils.cpp)

list(APPEND dotProduct_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(dotProduct_sources ${dotProduct_sources} PARENT_SCOPE)
set(dotProduct_headers ${dotProduct_headers} PARENT_SCOPE)
set(dotProduct_includes ${dotProduct_includes} PARENT_SCOPE)
