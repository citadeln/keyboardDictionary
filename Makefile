TARGET = start
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -g
GCOVFLAGS = -fprofile-arcs -ftest-coverage

PREF_SRC = ./lib
PREF_OBJ = ./obj/
FRONTEND = gui/

DEBUG_DIR = debug
DEBUG_NAME = debug.out

TESTFLAGS = -lcheck -lsubunit -lm -lgcov --coverage

SRC = $(shell find $(PREF_SRC) $(FRONTEND) -name '*.c')
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

$(PREF_OBJ)%.o: $(PREF_SRC)%.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

install: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

test: clean 
	@mkdir -p build
	@$(CC) $(CFLAGS) lib/keyboardDictionary.c tests/*.c -L. -L/usr/local/lib -L/usr/include $(GCOVFLAGS) $(TESTFLAGS) -o build/test_dictionary
	@./build/test_dictionary

gcov_report: test
#	~/.local/bin/gcovr
	gcovr -r . --html --html-details -o build/testDictionary.html
	@xdg-open build/testDictionary.html

style:
	find . lib tests -name '*.[ch]' | xargs clang-format -n -style=Google
	find . lib tests -name '*.[ch]' | xargs clang-format -i -style=Google

check:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem lib/keyboardDictionary.c

val: install
	valgrind --tool=memcheck --leak-check=yes ./$(TARGET)

clean:
	@rm -rf $(TARGET) $(PREF_OBJ) $(DEBUG_DIR)/$(DEBUG_NAME) build *.gcda *.gcno testDictionary.css testDictionary.html
	@echo;echo "Clean complete";echo;
