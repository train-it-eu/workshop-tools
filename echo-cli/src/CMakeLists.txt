# The MIT License (MIT)
#
# Copyright (c) 2020 Train IT
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 4.0)
project(echo-cli
  VERSION 0.1.0
  LANGUAGES CXX
)

# add dependencies
find_package(echo CONFIG REQUIRED GLOBAL)

# Experimental CPS workaround
# TODO Remove when https://gitlab.kitware.com/cmake/cmake/-/issues/27370 is resolved
set_property(TARGET echo::server PROPERTY IMPORTED_GLOBAL TRUE)

# create project configuration
configure_file(echo_cli_config.h.in echo_cli_config.h)

# build definition
add_subdirectory(build_info)

add_executable(echo-cli)
target_sources(echo-cli
  PRIVATE 
    main.cpp
    server.cpp
  PRIVATE
    FILE_SET internal
    TYPE HEADERS
    BASE_DIRS 
      "${CMAKE_CURRENT_SOURCE_DIR}"
      "${PROJECT_BINARY_DIR}"
    FILES
      "${CMAKE_CURRENT_SOURCE_DIR}/server.h"
      "${PROJECT_BINARY_DIR}/echo_cli_config.h"
)
target_compile_features(echo-cli PRIVATE cxx_std_17)
target_link_libraries(echo-cli
  PRIVATE
    echo-cli-build-info
    echo::server
    $<$<TARGET_EXISTS:echo::mixins>:echo::mixins>
)

# installation
include(GNUInstallDirs)
install(TARGETS echo-cli)
