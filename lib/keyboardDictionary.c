#include "keyboardDictionary.h"

/**
 * @brief Check if two characters are adjacent on a QWERTY keyboard
 *
 * @param[in] c1 and c2 - characters of the world
 * @return true if the characters are adjacent, false if they are not adjacent
 */
bool areAdjacent(char c1, char c2) {
  const char keyboard[ROWS_IN_KEYBOARD][COLS_IN_KEYBOARD] = {
      "000000000000", "0qwertyuiop0", "0asdfghjkl00",
      "0zxcvbnm0000", "000000000000",
  };
  
  c1 = tolower(c1);
  c2 = tolower(c2);

  for (int i = 1; i < ROWS_IN_KEYBOARD; i++)
    for (int j = 0; j < COLS_IN_KEYBOARD; j++)
      if (c1 == keyboard[i][j]) {
        if (c2 == keyboard[i][j] || c2 == keyboard[i - 1][j] ||
            c2 == keyboard[i - 1][j + 1] || c2 == keyboard[i][j + 1] ||
            c2 == keyboard[i + 1][j] || c2 == keyboard[i + 1][j - 1] ||
            c2 == keyboard[i][j - 1])
          return true;
        else
          return false;
      }

  return false;
}

/**
 * @brief Check the character is alpha or '-' or '\''
 *
 * @return true if the characters is valid, false if it is not
 */
bool isValidChar(char x) { return (isalpha(x) || x == '-' || x == '\''); }
