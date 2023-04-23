#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void print(Text text);
Text get_text();
int get_num();
char* get_str();
unsigned int len_str (char* str);
int strend (char* str_full, char* str_end);