cmake_minimum_required(VERSION 3.25)
project(maria_test)

set(CMAKE_CXX_STANDARD 23)

find_package(PkgConfig REQUIRED)
pkg_check_modules(MARIADB REQUIRED mariadb)

add_executable(maria_test main.cpp)
target_link_libraries(maria_test ${MARIADB_LIBRARIES})
target_include_directories(maria_test PRIVATE ${MARIADB_INCLUDE_DIRS})
target_compile_options(maria_test PRIVATE ${MARIADB_CFLAGS_OTHER})
