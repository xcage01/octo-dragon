cmake_minimum_required (VERSION 2.6)
project (octo-dragon)
add_executable(dragon src/dragon.cc)
target_link_libraries( dragon microhttpd )