cmake_minimum_required(VERSION 3.25)
project(maria_test)

set(CMAKE_CXX_STANDARD 23)
set(ENV{PKG_CONFIG_PATH}
    "/opt/homebrew/opt/mariadb-connector-c/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}"
)

find_package(PkgConfig REQUIRED)

if(APPLE)
    # On macOS: brew install mariadb-connector-c
    pkg_check_modules(MARIADB REQUIRED libmariadb)
else()
    pkg_check_modules(MARIADB REQUIRED mariadb)
endif()


add_executable(maria_test main.cpp)
target_link_libraries(maria_test ${MARIADB_LIBRARIES})
target_link_directories(maria_test PRIVATE ${MARIADB_LIBRARY_DIRS})
target_include_directories(maria_test PRIVATE ${MARIADB_INCLUDE_DIRS})
target_compile_options(maria_test PRIVATE ${MARIADB_CFLAGS_OTHER})
