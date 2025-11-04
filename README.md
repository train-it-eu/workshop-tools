# [Modern C++ Toolset](https://train-it.eu/trainings/cpp/75-cmake-conan) Workshop

This repository contains hands-on exercises for learning modern C++ development tools
including CMake and Conan.


## 📚 Workshop Structure

This workshop covers:
- CMake fundamentals and best practices
- Conan dependency management
- Modern C++ project structure
- Testing with Google Test


## 🚀 Quick Start

The preferred way to run this workshop is to use GitHub Codespaces by clicking the button below:

[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/train-it-eu/workshop-tools)

### Configuration
When creating a codespace, select:
- **Branch**: `task_1`
- **Machine type**: 2-core (recommended minimum)

### Alternative Setup Methods

1. **Via GitHub Web Interface**:
   - Navigate to the repository → **"Code"** → **"Codespaces"** → **"Create codespace on master"**

2. **Via VS Code Extension**:
   - Install the [GitHub Codespaces extension](https://marketplace.visualstudio.com/items?itemName=GitHub.codespaces)
   - Create codespace directly from VS Code

3. **Local Development**:
   - Use the pre-configured devcontainer and Docker image manually in your IDE
   - Requires Docker and VS Code with Remote-Containers extension
   - Benefits
      - **Full offline development** (after initial setup)
      - **Better performance** on powerful local machines
      - **Direct file system access** for easier integration with local tools
      - **No usage limits** unlike GitHub Codespaces

### Contents

The workspace comes pre-configured with:
- Modern C++ compilers (GCC, Clang)
- CMake build system
- Code formatting tools (clang-format)
- Initial code for our exercises


## 🔧 First Steps

### CMake Configuration

1. **Important**: Do not select any 3rd party `CMakeLists.txt` files. We will create our own
   during the first exercise of our workshop! 
2. In VS Code, select a CMake Kit for the latest compiler of your choice:
   - Open Command Palette (`Ctrl+Shift+P`)
   - Run "CMake: Select a Kit"
   - Choose your preferred compiler (e.g., GCC, Clang)


## 👥 Collaborative Development

During the workshop, you'll collaborate with other participants by sharing your IDE workspace.

### How to Share Your Workspace
1. Click the **"Live Share"** button in the VS Code status bar (bottom of the window)
2. VS Code will generate an invitation link
3. Share this link with your team members
4. Participants can join and see your code in real-time

### Live Share Features
- Real-time collaborative editing
- Shared terminal sessions
- Voice/text chat integration
- Shared debugging sessions


## 💾 Persistent Storage

**Important**: Understanding where to store your files is crucial for data persistence across
devcontainer sessions.

### Persistent Directories

Your codespace has two main persistent directories:

1. **Repository Directory**: `/workspaces/workshop-tools`
   - This is the current repository location
   - All files here are automatically saved and versioned with git
   - Perfect for code changes and build artifacts

2. **Persistent Directory**: `/workspaces/persistent` 
   - Available via environment variable: `$PERSISTENT_DIR`
   - Use for files that need to persist but aren't part of the repository
   - Examples: dependencies, pip packages, conan configuration, temporary files, additional tools

⚠️ **Warning**: Files stored outside these directories may be lost when the container is recreated or reset.


## ⏹️ Managing Your Codespace

**Important**: Remember to stop your codespace when not in use to conserve your free GitHub Codespaces hours.

### How to Stop Your Codespace

**Method 1 - Command Palette**:
1. Press `Ctrl+Shift+P` (or `Cmd+Shift+P` on Mac)
2. Type "Codespaces: Stop Current Codespace"
3. Press Enter

**Method 2 - Status Bar**:
1. Click the remote indicator in the bottom-left corner of VS Code
2. Select "Stop Current Codespace" from the menu

**Method 3 - GitHub Web Interface**:

*Option A - From Repository*:
1. Go to your repository page: [github.com/train-it-eu/workshop-tools](https://github.com/train-it-eu/workshop-tools)
2. Click the **"Code"** button (green button)
3. Switch to the **"Codespaces"** tab
4. Find your active codespace and click the three dots (⋯) menu
5. Select "Stop codespace" from the dropdown menu

*Option B - From Codespaces Dashboard*:
1. Navigate to [github.com/codespaces](https://github.com/codespaces)
2. Find your active codespace in the list
3. Click the three dots (⋯) menu next to your codespace
4. Select "Stop codespace" from the dropdown menu
5. Confirm the action when prompted

### Codespace Management Tips

- Codespaces automatically suspend after 30 minutes of inactivity (default)
- You can resume a stopped codespace anytime from GitHub
- Your work is automatically saved and persisted
- Free tier includes 120 core hours per month (e.g., 60 hours for 2-core machine)


## 🆘 Troubleshooting

If you encounter issues:
1. Try refreshing the codespace browser tab
2. Restart the codespace from the GitHub Codespaces dashboard
3. Check that you're using the correct branch (`task_1`)
4. Ensure your codespace has sufficient resources (2-core minimum)


## 📖 Additional Resources

- [Train-IT Modern C++ Course](https://train-it.eu/trainings/cpp/75-cmake-conan)
- [GitHub Codespaces Documentation](https://docs.github.com/en/codespaces)
- [CMake Documentation](https://cmake.org/documentation/)
- [Conan Documentation](https://docs.conan.io/en/latest/)
