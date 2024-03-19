cmake_minimum_required(VERSION 3.9)

project(linearSystem1 LANGUAGES CXX C VERSION 1.0.0)

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
list(APPEND linearSystem1_LINKED_LIBRARIES PUBLIC Eigen3::Eigen)

## Threads
find_package(Threads REQUIRED)
list(APPEND linearSystem1_LINKED_LIBRARIES PRIVATE Threads::Threads)

## GTest
find_package(GTest REQUIRED)

list(APPEND linearSystem1_LINKED_LIBRARIES PRIVATE GTest::gtest)
list(APPEND linearSystem1_LINKED_LIBRARIES PRIVATE GTest::gtest_main)
list(APPEND linearSystem1_LINKED_LIBRARIES PRIVATE GTest::gmock)
list(APPEND linearSystem1_LINKED_LIBRARIES PRIVATE GTest::gmock_main)

# Insert Sources
################################################################################

list(APPEND linearSystem1_SOURCES ${linearSystem1_sources})
list(APPEND linearSystem1_HEADERS ${linearSystem1_headers})
list(APPEND linearSystem1_INCLUDE ${linearSystem1_includes})

# Create executable
################################################################################
add_executable(${PROJECT_NAME}
	main.cpp
	${linearSystem1_SOURCES}
    ${linearSystem1_HEADERS})


add_executable(RIPASSO
	main_ripasso.cpp
	${linearSystem1_SOURCES}
    ${linearSystem1_HEADERS})

target_link_libraries(${PROJECT_NAME} ${linearSystem1_LINKED_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${linearSystem1_INCLUDE})
target_compile_options(${PROJECT_NAME} PUBLIC -fPIC)

target_link_libraries(RIPASSO ${linearSystem1_LINKED_LIBRARIES})
target_include_directories(RIPASSO PRIVATE ${linearSystem1_INCLUDE})
target_compile_options(RIPASSO PUBLIC -fPIC)
