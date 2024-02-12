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
#include <echo/mixin_net_api.h>
#include <echo/mixins/msg_logger.h>
#include <echo/mixins/null_sender.h>
#include <echo/mixins/ostream_logger.h>
#include <echo/mixins/stdout_logger.h>
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

template<typename Base>
class fake_receiver : public Base {
  std::int16_t id_;
  size_t payload_size_;

public:
  template<typename... Rest>
  explicit constexpr fake_receiver(std::int16_t id, size_t payload_size, Rest&&... rest) :
      Base(std::forward<Rest>(rest)...), id_(id), payload_size_(payload_size)
  {
  }
  constexpr void receive(echo::request_msg& msg) { msg = make_request(id_, payload_size_); }
};

void run()
{
  using net_api = echo::mixin_net_api<echo::msg_logger, echo::ostream_logger, echo::null_sender, fake_receiver>;
  echo::server server(net_api(std::cerr, std::int16_t(123), 256u), 3);
  server.run();
}

}  // namespace

int main()
{
  try {
    std::cout << "Server Example:\n";
    std::cout << "---------------\n";
    run();
  } catch (const std::exception& ex) {
    std::cerr << "Unhandled std exception caught: " << ex.what() << '\n';
  } catch (...) {
    std::cerr << "Unhandled unknown exception caught\n";
  }
}
