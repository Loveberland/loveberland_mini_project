CXX := g++

CPPFLAGS := -Isrc
CXXFLAGS := -Wall -Wextra -Werror -std=c++17

OUT_DIR := out

TARGET := convert
TEST_TARGET := $(OUT_DIR)/t_convert

OBJS := \
        $(OUT_DIR)/main.o \
        $(OUT_DIR)/convert.o

TEST_OBJS := \
             $(OUT_DIR)/t_convert.o \
             $(OUT_DIR)/convert.o

.PHONY: all run test clean flex

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OUT_DIR)/main.o: src/main.cc src/convert.hh | $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(OUT_DIR)/convert.o: src/convert.cc src/convert.hh | $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(OUT_DIR)/t_convert.o: test/t_convert.cc src/convert.hh | $(OUT_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -o $@

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -rf $(OUT_DIR)
	rm -rf $(TARGET)

flex:
	git ls-files | xargs wc -l
