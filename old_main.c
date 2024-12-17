// #include "lib/keyboardDictionary.h"

// int main() {
//   FILE *file = fopen(FILE_NAME, "r");
//   if (file == NULL) {
//     printf("Error opening the file.\n");
//     return 1;
//   }

//   char curChar = '\0';
//   char prevChar = '\0';
//   bool valid = true;
//   int count = 0;

//   while ((curChar = fgetc(file)) != EOF) {
//     // the end of the world
//     if (curChar == '\n') {
//       if (valid && prevChar != '\0') count++;
//       valid = true;
//       prevChar = '\0';
//       continue;
//     }

//     curChar = tolower(curChar);

//     if (!isValidChar(curChar)) {
//       valid = false;
//       prevChar = curChar;
//       continue;
//     }

//     switch (prevChar) {
//       // the begin of the world
//       case '\0':
//         prevChar = curChar;
//         break;
//       // other cases:
//       default: {
//         if (!areAdjacent(prevChar, curChar) || !isValidChar(curChar)) {
//           valid = false;
//         }
//         prevChar = curChar;
//       }
//     }
//   }

//   // count++ last world in the all dictionary
//   if (valid && prevChar != '\0') count++;

//   fclose(file);
//   printf("%d\n", count);

//   return 0;
// }
