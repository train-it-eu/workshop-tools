# [Modern C++ Toolset](https://train-it.eu/trainings/cpp/75-cmake-conan) Workshop
## Development Environment Setup

### Docker

The workshop is intended to run on a [Docker](https://www.docker.com) container based on a provided image. The image
provides gcc, clang, CMake, Ninja, debuggers, clang-format, and more...

To install [Docker](https://www.docker.com) please follow the point #1 of a detailed installation instruction in
[Developing inside a Container](https://code.visualstudio.com/docs/remote/containers#_installation) section of VSCode
documentation.

_Note:_ [WSL 2](https://docs.microsoft.com/en-us/windows/wsl) improves the performance of [Docker](https://www.docker.com)
on Windows. It is also a really powerful tool for daily C++ programming use. If you do not use it currently, please
consider installing it.

### Visual Studio Code

The usage of [Visual Studio Code](https://code.visualstudio.com/download) is strongly suggested for this workshop.
Make sure to enable at least the following extensions:
- [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)

### Alternative Development Environments

You can try to use your own development environment for this workshop but in such a case please make sure that you:
- have a C++20-ready compiler,
- Ninja Build
- the latest CMake version
- Python 3 and `pip`

## Compilation

1. When you open this folder in a VSCode it will ask:

    _Folder contains a Dev Container configuration file. Reopen folder to develop in a container (learn more)._

    - If `Reopen in Container` is available and works correctly than continue with this option.
    - Otherwise
      - choose `Clone in Volume` at first run
      - either provide a clone URL directly (https://github.com/train-it-eu/workshop-tools.git) or choose
        "Clone a repository form GitHub in a Container Volume", and type "train-it-eu/irrlicht-example",
      - choose a volume for the repository (unique, current, other),
      - on the following runs use `Reopen in Container` and choose the one you created for this repo.

2. Wait a moment for the container to initialize.

3. Select CMake Kit for **the latest GCC toolchain** in VSCode.

4. Ignore the message that `CMakeLists.txt` was not found. We will deal with this during the workshop ;-)

## Live Share

During the workshop we will be sharing the IDE with other participants via **Live Share**. Please make sure
that you are able to start a **Live Share** session in the VS Code. To do this you will need to sign in using
GitHub or Microsoft accounts.
