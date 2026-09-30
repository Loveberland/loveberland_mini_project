CC := g++

CFLAGS := -O3 -Wall -Wextra -Werror

SRC_DIR := src
OUT_DIR := out

TARGET := $(OUT_DIR)/cnb

SRC := $(wildcard $(SRC_DIR)/*.cc)
OBJ := $(patsubst $(SRC_DIR)/%.cc, $(OUT_DIR)/%.o, $(SRC))

.PHONY: all build clean flex

all: build

build: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cc
	mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OUT_DIR)

flex:
	git ls-files | xargs wc -l
