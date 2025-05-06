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

int main(int argc, char *argv[]) {
    char filename[1024];
    strcpy(filename, argv[1]);
    printf("Arg: %s\n", argv[1]);
    char content[4096];

    FILE *pF = fopen(argv[1], "r");
    
    char buffer[255];

    if(pF == NULL) 
    {
        printf("Unable to open file!\n");
    }
    else
    {
        while(fgets(buffer, 255, pF) != NULL)
        {
            printf("%s\n", buffer);
            if (strcmp(buffer, "\n") == 0) {
                continue;
            } else {
                strcpy(content, buffer);
            }
        }
    }

    char delimiter[] = " ";
    char *token;

    token = strtok(content, delimiter);

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delimiter);
    }



    fclose(pF);

    return 0;
}