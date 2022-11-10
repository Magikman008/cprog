.PHONY: clean debug cleano

CC = gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
UFLAGS := -lcheck -lpthread -lrt -lm -lsubunit

INC_DIR = ./inc
OBJ_DIR = ./out
SRC_DIR = ./src
UNIT_DIR = ./unit

MAIN := main.c
OMAIN := $(MAIN:.c=.o)
FUNCS := funcs.c
OFUNCS := $(FUNCS:.c=.o)
UNITS := unit_main.c unit_tests.c
OUNITS := $(UNITS:.c=.o)

SRCS := $(addprefix $(SRC_DIR)/,$(MAIN) $(FUNCS))
OBJS := $(addprefix $(OBJ_DIR)/,$(OMAIN) $(OFUNCS))
USRCS := $(addprefix $(UNIT_DIR)/,$(UNITS) $(FUNCS))
UOBJS := $(addprefix $(OBJ_DIR)/,$(OUNITS) $(OFUNCS))

EXEC_APP := app.exe
EXEC_DEBUG := debug.exe
EXEC_UNIT := unit_tests.exe

$(EXEC_APP): $(OBJ_DIR) | $(OBJS)
	@echo $(OBJS)
	$(CC) $(OBJS) -o $@

debug : CFLAGS += -DDEBUG
debug : cleano
debug : $(EXEC_DEBUG)

$(EXEC_DEBUG): $(OBJ_DIR) | $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -I$(INC_DIR) -c $< -o $@

# unit: CFLAGS += -lcheck -lpthread -lrt
unit: cleano
unit: $(EXEC_UNIT)

$(EXEC_UNIT): $(OBJ_DIR) | $(UOBJS)
	$(CC) $(UOBJS) $(UFLAGS) -o $@

$(OBJ_DIR)/%.o: $(UNIT_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@


# func: debug
# 	./collect_coverage.sh

# unit: $(EXEC_UNIT)
# 	valgrind --leak-check=full ./$(EXEC_UNIT)
# 	@echo "\nrc = $$?"
# 	@echo "\nCoverage report:"
# 	gcov -f -r $(OBJECTS:%.o=%.gcno)


clean:
	rm -f -r $(OBJ_DIR) *.exe *.gcov

cleano:
	rm -f -r $(OBJ_DIR)

