# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -Iinclude -g

# Directories
SRC_DIR = src
BUILD_DIR = build/debug

# Default target
all:
	@echo "Specify a target program with: make PROGRAM=<program_name> compile"

# Compile the specified program
compile:
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/$(PROGRAM).cpp -o $(BUILD_DIR)/$(PROGRAM).exe

# Clean build files
clean:
	@if exist "$(BUILD_DIR)" rmdir /s /q "$(BUILD_DIR)"
