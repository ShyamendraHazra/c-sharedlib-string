#ifndef MYSTRING_H
#define MYSTRING_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define STRING_EMPTY 0
#define STRING_HEAP_ALLOCATED 1

typedef struct {
    uint8_t *sptr;
    uint16_t len;
    int8_t str_state;
} String;

void extend_string(String* str, char chr);
void initialize_string(String* str); //Initialise String
void deinitialize_string(String* str); // De-Initialise String
void print_string(String* str);
void slice_string(String* str, uint16_t beg, uint16_t end, String* slice);

#endif