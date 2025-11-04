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

// #include "build_info/build_info.h"
// #include "echo_cli_config.h"
// #include "server.h"
// #include <filesystem>
#include <iostream>

namespace {

using path = const char*;
// using path = std::filesystem::path;

void usage(const path& p)
{
  std::cout << "Usage: " << p << " COUNT PAYLOAD_SIZE\n";
  // std::cout << "Usage: " << p.filename().string() << " COUNT PAYLOAD_SIZE\n";
  std::cout << "Version: " << 0 << "." << 1 << " (compiled as: ";
#if NDEBUG
  std::cout << "Release";
#else
  std::cout << "Debug";
#endif
  // std::cout << ", linked with: " << fix_parser_cli::get_build_type();
  std::cout << ")\n";
}

}  // namespace

int main(int argc, const char* argv[])
{
  if (argc != 2) usage(argv[0]);
  std::cout << "\n";

  std::size_t count, size;
  std::cout << "Message count:\n";
  std::cin >> count;
  std::cout << "Payload size:\n";
  std::cin >> size;

  std::cout << "\nRunning server with: count = " << count << ", payload_size = " << size << "\n\n";

  // echo_cli::run(123, count, size);
}
