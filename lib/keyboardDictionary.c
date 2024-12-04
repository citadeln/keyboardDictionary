#include "../keyboardDictionary.h"

// Function to check if two characters are adjacent on a QWERTY keyboard
bool areAdjacent(char c1, char c2) {
  // Define adjacent key pairs on a QWERTY keyboard
  bool result = false;
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
            c2 == keyboard[i][j - 1] || c2 == '-')
          result = true;

  return result;
}

int main() {
  // Open the file containing English words
  FILE *file = fopen("1.txt", "r");
  if (file == NULL) {
    printf("Error opening the file.\n");
    return 1;
  }

  char word[100];
  int count = 0;

  // Read each word from the file and check if it can be typed using adjacent
  // keys
  while (fscanf(file, "%s", word) != EOF) {
    bool valid = true;
    for (int i = 0; word[i + 1] != '\0'; i++) {
      if (!areAdjacent(word[i], word[i + 1])) {
        valid = false;
        break;
      }
    }
    if (valid)
      count++;
  }

  fclose(file);
  printf("%d\n", count);

  return 0;
}
