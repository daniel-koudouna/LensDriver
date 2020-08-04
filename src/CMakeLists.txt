cmake_minimum_required(VERSION 3.14.1)
project(optotune-lensdriver LANGUAGES C CXX)

file(GLOB CMD_FILES ${CMAKE_CURRENT_SOURCE_DIR}/cmd_*)

add_library(lensdriver-lib SHARED
  clear_recv_buffer.c
  ${CMD_FILES}
  config_serial.c
  crc.c
  dev_open_setup.c
  lensdriver.h
  parse_answer.c
  print_buffer.c
  read_device.c
  safe_exit.c
  show_config.c
  uint8ncmp.c
  usage.c
  write_device.c)

target_include_directories(lensdriver-lib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(lensdriver-lib m)

add_executable(lensdriver
  lensdriver.h
  main.c)

target_link_libraries(lensdriver lensdriver-lib)
