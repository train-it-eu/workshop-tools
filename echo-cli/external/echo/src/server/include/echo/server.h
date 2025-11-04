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

#pragma once

#include <echo/messages.h>
#include <concepts>
#include <optional>

namespace echo {

template<typename T>
concept server_api = requires(T&& t, request_msg rx, reply_msg tx) {
  std::forward<T>(t).receive(rx);
  std::forward<T>(t).send(tx);
};

class server_base {
public:
  reply_msg make_replay(const request_msg& req) const;
};

template<server_api NetApi>
class server : public server_base {
  NetApi api_;
  std::optional<size_t> message_count_;  // empty means an infinite loop
public:
  explicit server(NetApi&& api, std::optional<size_t> message_count = std::nullopt) :
      api_(std::move(api)), message_count_(message_count)
  {
  }
  NetApi& api() { return api_; }
  const NetApi& api() const { return api_; }
  void run()
  {
    size_t i = 0;
    while (true) {
      request_msg req;
      api_.receive(req);
      api_.send(make_replay(req));
      if (message_count_ && ++i == *message_count_) break;
    }
  }
};

}  // namespace echo
