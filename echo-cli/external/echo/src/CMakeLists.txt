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
project(echo
  VERSION 0.1.0
  LANGUAGES CXX
)

# project options
option(ECHO_MIXINS "Enables Mixins support")

# build definition
include(GNUInstallDirs)
add_subdirectory(protocol)
add_subdirectory(server)

if(ECHO_MIXINS)
  message("Mixins support enabled")
  add_subdirectory(mixins)
else()
  message("Mixins support disabled")
endif()

# installation
configure_file(echo-config.cmake.in echo-config.cmake @ONLY)
include(CMakePackageConfigHelpers)
write_basic_package_version_file(echo-config-version.cmake COMPATIBILITY SameMajorVersion)
install(
  FILES 
    ${CMAKE_CURRENT_BINARY_DIR}/echo-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/echo-config-version.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/echo
)
install(EXPORT echo-targets
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/echo
  NAMESPACE echo::
)
