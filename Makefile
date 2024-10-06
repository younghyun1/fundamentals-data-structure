.PHONY: build run clean

# Compiler and flags
CC := gcc
CFLAGS := -O3 -march=raptorlake -flto

# Directories
SRC_DIR := src
BIN_DIR := bin

# Find all .c files under the source directory
SRC_FILES := $(shell find $(SRC_DIR) -type f -name '*.c')
# Convert source files to their corresponding binary names in the bin directory
BINARIES := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SRC_FILES))

# Build all binaries
build: $(BINARIES)

# Pattern rule to build each binary
$(BIN_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $<

# Run all binaries
run: build
	@for bin in $(BINARIES); do \
		echo "Running $$bin"; \
		./$$bin; \
	done

# Clean up binaries
clean:
	rm -rf $(BIN_DIR)
