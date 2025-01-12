# Cpp_Exercises

## Overview
This repository contains a collection of **C++ exercises and projects** that I am working on to practice and improve my **C++ programming skills**. It includes examples of foundational concepts, algorithms, and small projects for hands-on learning. This repository documents my progress and serves as a public record of my journey with C++.

---

## Features
- Exercises and projects covering:
  - Variables, data types, and control structures.
  - Object-Oriented Programming (OOP).
  - Algorithms and data structures.
  - File I/O operations.
- Organized folder structure for easy navigation.
- Support for building with both `CMake` and `Make`.

---

## Project Structure
```
Cpp_Exercises/
├── build/                # Build artifacts (debug/release).
├── include/              # Header files for the exercises.
├── src/                  # Source code files.
│   └── main.cpp          # Entry point for the current exercise/project.
├── .gitignore            # Files/directories ignored by Git.
├── CMakeLists.txt        # CMake build configuration.
├── Makefile              # Makefile for building the project.
├── README.md             # This file.
```

---

## Requirements
To work with this repository, you will need:
- **C++ Compiler**: `g++`, `clang++`, or MSVC.
- **CMake**: For cross-platform builds.
- **Make**: (Optional) For using the Makefile.
- **Git**: For version control.

---

## Build and Run Instructions

### Using `make`
1. Clone the repository:
   ```bash
   git clone https://github.com/sergiogallegos/Cpp_Exercises.git
   cd Cpp_Exercises
   ```
2. Build the project:
   - For **debug**:
     ```bash
     make
     ```
   - For **release**:
     ```bash
     make BUILD_MODE=release
     ```
3. Run the program:
   ```bash
   ./build/debug/main.exe   # For debug mode
   ./build/release/main.exe # For release mode
   ```
4. Clean up:
   ```bash
   make clean
   ```

### Using `CMake`
1. Create a build directory:
   ```bash
   cmake -S . -B build -G "Your Generator"
   cmake --build build
   ```
2. Run the program:
   ```bash
   ./build/main
   ```

---

## Contributions
This repository is for personal learning purposes, but contributions are welcome! If you’d like to suggest improvements or share ideas, feel free to:
- Fork this repository.
- Open a pull request.
- Submit issues for bugs or enhancements.

---

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

```
MIT License

Copyright (c) 2025 [Sergio Gallegos]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
...
```

---

## Acknowledgments
- Inspired by **Programming: Principles and Practice Using C++** by Bjarne Stroustrup.
- Leveraging resources like online tutorials, forums, and open-source documentation.