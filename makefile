# Compiler and flags
CC := clang
CFLAGS := -Wall -Wextra -std=c11 -g
CFLAGS += $(shell pkg-config --cflags raylib)
LDFLAGS := $(shell pkg-config --libs raylib)

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Files
SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))
TARGET := $(BIN_DIR)/xpalette

# Default target
all: $(TARGET) compile_commands.json

# Link the final binary
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile each .c file into a .o file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if they don't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Generate compile_commands.json for clangd
compile_commands.json: $(SOURCES) Makefile
	@echo "[" > $@
	@for src in $(SOURCES); do \
		echo "  {" >> $@; \
		echo "    \"directory\": \"$(CURDIR)\"," >> $@; \
		echo "    \"command\": \"$(CC) $(CFLAGS) -c $$src\"," >> $@; \
		echo "    \"file\": \"$$src\"" >> $@; \
		echo "  }," >> $@; \
	done
	@sed -i '' '$$ s/,$$//' $@
	@echo "]" >> $@

# Run the app
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) compile_commands.json

.PHONY: all run clean
