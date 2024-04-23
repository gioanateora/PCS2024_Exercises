list(APPEND sorting_headers ${CMAKE_CURRENT_SOURCE_DIR}/SortingAlgorithm.hpp)

list(APPEND sorting_includes ${CMAKE_CURRENT_SOURCE_DIR})

set(sorting_sources ${sorting_sources} PARENT_SCOPE)
set(sorting_headers ${sorting_headers} PARENT_SCOPE)
set(sorting_includes ${sorting_includes} PARENT_SCOPE)
