cmake_minimum_required(VERSION 3.5)

project( LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# The Project name
set (APPL_NAME "ParkingLot")

# The version number
set (VERSION_MAJOR 0)
set (VERSION_MINOR 0)

# Add Defenitions
add_definitions(-DVERSION_MAJOR=${VERSION_MAJOR})
add_definitions(-DVERSION_MINOR=${VERSION_MINOR})

# Set global application vars
set(APPL_BUILD_DIR "${APPL_BASE_DIR}/build")
set(APPL_SOURCE_DIR "${APPL_BASE_DIR}/src")

# External libruaries
set(EXTERNAL_LIBRUARY_DIR "${APPL_BASE_DIR}/../ext")

# Options
set(COMMON_COMPILE_OPTION "-Wall")
