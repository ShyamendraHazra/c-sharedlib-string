#include <stdio.h>
#include <stdbool.h>
#include "lib/mystring.h"

int main() {
    char ch;

    String newString;
    initialize_string(&newString);
    printf("Enter a string :: ");
    
    while(true) {

        if((ch = getchar()) == '\n' ) {
            extend_string(&newString, '\0');    
            break;
        }

        extend_string(&newString,ch);
    }

    print_string(&newString);
    deinitialize_string(&newString);
}