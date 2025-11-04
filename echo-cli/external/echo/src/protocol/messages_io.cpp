// The MIT License (MIT)
//
// Copyright (c) 2020 Train IT
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <echo/messages_io.h>
#include <iostream>

namespace {

std::ostream& to_stream(std::ostream& os, const echo::message_base& msg)
{
  return os << "id: " << msg.id << "; seq_num: " << msg.seq_num << "; data: " << msg.data.size() << " B";
}

}  // namespace

namespace echo {

std::ostream& operator<<(std::ostream& os, const request_msg& data)
{
  os << "echo-request[";
  return to_stream(os, data) << "]";
}

std::ostream& operator<<(std::ostream& os, const reply_msg& data)
{
  os << "echo-reply[";
  return to_stream(os, data) << "]";
}

}  // namespace echo
