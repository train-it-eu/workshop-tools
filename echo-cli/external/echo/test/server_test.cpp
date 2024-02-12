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

#include <echo/server.h>
#include <gtest/gtest.h>
#include <algorithm>
#include <exception>

namespace {

echo::request_msg make_request(std::int16_t id, size_t payload_size)
{
  static std::int16_t seq_num = 0;
  std::vector<std::byte> data(payload_size);
  std::ranges::generate(data, [i = 0]() mutable { return std::byte(i++); });
  return {id, seq_num++, std::move(data)};
}

class test_api {
  std::int16_t id_;
  size_t payload_size_;
  echo::request_msg last_msg_;
  bool status_ = true;
  int count_ = 0;
public:
  explicit test_api(std::int16_t id, size_t payload_size) : id_(id), payload_size_(payload_size) {}

  void receive(echo::request_msg& msg) { msg = last_msg_ = make_request(id_, payload_size_); }

  void send(const echo::reply_msg& msg)
  {
    status_ = status_ && (last_msg_ == msg);
    ++count_;
  }

  bool status() const { return status_; }
  int count() const { return count_; }
};

}  // namespace

TEST(Server, MessageCount)
{
  const int count = 3;
  echo::server server(test_api(123, 256), count);
  server.run();

  EXPECT_EQ(count, server.api().count());
}

TEST(Server, MessageContent)
{
  echo::server server(test_api(123, 256), 1);
  server.run();

  EXPECT_TRUE(server.api().status());
}
