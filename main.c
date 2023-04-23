#include <stdio.h>
#include "input.h"
#include "shall.h"

int main() {
    puts("INPUT STRING:");
    char* str1 = get_str();
    puts("INPUT ENDING STRING:");
    char* str2 = get_str();
    printf("result: %i\n", strend(str1, str2));
    free(str1);
    free(str2);
    Text text = get_text();
    shall_sort(text);
    puts("RESULT OF SHALL SORT:\n");
    print(text);
    for(unsigned int i = 0; i < text.len; i++) {
        free(text.strings[i]);
    }
    free(text.strings);
}