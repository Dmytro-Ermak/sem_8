#include "swap.h"
#include "input.h"

void shall_sort(Text text) {
    int step = text.len;
    do {
        step /= 2;
        for (int i = 0; i < step; i++) {            
            for (int j = i + step; j < text.len; j += step) {            
                for (int k = j; k - step >= i; k -= step) {
                    if (len_str(text.strings[k]) < len_str(text.strings[k - step])) {
                        SWAP(text.strings[k], text.strings[k - step]);
                    }
                    else {
                        break;
                    }
                }
            }
        }
    } while (step > 1);
}