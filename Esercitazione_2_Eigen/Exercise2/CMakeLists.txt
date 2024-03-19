cmake_minimum_required(VERSION 3.9)

project(linearSystem2 LANGUAGES CXX C VERSION 1.0.0)

# Set C++ Standard
################################################################################
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# IMPOSE WARNINGS ON DEBUG
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic-errors")

# IMPOSE CXX FLAGS FOR WINDOWS
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
endif (WIN32)

# Add dependencies
################################################################################
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../../externals/Main_Install/eigen3)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../../externals/Main_Install/googletest)

## Eigen3
find_package(Eigen3 CONFIG REQUIRED)
list(APPEND linearSystem2_LINKED_LIBRARIES PUBLIC Eigen3::Eigen)

## Threads
find_package(Threads REQUIRED)
list(APPEND linearSystem2_LINKED_LIBRARIES PRIVATE Threads::Threads)

## GTest
find_package(GTest REQUIRED)

list(APPEND linearSystem2_LINKED_LIBRARIES PRIVATE GTest::gtest)
list(APPEND linearSystem2_LINKED_LIBRARIES PRIVATE GTest::gtest_main)
list(APPEND linearSystem2_LINKED_LIBRARIES PRIVATE GTest::gmock)
list(APPEND linearSystem2_LINKED_LIBRARIES PRIVATE GTest::gmock_main)

# Insert Sources
################################################################################

list(APPEND linearSystem2_SOURCES ${linearSystem2_sources})
list(APPEND linearSystem2_HEADERS ${linearSystem2_headers})
list(APPEND linearSystem2_INCLUDE ${linearSystem2_includes})

# Create executable
################################################################################
add_executable(${PROJECT_NAME}
	main.cpp
	${linearSystem2_SOURCES}
    ${linearSystem2_HEADERS})

target_link_libraries(${PROJECT_NAME} ${linearSystem2_LINKED_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${linearSystem2_INCLUDE})
target_compile_options(${PROJECT_NAME} PUBLIC -fPIC)
