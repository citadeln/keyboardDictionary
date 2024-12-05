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

int main() {
  // Открываем файл с английскими словами
  FILE *file = fopen(FILE_NAME, "r");
  if (file == NULL) {
    printf("Error opening the file.\n");
    return 1;
  }

  char curChar = '\0';
  char prevChar = '\0';
  bool valid = true;
  int count = 0;

  while ((curChar = fgetc(file)) != EOF) {
    // Игнорируем пробелы
    if (curChar == '\n') {
      // Проверка на валидность слова
      if (valid && prevChar != '\0') count++;
      valid = true;  // Сбрасываем для следующего слова
      prevChar = '\0';  // Сбрасываем предыдущий символ
      continue;
    }

    // Приводим к нижнему регистру для удобства сравнения
    curChar = tolower(curChar);

    // Проверяем, является ли текущий символ допустимым
    if (!isValidChar(curChar)) {
      valid = false;  // Если не допустимый символ, слово недопустимо
      prevChar = curChar;  // Обновляем предыдущий символ
      continue;
    }

    switch (prevChar) {
      case '\0':  // Начало слова
        prevChar = curChar;
        break;
      default: {
        // Проверяем условия для смежных клавиш
        if (!areAdjacent(prevChar, curChar) || !isValidChar(curChar)) {
          valid = false;
        }
        prevChar = curChar;  // Обновляем предыдущий символ
      }
    }
  }

  // Проверка последнего слова в файле
  if (valid && prevChar != '\0') count++;

  fclose(file);
  printf("%d\n", count);

  return 0;
}
