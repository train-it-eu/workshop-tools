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
#include <gtest/gtest.h>
#include <sstream>

TEST(MessagesIO, Request)
{
  auto req = echo::request_msg{123, 1, echo::request_msg::payload(32)};
  std::stringstream ss;
  ss << req;
  EXPECT_EQ("echo-request[id: 123; seq_num: 1; data: 32 B]", ss.str());
}

TEST(MessagesIO, Reply)
{
  auto req = echo::reply_msg{234, 2, echo::request_msg::payload(32)};
  std::stringstream ss;
  ss << req;
  EXPECT_EQ("echo-reply[id: 234; seq_num: 2; data: 32 B]", ss.str());
}
