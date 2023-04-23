#include "input.h"

Text get_text() {
	Text text;
	printf("Input count of elements in array: ");
	text.len = get_num();
	text.strings = (char**) malloc(sizeof(char*) * (text.len));
	printf("Input num %i times\n", text.len);
	for (int i = 0; i < text.len; i++) {
		text.strings[i] = get_str();
	}
	puts("U INPUT FULL ARRAY");
	return text;
}

unsigned int len_str (char* str) {
	unsigned int i = 0;
	while(str[i]) {
		i++;
	}
	return i;
}

char* get_str() {
    char symb;
    char* string = (char*) calloc(0, sizeof(char));           
        for (unsigned int j = 0; (symb = getchar()) != '\n'; ++j) {
            string = (char*) realloc(string, (j + 1) * sizeof(char));
            string[j] = symb;
            string[j + 1] = '\0';
        }
    return string;
}

void print(Text text) {
	for(unsigned int k = 0; k < text.len; k++) { 
        printf("%s\n", text.strings[k]);
    } 
}

int get_num() {
	int num;
	char* str;
	do {
		str = get_str();
		num = atoi(str);
		if (num == 0) {
			if (*str == '0') {
				free(str);
				break;
			}
			else {
				puts("error num, input again");
			}
		}
		free(str);
	} while (!num);
	return num;
}

int equivalent(char* first, char* second) {
    while (*first == *second) { //если попадаются разные символы или если первая или вторая строка короче другой, то цикл завершается
        if (*first == '\0') { //если строки одинаковой длины и все предыдущие символы одиноковы, то возвращает true из функции
            return 1;
        }
		*first++;
		*second++;
    } 
    return 0;
}

int strend (char* str_full, char* str_end) {
	if (!(*str_end && *str_full)) {
		return 0;
	}
	int len = len_str(str_end);
	if (len > len_str(str_full)) {
		return 0;
	}
	while (*(str_full + len)) {
		str_full++;
	}
	return equivalent(str_full, str_end);
}