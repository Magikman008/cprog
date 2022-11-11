.PHONY: clean debug cleano func key
.NOTPARALLEL: debug func

CC = gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
UFLAGS := -lcheck
DFLAGS := 

#UFLAGS += -lm -lsubunit

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
USRCS := $(addprefix $(UNIT_DIR)/,$(UNITS) $(FUNCS))
UOBJS := $(addprefix $(OBJ_DIR)/,$(OUNITS) $(OFUNCS))

EXEC_APP := app.exe
EXEC_DEBUG := debug.exe
EXEC_UNIT := unit_tests.exe

$(EXEC_APP): $(OBJ_DIR) | $(OBJS)
	$(CC) $(OBJS) $(DFLAGS) -o $@

key : CFLAGS += -DDEBUG
key : cleano
key : $(EXEC_DEBUG)

debug : CFLAGS += -g3 --coverage
debug : cleano
debug : DFLAGS += --coverage
debug : $(EXEC_APP)

$(EXEC_DEBUG): $(OBJ_DIR) | $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -I$(INC_DIR) -c $< -o $@

unit: cleano
unit: $(EXEC_UNIT)

$(EXEC_UNIT): $(OBJ_DIR) | $(UOBJS)
	$(CC) $(UOBJS) $(UFLAGS) -o $@

$(OBJ_DIR)/%.o: $(UNIT_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@


func:
	./collect_coverage.sh

# unit: $(EXEC_UNIT)
# 	valgrind --leak-check=full ./$(EXEC_UNIT)
# 	@echo "\nrc = $$?"
# 	@echo "\nCoverage report:"
# 	gcov -f -r $(OBJECTS:%.o=%.gcno)


clean:
	rm -f -r $(OBJ_DIR) *.exe *.gcov ./func_tests/scripts/*.txt

cleano:
	rm -f -r $(OBJ_DIR)

include $(wildcard $(addsuffix /*.d, $(OBJ_DIR)))
