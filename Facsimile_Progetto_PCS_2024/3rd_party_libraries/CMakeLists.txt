cmake_minimum_required(VERSION 3.9)

project(Gedim_3rd_party_libraries LANGUAGES CXX C VERSION 1.0)

# Set C++ Standard
###########################################################################################
set(CMAKE_CXX_STANDARD 17 FORCE)
set(CMAKE_CXX_STANDARD_REQUIRED ON FORCE)

# Create variables
################################################################################
set(MAIN_SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/Main_Source CACHE PATH "Main Source Directory")
set(MAIN_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/Main_Build CACHE PATH "Main Build Directory")
set(MAIN_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/Main_Install CACHE PATH "Main Install Directory")

option(INSTALL_EIGEN3 "Install Eigen3" ON)
option(INSTALL_GOOGLETEST "Install GoogleTest" ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel" FORCE)
endif()

# Add dependencies
################################################################################
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

## Eigen3
if(INSTALL_EIGEN3)
	include(InstallEigen3)
endif()

## GoogleTest
if(INSTALL_GOOGLETEST)
	include(InstallGTest)
endif()
