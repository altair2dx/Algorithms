#include <stdio.h>
#include <time.h>
#include <math.h>

int numDigits(unsigned long long number) {
    return floor(log10(number)) + 1;
}

unsigned long long middleSqaure (unsigned long long seed, unsigned long long digit) {
    unsigned long long square = seed * seed;
    unsigned long long squareDigit = numDigits(square);
    unsigned long long remainDigit = (squareDigit - digit) / 2;
    return (square % (unsigned long long)pow(10,squareDigit-remainDigit)) / (unsigned long long)pow(10,squareDigit-remainDigit-digit);
}

int main() {
    unsigned long long seed = time(NULL);
    unsigned long long digit = 6;
    unsigned long long ms = middleSqaure(seed, digit); 
    for (int i = 1; i<101; i++) {
        printf("X%d = %llu \n", i, ms);
        ms = middleSqaure(ms, digit);
    }

    return 0;
}