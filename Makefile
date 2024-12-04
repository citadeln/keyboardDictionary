TARGET = start
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -g
GCOVFLAGS = -fprofile-arcs -ftest-coverage

PREF_SRC = ./lib
PREF_OBJ = ./obj/
FRONTEND = gui/

DEBUG_DIR = debug
DEBUG_NAME = debug.out

SRC_TEST = tests/test.c
LIBS_TEST = -lcheck -lsubunit -lm -lgcov

SRC = $(shell find $(PREF_SRC) $(FRONTEND) -name '*.c')
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))

$(PREF_OBJ)%.o: $(PREF_SRC)%.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

install: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

test: clean 
	@rm -rf build
	@mkdir -p build
	@$(CC) $(CFLAGS) brick_game/tetris/backend.c tests/*.c -L. -L/usr/local/lib -L/usr/include $(GCOVFLAGS) $(LIBS_TEST) -o build/test_dictionary $(EXTRA_FLAG)
	@build/test_dictionary

gcov_report: test
#	~/.local/bin/gcovr
	gcovr -r . --html --html-details -o build/testDictionary.html
	@xdg-open build/testDictionary.html


val: test_build
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes $(BUILD_DIR)/$(TEST_NAME)
	@$(MAKE) clean_all

style:
	find . lib tests -name '*.[ch]' | xargs clang-format -n -style=Google
	find . lib tests -name '*.[ch]' | xargs clang-format -i -style=Google

debug: clean $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(DEBUG_DIR)/$(DEBUG_NAME)

check: val
	cppcheck --enable=all --suppress=missingIncludeSystem .
	cp ../materials/linters/.clang-format .
	find . -name '*.[ch]' | xargs clang-format -n || true
	rm .clang-format
	@echo;

clean_gcovr:
	@rm -f *.gcda *.gcno $(BUILD_DIR)/*.gcda $(BUILD_DIR)/*.gcno $(BUILD_DIR)/$(TEST_NAME)

clean:
	rm -rf $(TARGET) $(PREF_OBJ) $(DEBUG_DIR)/$(DEBUG_NAME) build *.gcda *.gcno testDictionary.css testDictionary.html
	@echo;echo "Clean complete";echo;

# clean: clean_gcovr
# 	@rm -f $(OBJECTS)/*.o
# 	@rm -f $(LIB) $(TEST_NAME) $(DEBUG_DIR)/$(DEBUG_NAME) $(TARGET) || true
# 	@rm -rf ./gcov_report *.html
# 	@rm -rf $(BUILD_DIR)	
