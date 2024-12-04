#define IFDEBUG 0

#if IFDEBUG == 0

#include "../keyboardDictionary.h"

bool isChar(char x) {
  if ((x > 64 && x < 91) || (x > 96 && x < 123))
    return true;
  else
    return false;
}

int main() {

  printf("%d\n%d\n%d\n%d\n%d\n", isChar('s'), isChar('y'), isChar('1'), isChar('a'), isChar('z'));

  return 0;
}

#endif
