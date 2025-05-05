#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define exec system

void* MEA(size_t size) {
    char* string = (char*)malloc(size + 8);
    string[size + 8] = '\0';
    return (void*)string;
}

void link_arrays(void* array1, void* array2, size_t size) {
    char temp = ((char*)array1)[size-8];
    memcpy(&temp, &array2, 8);
}

void add_data(void* array, char* data, size_t size) {
    memcpy(array, data, size);
}

int main(int argc, char** argv) {
    
}