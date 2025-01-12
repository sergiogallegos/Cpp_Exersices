# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -Iinclude

# Build mode (debug or release)
BUILD_MODE = debug

# Debug and Release-specific flags
DEBUG_FLAGS = -g
RELEASE_FLAGS = -O2

# Build directory based on the build mode
BUILD_DIR = build/$(BUILD_MODE)

# Target executable
TARGET = $(BUILD_DIR)/main.exe

# Source files and object files
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:src/%.cpp=$(BUILD_DIR)/%.o)

# Determine flags based on build mode
ifeq ($(BUILD_MODE), debug)
    CXXFLAGS += $(DEBUG_FLAGS)
else ifeq ($(BUILD_MODE), release)
    CXXFLAGS += $(RELEASE_FLAGS)
endif

# Default rule to build the project
all: $(TARGET)

# Rule to link the final executable
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build artifacts
clean:
	rm -rf build
