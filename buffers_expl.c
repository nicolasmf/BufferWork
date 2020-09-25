#ifdef _WIN32
    char* clear = "cls";
#endif
#ifdef _Win64
    char* clear = "cls";
#endif
#ifdef __linux__
    char* clear = "clear";
#endif

#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

int main(){
    Buffer* myBuffer;
    char c;
    char *output = " ";

    myBuffer = create_buffer(3);
    system("clear");
    do {
        print_w(myBuffer);
        print_buffer(myBuffer);
        print_r(myBuffer);
        printf("\nOutput : %s", output);
        printf("\nEnter the character you want to add: ");
        scanf(" %c", &c);
        system(clear);
        if(c == '1'){
            char read_c = read_buffer(myBuffer);
            output = str_append(output, read_c);
        }
        else write_buffer(myBuffer, c);
    }while(c != '0');

    free(output);

    return 0;
}