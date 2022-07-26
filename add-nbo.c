#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    uint32_t buff1, buff2, addnum; // buffer, add
    FILE* file1 = NULL;
    FILE* file2 = NULL;


    // if there is no file, error
    file1 = fopen(argv[1], "r");
    if(file1 == NULL){
        fputs("File error", stderr);
        exit(1);
    }
    file2 = fopen(argv[2], "r");
    if(file2 == NULL){
        fputs("File error", stderr);
        exit(1);
    }

    fread(&buff1, sizeof(uint32_t), 1, file1);
    fread(&buff2, sizeof(uint32_t), 1, file2);

    buff1 = ntohl(buff1);
    buff2 = ntohl(buff2);
    addnum = buff1 + buff2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", buff1, buff1, buff2, buff2, addnum);

    // file reading
    
    // fread(buff, sizeof(char), 1, file2);
    // printf("0x%x", buff);

    // file print
    // printf("%s + %s = %s", );

    // file close 
    fclose(file1);
    fclose(file2);

}