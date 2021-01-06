cmake_minimum_required(VERSION 2.6)

add_subdirectory(FCollada)

set(DEST_DIR "${CMAKE_INSTALL_PREFIX}")
CONFIGURE_FILE("fcollada.pc.in" "fcollada.pc" @ONLY)

install(FILES fcollada.pc DESTINATION lib/pkgconfig)
