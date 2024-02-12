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
from conan.tools.files import get, copy
from conan.tools.scm import Version


class CiabattaConan(ConanFile):
    name = "ciabatta"
    version = "4.0.0"
    license = "Apache-2.0 License"
    author = "Gašper Ažman <gasper.azman@gmail.com>"
    description = "The C++ Mixin Support Library: Sandwich Mixins all the way"
    package_type = "header-library"
    no_copy_source = True

    def source(self):
        zip_name = "version-%s.zip" % Version(self.version).major
        get(
            self,
            "https://github.com/atomgalaxy/libciabatta/archive/refs/tags/%s" % zip_name,
            sha256="c15944f83199398505373da21200ce8d2d4ead6d28f71019436159ab5b82844d",
            strip_root=True,
        )

    def package(self):
        copy(self, "*.hpp", self.source_folder, self.package_folder)
