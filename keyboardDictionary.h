#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define FILE_NAME "tests/dictionary20000.txt"
#define ROWS_IN_KEYBOARD \
  5  // 3 + before + after in oreder not to be out of array
#define COLS_IN_KEYBOARD \
  12  // 10 + before + after in oreder not to be out of array

bool areAdjacent(char c1, char c2);
bool isValidChar(char x);
