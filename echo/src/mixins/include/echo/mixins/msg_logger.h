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

#include <ciabatta/ciabatta.hpp>

namespace echo {

template<typename Base>
class msg_logger : public Base {
  Base& base() { return *static_cast<Base*>(this); }

public:
  CIABATTA_DEFAULT_MIXIN_CTOR(msg_logger, Base);
  void receive(auto& msg)
  {
    base().receive(msg);
    this->self().log("Received: ", msg);
  }
  void send(const auto& msg)
  {
    base().send(msg);
    this->self().log("Sent: ", msg);
  }
};

}  // namespace echo
