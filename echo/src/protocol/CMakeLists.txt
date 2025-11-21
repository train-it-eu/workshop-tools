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

list(APPEND CMAKE_MESSAGE_CONTEXT protocol)

# build definition
add_library(echo-protocol STATIC)
target_sources(echo-protocol 
  PRIVATE
    messages_io.cpp 
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      include/echo/messages.h
      include/echo/messages_io.h
)
target_compile_features(echo-protocol PUBLIC cxx_std_20)
set_target_properties(echo-protocol PROPERTIES EXPORT_NAME protocol)
add_library(echo::protocol ALIAS echo-protocol)

# installation
install(TARGETS echo-protocol
  EXPORT echo-targets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/$<$<CONFIG:Debug>:debug>
  RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}/$<$<CONFIG:Debug>:debug>
  FILE_SET HEADERS
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
