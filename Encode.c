#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

size_t readf(void **__restrict__ __ptr, const char *__restrict__ __dir, const char *__restrict__ __mode) {
    FILE *fptr = fopen(__dir, __mode);
    fseek(fptr, 0, SEEK_END);
    size_t size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    *__ptr = malloc(size);
    size_t size_ = fread(*__ptr, 1, size, fptr);

    fclose(fptr);
    
    return size;
}

int main() {
    char *text;
    size_t size = readf((void **)&text,"file.oe","rb");
    int *arr = calloc(size, sizeof(int));
    char *charList;
    int *intList;
    int unique_chars = 0;
    char buffer;

    if(size <= 256) {
        charList = malloc((size + 1) * sizeof(char));
        intList = malloc(size * sizeof(int));
    } else {
        charList = malloc((256 + 1) * sizeof(char));
        intList = malloc(256 * sizeof(int));
    }

    for(size_t i = 0; i < size; ++i) {
        if(!i) {
            intList[unique_chars] = 1;
            charList[unique_chars] = text[i];
            buffer = text[i];
        } else if(arr[i]) {
            continue;
        } else {
            unique_chars++;
            intList[unique_chars] = 1;
            charList[unique_chars] = text[i];
            buffer = text[i];
        }
        for(size_t j = i + 1; j < size; ++j) {
            if(text[j] == buffer) {
                intList[unique_chars]++;
                arr[j] = 1;
            }
        }
    }

    sort(intList, charList, unique_chars);

    for(int i = 0; i <= unique_chars; ++i) {
        printf("%c %u\n",charList[i], intList[i]);
    }
    //printf("\n%u\n",unique_chars + 1);

    free(charList);
    free(intList);
    free(arr);
    free(text);

    return 0;
}