NAME := none-8086emu
CC := cc
SRC_DIR := src
DST_DIR := dst

CCFLAGS := -Wall -Wextra -pedantic -std=c99 -Ofast
LDFLAGS := $(pkg-config --cflags --libs sdl2)

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(DST_DIR)/%.o, $(SRCS))
TARGET := $(DST_DIR)/$(NAME)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(DST_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(DST_DIR)
	$(CC) $(CLFAGS) -c $< -o $@

clean:
	rm -rf $(DST_DIR)/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

debug:
	gdb ./$(TARGET)

leakcheck:
	valgrind --leak-check=full ./$(TARGET)

.PHONY: all clean run
