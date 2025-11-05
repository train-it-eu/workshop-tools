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

# protocol
add_library(echo-protocol STATIC)
target_sources(echo-protocol 
  PRIVATE
    src/protocol/messages_io.cpp 
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS src/protocol/include
    FILES
      src/protocol/include/echo/messages.h
      src/protocol/include/echo/messages_io.h
)
target_compile_features(echo-protocol PUBLIC cxx_std_20)
add_library(echo::protocol ALIAS echo-protocol)

# server
add_library(echo-server)
target_sources(echo-server
  PRIVATE
    src/server/server.cpp
    src/server/utils.cpp
  PRIVATE
    FILE_SET internal
    TYPE HEADERS
    BASE_DIRS src/server
    FILES
      src/server/utils.h
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS src/server/include
    FILES
      src/server/include/echo/server.h
)
target_compile_features(echo-server PUBLIC cxx_std_20)
target_link_libraries(echo-server PUBLIC echo::protocol)
add_library(echo::server ALIAS echo-server)
