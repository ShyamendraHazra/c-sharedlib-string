#include "lib/mystring.h"

void extend_string(String* str, char chr) {

    if(str == NULL) {
        printf("Invalid string referrence given\n");
        return;
    }

    char* temp;

    if(str->len == UINT16_MAX) {
        printf("String already full to the maximum capacity\n");
        return;
    }

    if(str->len == UINT16_MAX-1) {
        
        printf("String length limit reached\n");
        printf("Terminating the string with a null terminator");
        
        temp = (char*)realloc(str->sptr, (str->len+1)*sizeof(char));
        
        if(temp == NULL) {
            
            printf("Failed to allocate space for string pointer to terminate\nReleasing the string\n");
            deinitialize_string(str);
            return;
        }

        str->sptr = temp;
        str->len++;        
        str->sptr[str->len-1] = '\0';
        return;
    }

    temp = (char*)realloc(str->sptr, (str->len+1)*sizeof(char));
        
    if(temp == NULL) {
        
        printf("Failed to allocate space for string pointer.\n");
        deinitialize_string(str);
        return;
    }

    str->sptr = temp;
    str->len++;
    
    if(str->len == 1) {

       str->str_state = STRING_HEAP_ALLOCATED;
    }
    str->sptr[str->len-1] = chr;
    return;
}

void initialize_string(String* str) {

    if(str == NULL) {
        printf("Invalid string referrence given\n");
        return;
    }

    if(str->str_state == STRING_HEAP_ALLOCATED) {
        printf("String already allocated\n");
        return;
    } else if(str->str_state == STRING_EMPTY) {
        printf("String already initialized\n");
        return;
    } 

    str->sptr = NULL;
    str->len = 0;
    str->str_state = STRING_EMPTY;
    return;
}

void deinitialize_string(String* str) {

    if(str == NULL) {
        printf("Invalid string referrence given\n");
        return;
    }

    if(str->str_state == STRING_HEAP_ALLOCATED) 
    {
        free(str->sptr);
        str->sptr = NULL;

    } else {

        str->sptr = NULL;
    }

    str->len = 0;
    str->str_state = STRING_EMPTY;

}

void print_string(String* str) {
    
    if(str == NULL) {
        printf("Invalid string referrence given\n");
        return;
    }

    if (str->len != 0 && str->str_state != STRING_EMPTY) {
        printf("%s\n",str->sptr);
    }
}

void slice_string(String* str, uint16_t beg, uint16_t end, String* slice) {
    
    if(str == NULL) {
        printf("Invalid string referrence given\n");
        return;
    }
    
    if(beg >= end || end > str->len) {
        printf("Invalid Slice index\n");
        return;
    }


    for (; beg < end; beg++) {

        extend_string(slice, str->sptr[beg]);
        
        if(slice->str_state == STRING_EMPTY) {

            printf("Failed to slice string\n");
            exit(EXIT_FAILURE);
        }
    }

}
