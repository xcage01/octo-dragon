cmake_minimum_required (VERSION 3.0)
add_definitions(-std=c++11)
project (octo-dragon)

include_directories(src/logger)
include_directories(src/dragon)
include_directories(src/server)

add_library( dragon src/dragon/dragon.cc )
add_library( server src/server/server.cc )

add_executable(app src/app.cc)

target_link_libraries( server microhttpd )
target_link_libraries( dragon server )
target_link_libraries( app dragon )