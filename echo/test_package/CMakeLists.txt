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
project(test_package)

find_package(echo CONFIG REQUIRED)
message("ECHO_MIXINS: ${ECHO_MIXINS}")

function(add_test_package name)
  add_executable(test_package_${name})
  target_sources(test_package_${name} PRIVATE test_package_${name}.cpp)
  target_link_libraries(test_package_${name} PRIVATE echo::${name})
endfunction()

add_test_package(protocol)
add_test_package(server)

if(ECHO_MIXINS)
  add_test_package(mixins)
endif()
