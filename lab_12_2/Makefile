.PHONY: clean debug cleano func key
.NOTPARALLEL: debug func

CC = gcc
CFLAGS := -std=c99 -Wall -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
UFLAGS := -lcheck
DFLAGS :=

ifeq ($(shell hostname), Violet)
	UFLAGS += -lm -lsubunit
endif

ifeq ($(shell uname), Linux)
	UFLAGS += -lpthread -lrt
endif

INC_DIR = ./inc
OBJ_DIR = ./out
SRC_DIR = ./src
MAIN :=
OMAIN := $(MAIN:.c=.o)
FUNCS := funcs.c
OFUNCS := $(FUNCS:.c=.o)


SRCS := $(addprefix $(SRC_DIR)/,$(MAIN) $(FUNCS))
OBJS := $(addprefix $(OBJ_DIR)/,$(OMAIN) $(OFUNCS))

#linklib
link: $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -fPIC -c $(SRC_DIR)/funcs.c -o $(OBJ_DIR)/funcs.o
	$(CC) -I$(INC_DIR) -o $(OBJ_DIR)/libfuncs.so -shared $(OBJ_DIR)/funcs.o

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -I$(INC_DIR) -c $< -o $@

unit: cleano
unit: $(EXEC_UNIT)

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -f -r $(OBJ_DIR) *.exe *.gcov ./func_tests/scripts/*.txt *.a

cleano:
	rm -f -r $(OBJ_DIR)

include $(wildcard $(addsuffix /*.d, $(OBJ_DIR)))
