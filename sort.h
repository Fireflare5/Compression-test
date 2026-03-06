#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

void sort(int *__intPtr, char *__charPtr, size_t __size) {
    int lint = 0;
    int shift = 0;
    int cPos;
    for(size_t i = 0; i <= __size; ++i) {
        if(__intPtr[i] > lint) {
            lint = __intPtr[i];
        }
    }

    int *intArray = calloc(lint + 1, sizeof(int));
    char *charArray = malloc((lint + 258) * sizeof(char));
    
    for(int i = 0; i <= __size; ++i) {
        cPos = __intPtr[i];
        if(!intArray[cPos]) {
            intArray[cPos]++;
            charArray[cPos] = __charPtr[i];
        } else {
            shift++;
            intArray[cPos]++;
            charArray[lint + shift] = __charPtr[i];
        }
    }

    shift = 1;
    cPos = 0;
    for(int i = 0; i <= lint; ++i) {
        if(!intArray[i]) {
            continue;
        } else {
            shift--;
            __charPtr[cPos] = charArray[i];
            __intPtr[cPos] = i;
            cPos++;
            for(int j = 0; j < intArray[i] - 1; ++j) {
                shift++;
                //printf("%c", charArray[i + shift]);
                __charPtr[cPos] = charArray[lint + shift];
                __intPtr[cPos] = i;
                cPos++;
            }
        }
    }

    free(intArray);
    free(charArray);
}
#endif