.PHONY: clean debug cleano

CC = gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion

INC_DIR = ./inc
OBJ_DIR = ./out
SRC_DIR = ./src
UNIT_DIR = ./unit_tests

SRCS := funcs.c main.c
OBJS := funcs.o main.o

SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

EXEC_APP := app.exe
EXEC_DEBUG := debug.exe

# EXEC_UNIT := unit_tests.exe

$(EXEC_APP): $(OBJ_DIR) | $(OBJS)
	$(CC) $(OBJS) -o $@
	
debug : CFLAGS += -DDEBUG
debug : cleano
debug : $(EXEC_DEBUG)

$(EXEC_DEBUG): $(OBJ_DIR) | $(OBJS)
	$(CC) $(OBJS) -o $@

# $(EXEC_UNIT): CFLAGS += $(DFLAGS)
# $(EXEC_UNIT): LFLAGS += $(DFLAGS)
# $(EXEC_UNIT): $(OBJ_DIR) | $(filter-out $(OBJ_DIR)/main.o, $(UNIT_OBJECTS))
# 	$(CC) $(LFLAGS) $(filter-out $(OBJ_DIR)/main.o, $(UNIT_OBJECTS)) $(UFLAGS) -o $@
# 	@echo

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -MMD -I$(INC_DIR) -c $< -o $@

# $(OBJ_DIR)/%.o: $(UNIT_DIR)/%.c
# 	$(CC) $(CFLAGS) -MMD -I$(INC_DIR) -c $< -o $@

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

