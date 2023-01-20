.PHONY: clean debug cleano func key
.NOTPARALLEL: debug func

CC = gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
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
UNIT_DIR = ./unit_tests

MAIN := main.c
OMAIN := $(MAIN:.c=.o)
FUNCS := funcs.c
OFUNCS := $(FUNCS:.c=.o)
UNITS := check_main.c check_funcs.c
OUNITS := $(UNITS:.c=.o)

SRCS := $(addprefix $(SRC_DIR)/,$(MAIN) $(FUNCS))
OBJS := $(addprefix $(OBJ_DIR)/,$(OMAIN) $(OFUNCS))
USRCS := $(addprefix $(UNIT_DIR)/,$(UNITS))
UOBJS := $(addprefix $(OBJ_DIR)/,$(OUNITS))

EXEC_APP := app.exe
EXEC_DEBUG := debug.exe
EXEC_UNIT := unit_tests.exe

$(EXEC_APP): $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) $(DFLAGS) -o $@

key:
	CFLAGS += -DDEBUG
	cleano
	$(EXEC_DEBUG)

debug:
	CFLAGS += -g3 --coverage
	cleano
	DFLAGS += --coverage
	$(EXEC_APP)

#statlib
static: $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/funcs.c -o $(OBJ_DIR)/funcs.o
	ar cr $(OBJ_DIR)/libfuncs.a $(OBJ_DIR)/funcs.o
	ranlib $(OBJ_DIR)/libfuncs.a
	$(CC) $(CFLAGS) -I$(INC_DIR) $(SRC_DIR)/main.c $(OBJ_DIR)/libfuncs.a -o app.exe

#linklib
link: $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -fPIC -c $(SRC_DIR)/funcs.c -o $(OBJ_DIR)/funcs.o
	$(CC) -I$(INC_DIR) -o $(OBJ_DIR)/libfuncs.so -shared $(OBJ_DIR)/funcs.o
	$(CC) -I$(INC_DIR) $(SRC_DIR)/main.c -L $(OBJ_DIR)/. -lfuncs -o link_app.exe

#loadlib
load: $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/funcs.c -o $(OBJ_DIR)/funcs.o
	$(CC) -I$(INC_DIR) -o $(OBJ_DIR)/libfuncs.so -shared $(OBJ_DIR)/funcs.o
	$(CC) $(CFLAGS) -I$(INC_DIR) $(SRC_DIR)/main_load.c -o app.exe -ldl

$(EXEC_DEBUG): $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -I$(INC_DIR) -c $< -o $@

unit: $(OBJ_DIR) $(UOBJS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $(SRC_DIR)/funcs.c -o $(OBJ_DIR)/funcs.o
	ar cr $(OBJ_DIR)/libfuncs.a $(OBJ_DIR)/funcs.o
	ranlib $(OBJ_DIR)/libfuncs.a
	$(CC) $(UOBJS) $(OBJ_DIR)/libfuncs.a $(UFLAGS) -o unit_app.exe

$(OBJ_DIR)/%.o: $(UNIT_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

func:
	./collect_coverage.sh

clean:
	rm -f -r $(OBJ_DIR) *.exe *.gcov ./func_tests/scripts/*.txt *.a

cleano:
	rm -f -r $(OBJ_DIR)

include $(wildcard $(addsuffix /*.d, $(OBJ_DIR)))
