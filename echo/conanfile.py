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

from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.build import can_run, check_min_cppstd


class EchoConan(ConanFile):
    settings = "os", "arch", "compiler", "build_type"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    no_copy_source = True

    @property
    def _build_all(self):
        return bool(self.conf.get("user.workshop.build:all", default=False))

    def build_requirements(self):
        if self._build_all:
            self.test_requires("gtest/1.10.0")

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def validate(self):
        check_min_cppstd(self, "20")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.cache_variables["CMAKE_MESSAGE_CONTEXT_SHOW"] = True
        tc.cache_variables["CMAKE_VERIFY_INTERFACE_HEADER_SETS"] = self._build_all
        tc.cache_variables["CMAKE_EXPERIMENTAL_EXPORT_PACKAGE_INFO"] = (
            "b80be207-778e-46ba-8080-b23bba22639e"
        )
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure(build_script_folder=None if self._build_all else "src")
        cmake.build()
        if self._build_all:
            cmake.build(target="all_verify_interface_header_sets")
            if can_run(self):
                cmake.ctest(cli_args=["--output-on-failure"])
