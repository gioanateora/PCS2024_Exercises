cmake_minimum_required(VERSION 3.9)

project(classRationalSolution LANGUAGES CXX C VERSION 1.0.0)

# Set C++ Standard
################################################################################
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# IMPOSE WARNINGS ON DEBUG
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic-errors")

# IMPOSE CXX FLAGS FOR WINDOWS
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
endif (WIN32)

# Add dependencies
################################################################################
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../../../externals/Main_Install/eigen3)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../../../externals/Main_Install/googletest)

## Eigen3
find_package(Eigen3 CONFIG REQUIRED)
list(APPEND classRationalSolution_LINKED_LIBRARIES PUBLIC Eigen3::Eigen)

## Threads
find_package(Threads REQUIRED)
list(APPEND classRationalSolution_LINKED_LIBRARIES PRIVATE Threads::Threads)

## GTest
find_package(GTest REQUIRED)

list(APPEND classRationalSolution_LINKED_LIBRARIES PRIVATE GTest::gtest)
list(APPEND classRationalSolution_LINKED_LIBRARIES PRIVATE GTest::gtest_main)
list(APPEND classRationalSolution_LINKED_LIBRARIES PRIVATE GTest::gmock)
list(APPEND classRationalSolution_LINKED_LIBRARIES PRIVATE GTest::gmock_main)

# Insert Sources
################################################################################
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

list(APPEND classRationalSolution_SOURCES ${classRationalSolution_sources})
list(APPEND classRationalSolution_HEADERS ${classRationalSolution_headers})
list(APPEND classRationalSolution_INCLUDE ${classRationalSolution_includes})

# Create executable
################################################################################
add_executable(${PROJECT_NAME}
    main.cpp
    ${classRationalSolution_SOURCES}
    ${classRationalSolution_HEADERS})

target_link_libraries(${PROJECT_NAME} ${classRationalSolution_LINKED_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${classRationalSolution_INCLUDE})
target_compile_options(${PROJECT_NAME} PUBLIC -fPIC)
