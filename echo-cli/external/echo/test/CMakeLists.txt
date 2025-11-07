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

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

function(add_gtest_unit_tests target link_target)
  if(NOT TARGET ${link_target})
    message(FATAL_ERROR "'${link_target}' is not a CMake target")
  endif()

  add_executable(${target})
  target_sources(${target} PRIVATE ${ARGN})
  target_include_directories(${target} PRIVATE ${echo_SOURCE_DIR})
  target_link_libraries(${target} PRIVATE ${link_target} GTest::gtest_main)
  gtest_discover_tests(${target})
endfunction()

add_gtest_unit_tests(echo-protocol-unit-tests echo::protocol
  messages_test.cpp
  messages_io_test.cpp
)

add_gtest_unit_tests(echo-server-unit-tests echo::server
  utils_test.cpp
  server_test.cpp
)
