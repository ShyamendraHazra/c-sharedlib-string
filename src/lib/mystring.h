#ifndef MYSTRING.H
#define MYSTRING.H

#include <stdint.h>

typedef struct {
    uint8_t *str;
    uint16_t len;
    int8_t str_state;
} String;

void initialize_string(); //Initialise 
void deinitialize_string();
void print_string();
void slice_String();
#endif