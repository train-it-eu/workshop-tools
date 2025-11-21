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

list(APPEND CMAKE_MESSAGE_CONTEXT mixins)

# add dependencies
find_package(ciabatta CONFIG REQUIRED)

# build definition
add_library(echo-mixins INTERFACE)
target_sources(echo-mixins PUBLIC
  FILE_SET HEADERS
  BASE_DIRS include
  FILES
    include/echo/mixin_net_api.h
    include/echo/mixins/msg_logger.h
    include/echo/mixins/null_receiver.h
    include/echo/mixins/null_sender.h
    include/echo/mixins/ostream_logger.h
    include/echo/mixins/stdout_logger.h
)
target_compile_features(echo-mixins INTERFACE cxx_std_20)
target_compile_definitions(echo-mixins INTERFACE ECHO_MIXINS=1)
target_link_libraries(echo-mixins INTERFACE ciabatta::ciabatta)
set_target_properties(echo-mixins PROPERTIES EXPORT_NAME mixins)
add_library(echo::mixins ALIAS echo-mixins)

# installation
install(TARGETS echo-mixins EXPORT echo-targets FILE_SET HEADERS)
