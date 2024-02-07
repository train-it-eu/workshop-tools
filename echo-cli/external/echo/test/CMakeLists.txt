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

function(validate_unparsed target prefix)
  if(${prefix}_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "Invalid arguments '${${prefix}_UNPARSED_ARGUMENTS}' for target '${target}'")
  endif()
endfunction()

function(validate_argument_exists target prefix arg)
  if(NOT ${prefix}_${arg})
    message(FATAL_ERROR "'${arg}' not provided for target '${target}'")
  endif()
endfunction()

function(validate_arguments_exists target prefix)
  foreach(arg ${ARGN})
    validate_argument_exists(${target} ${prefix} ${arg})
  endforeach()
endfunction()

#
# add_gtest_unit_tests(TargetName [EXCLUDE_FROM_ALL]
#                      LIBRARIES <lib>...
#                      SOURCES <item>...)
#
function(add_gtest_unit_tests target)
  # parse arguments
  set(options EXCLUDE_FROM_ALL)
  set(oneValueArgs)
  set(multiValueArgs LIBRARIES SOURCES)
  cmake_parse_arguments(PARSE_ARGV 1 add_gtest_unit_tests "${options}" "${oneValueArgs}" "${multiValueArgs}")

  # validate and process arguments
  validate_unparsed(${target} add_gtest_unit_tests)
  validate_arguments_exists(${target} add_gtest_unit_tests LIBRARIES SOURCES)
  if(add_gtest_unit_tests_EXCLUDE_FROM_ALL)
    set(exclude_from_all EXCLUDE_FROM_ALL)
  endif()

  # define tests
  add_executable(${target} ${exclude_from_all})
  target_sources(${target} PRIVATE ${add_gtest_unit_tests_SOURCES})
  target_include_directories(${target} PRIVATE ${echo_SOURCE_DIR})
  target_link_libraries(${target} PRIVATE ${add_gtest_unit_tests_LIBRARIES} GTest::gtest_main)
  gtest_discover_tests(${target})
endfunction()

add_gtest_unit_tests(echo-protocol-unit-tests
  LIBRARIES echo::protocol
  SOURCES
    messages_test.cpp
    messages_io_test.cpp
)

add_gtest_unit_tests(echo-server-unit-tests
  LIBRARIES echo::server
  SOURCES
    utils_test.cpp
    server_test.cpp
)
