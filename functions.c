#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"


Buffer* create_buffer(int n){
    Buffer* newBuffer;
    newBuffer = malloc(sizeof(Buffer));
    newBuffer->size = n;
    newBuffer->data = malloc(sizeof(char)*n);
    for (int i = 0; i < newBuffer->size; i++)
        newBuffer->data[i] = '.';
    newBuffer->w = 0;
    newBuffer->r = 0;
    newBuffer->is_empty = 1;
    return newBuffer;
}

void print_buffer(Buffer* buffer){
    for (int i = 0; i < buffer->size; i++){
        printf("|");
        printf("%c", buffer->data[i]);
    }
    printf("|\n");
}

int write_buffer(Buffer* buffer, char info){
    if (buffer->w != buffer->r || (buffer->w == buffer->r && buffer->is_empty == 1))
    {
        buffer->data[buffer->w] = info;
        buffer->w = (buffer->w + 1)% buffer->size;
        buffer->is_empty = 0;
        return 0;
    }
    printf("Can't write %c, cell not empty. You need to read the cell first.\n", info);
    return -1;
}

char read_buffer(Buffer* buffer){
    if (buffer->w != buffer->r || (buffer->w == buffer->r && buffer->is_empty == 0)){
        char temp = buffer->data[buffer->r];
        buffer->data[buffer->r] = '.';
        buffer->r = (buffer->r + 1) % buffer->size;
        if (buffer->r == buffer->w)
            buffer->is_empty = 1;
        return temp;
    }
    printf("Can't read an empty cell.\n");
    return '\0';
}

void print_w(Buffer *buffer){

    printf(" ");
    for (int i = 0; i < buffer->w; i++)
    {
        printf("  ");
    }
    printf("w\n");
}

void print_r(Buffer *buffer){
    printf(" ");
    for (int i = 0; i < buffer->r; i++)
    {
        printf("  ");
    }
    printf("r\n");
}

char* str_append(char* str, char c){
    size_t len = strlen(str);
    char *str2 = malloc(len+1+1);
    strcpy(str2, str);
    str2[len] = c;
    str2[len + 1] = '\0';
    return str2;
}