// #include "../keyboardDictionary.h"

// // Function to check if two characters are adjacent on a QWERTY keyboard
// bool areAdjacent(char c1, char c2) {
//     // Define adjacent key pairs on a QWERTY keyboard
//     char qwerty[26] = "qwertyuiopasdfghjklzxcvbnm";
//     int adj[26][7] = {
// {1, 0, 0, 1, 0, 0}, // q
// {1, 1, 0, 1, 1, 0}, // w
// {1, 1, 0, 1, 1, 0}, // e
// {1, 1, 0, 1, 1, 0}, // r
// {1, 1, 0, 1, 1, 0}, // t
// {1, 1, 0, 1, 1, 0}, // y
// {1, 1, 0, 1, 1, 0}, // u
// {1, 1, 0, 1, 1, 0}, // i
// {1, 1, 0, 1, 1, 0}, // o
// {1, 0, 1, 1, 0, 1}, // p
// {0, 0, 1, 1, 0, 1}, // a
// {0, 1, 1, 1, 1, 1}, // s
// {0, 1, 1, 1, 1, 1}, // d
// {0, 1, 1, 1, 1, 1}, // f
// {0, 1, 1, 1, 1, 1}, // g
// {0, 1, 1, 1, 1, 1}, // h
// {0, 1, 1, 1, 1, 1}, // j
// {0, 1, 1, 1, 1, 1}, // k
// {0, 1, 1, 1, 1, 1}, // l
// {0, 1, 1, 0, 1, 1}, // z
// {0, 1, 1, 0, 1, 1}, // x
// {0, 1, 1, 0, 1, 1}, // c
// {0, 1, 1, 0, 1, 1}, // v
// {0, 1, 1, 0, 1, 1}, // b
// {0, 0, 1, 0, 1, 1}, // n
// {0, 0, 1, 0, 1, 1}, // m
//     };

//     c1 = tolower(c1);
//     c2 = tolower(c2);

//     for (int i = 0; i < 26; i++) {
//         if (c1 == qwerty[i]) {
//             for (int j = 0; j < 7; j++) {
//                 if (adj[i][j] == 1 && c2 == qwerty[i+j]) {
//                     return true;
//                 }
//             }
//         }
//     }

//     return false;
// }

// int main() {
//     // Open the file containing English words
//     FILE *file = fopen("1.txt", "r");
//     if (file == NULL) {
//         printf("Error opening the file.\n");
//         return 1;
//     }

//     char word[100];
//     int count = 0;

//     // Read each word from the file and check if it can be typed using
//     adjacent keys while (fscanf(file, "%s", word) != EOF) {
//         bool valid = true;
//         for (int i = 0; word[i+1] != '\0'; i++) {
//             if (!areAdjacent(word[i], word[i+1])) {
//                 valid = false;
//                 break;
//             }
//         }
//         if (valid) {
//             count++;
//         }
//     }

//     // Close the file
//     fclose(file);

//     // Output the count of words that can be typed using adjacent keys
//     printf("Number of English words that can be typed using adjacent keys:
//     %d\n", count);

//     return 0;
// }