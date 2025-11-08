cmake_minimum_required(VERSION 2.6...3.10)

add_subdirectory(FCollada)

set(DEST_DIR "${CMAKE_INSTALL_PREFIX}")
configure_file("fcollada.pc.in" "fcollada.pc" @ONLY)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/fcollada.pc" DESTINATION lib/pkgconfig)
