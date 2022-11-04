.PHONY: clean debug cleano

CC = gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion

INC_DIR = ./inc
OBJ_DIR = ./out
SRC_DIR = ./src

SRCS := main.c readprint.c funcs.c
OBJS := main.o readprint.o funcs.o

SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

EXEC_APP := app.exe

build : $(EXEC_APP)

$(EXEC_APP): $(OBJ_DIR) | $(OBJS)
	$(CC) $(OBJS) -o $@ -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) *.exe *.gcov out.txt

