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
#if ECHO_MIXINS
#include <echo/mixin_net_api.h>
#include <echo/mixins/msg_logger.h>
#include <echo/mixins/null_sender.h>
#include <echo/mixins/stdout_logger.h>
#endif
#include <echo/server.h>
#include <algorithm>
#include <exception>
#include <iostream>

namespace {

echo::request_msg make_request(std::int16_t id, size_t payload_size)
{
  static std::int16_t seq_num = 0;
  std::vector<std::byte> data(payload_size);
  std::ranges::generate(data, [i = 0]() mutable { return std::byte(i++); });
  return {id, seq_num++, std::move(data)};
}

#if ECHO_MIXINS

template<typename Base>
class fake_receiver : public Base {
  std::int16_t id_;
  size_t payload_size_;
public:
  template<typename... Args>
  fake_receiver(std::int16_t id, size_t payload_size, Args&&... rest) :
      Base(std::forward<Args>(rest)...), id_(id), payload_size_(payload_size)
  {
  }

  void receive(echo::request_msg& msg) { msg = make_request(id_, payload_size_); }
};

#else

struct fake_api {
  std::int16_t id;
  size_t payload_size;

  void receive(echo::request_msg& msg)
  {
    msg = make_request(id, payload_size);
    std::cout << "Received: " << msg << "\n";
  }
  void send(const echo::reply_msg& msg) { std::cout << "Sent: " << msg << "\n"; }
};

#endif

}  // namespace

namespace echo_cli {

void run(std::int16_t id, size_t count, size_t payload_size)
{
#if ECHO_MIXINS
  std::cout << "Using mixin-based server API\n";
  using server_api = echo::mixin_net_api<echo::msg_logger, echo::stdout_logger, echo::null_sender, fake_receiver>;
  echo::server server(server_api{id, payload_size}, count);
#else
  std::cout << "Using fake server API\n";
  echo::server server(fake_api{id, payload_size}, count);
#endif
  server.run();
}

}  // namespace echo_cli
