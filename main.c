#include <pthread.h>
#include <sys/sysinfo.h>

#include "lib/keyboardDictionary.h"

typedef struct {
    const char* filename;
    int threadCount;
} ThreadData;

void* processFile(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    
    FILE* file = fopen(data->filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return NULL;
    }

    char curChar = '\0';
    char prevChar = '\0';
    bool valid = true;
    int count = 0;

    while ((curChar = fgetc(file)) != EOF) {
        if (curChar == '\n') {
            if (valid && prevChar != '\0') count++;
            valid = true;
            prevChar = '\0';
            continue;
        }

        curChar = tolower(curChar);

        if (!isValidChar(curChar)) {
            valid = false;
            prevChar = curChar;
            continue;
        }

        switch (prevChar) {
            case '\0':
                prevChar = curChar;
                break;
            default: {
                if (!areAdjacent(prevChar, curChar) || !isValidChar(curChar)) {
                    valid = false;
                }
                prevChar = curChar;
            }
        }
    }

    if (valid && prevChar != '\0') count++;

    printf("Number of words: %d\n", count);

    fclose(file);

    return NULL;
}

int main() {
int numCores = get_nprocs(); // Get the number of available cores
int numThreads = 1;

if (numCores >= 4) {
    numThreads = 4;
} else if (numCores >= 2) {
    numThreads = 2;
}

    pthread_t threads[numThreads];
    ThreadData threadData[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        threadData[i].filename = FILE_NAME;
        threadData[i].threadCount = numThreads;
        pthread_create(&threads[i], NULL, processFile, (void*)&threadData[i]);
    }

    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
