cmake_minimum_required(VERSION 2.6)
project(FCollada)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, defaulting to Debug")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

option(BUILD_SHARED_LIBS "Build FCollada as a shared library." OFF)
option(BUILD_UNICODE "Build FCollada in wide-character mode." OFF)
option(BUILD_TESTS "Build the test suite." OFF)

add_subdirectory(FCollada)

set(DEST_DIR "${CMAKE_INSTALL_PREFIX}")
CONFIGURE_FILE("fcollada.pc.in" "fcollada.pc" @ONLY)

install(FILES fcollada.pc DESTINATION lib/pkgconfig)
