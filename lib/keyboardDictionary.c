#include "../keyboardDictionary.h"
// Функция для проверки, являются ли два символа соседними на клавиатуре QWERTY
bool areAdjacent(char c1, char c2) {
  // Определяем позиции клавиш на клавиатуре QWERTY
  char keyboard[5][12] = {
      "000000000000", "0qwertyuiop0", "0asdfghjkl00",
      "0zxcvbnm0000", "000000000000",
  };

  c1 = tolower(c1);
  c2 = tolower(c2);

  for (int i = 1; i < 4; i++)
    for (int j = 0; j < 10; j++)
      if (c1 == keyboard[i][j])
        if (c2 == keyboard[i][j] || c2 == keyboard[i - 1][j] ||
            c2 == keyboard[i - 1][j + 1] || c2 == keyboard[i][j + 1] ||
            c2 == keyboard[i + 1][j] || c2 == keyboard[i + 1][j - 1] ||
            c2 == keyboard[i][j - 1])
          return true;

  return false;
}

// Функция для проверки, является ли символ буквой или допустимым символом
bool isValidChar(char x) { return (isalpha(x) || x == '-' || x == '\''); }
