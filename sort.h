#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

void sort(int *__intPtr, char *__charPtr, size_t __size) {
    // Custom sorting algorithm
    // First it counts the frequency of a number in a large array
    // It then loops through the array repeating the number for each occurrence and adding it into the sorted array

    int lint = 0; //Largest int in array
    int shift = 0; // Offset from position lint in an array
    int cPos; // Current position

    // Find the largest int in __intPtr
    for(size_t i = 0; i <= __size; ++i) {
        if(__intPtr[i] > lint) {
            lint = __intPtr[i];
        }
    }

    // Allocate memory
    int *intArray = calloc(lint + 1, sizeof(int));
    char *charArray = malloc((lint + 258) * sizeof(char));
    
    for(int i = 0; i <= __size; ++i) {
        cPos = __intPtr[i]; // Set cPos to char number

        if(!intArray[cPos]) {
            // Check if position is empty
            intArray[cPos]++; // Increase count for that position
            charArray[cPos] = __charPtr[i]; // Set the character at that position
        } else {
            shift++; // Increase the offset
            intArray[cPos]++; // Increase count
            charArray[lint + shift] = __charPtr[i]; // Add char for that position using the new offset
        }
    }

    shift = 1; // Set offset to 1
    cPos = 0; // Set start position
    for(int i = 0; i <= lint; ++i) {
        if(!intArray[i]) {
            // If position is empty skip
            continue; 
        } else {
            shift--; // Reduce offset
            __charPtr[cPos] = charArray[i]; // Set the char into its sorted position
            __intPtr[cPos] = i; // Set the int into its sorted position
            cPos++; // Move to next position
            for(int j = 0; j < intArray[i] - 1; ++j) {
                // Loop for all chars with a shared number
                shift++; // Incease offset
                __charPtr[cPos] = charArray[lint + shift]; // Set char to its sorted position
                __intPtr[cPos] = i; // Set the int to its sorted position
                cPos++; // Move to next position
            }
        }
    }

    // Free memory
    free(intArray);
    free(charArray);
}
#endif