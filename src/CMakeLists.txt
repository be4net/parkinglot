cmake_minimum_required(VERSION 3.11)

# Include project cmake script
include ("./Config.cmake")

configure_file ("${APPL_SOURCE_DIR}/Config.h.in", "${APPL_SOURCE_DIR}/Config.h")

include_directories("${APPL_SOURCE_DIR}")

add_subdirectory("ut")
