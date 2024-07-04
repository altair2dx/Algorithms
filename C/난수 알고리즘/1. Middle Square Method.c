/* --- 중앙제곱법 (Middle Square Method) --- */
// 수열 Xₙ₊₁ = {(Xₙ)² 중앙의 a자리} 를 이용해 난수를 생성하는 방식.
// 1949년 고안, 난수의 품질이 좋지 않아 현재는 사용하지 않는다.

// 예시
// X₀ = 1773, a = 4
// X₀² = 3143529 → X₁ = 1435
// X₁² = 2059225 → X₂ = 592
// X₂² = 350464 → X₃ = 5046
// X₃² = 25462116 → X₄ = 4621
// ...

// 코드
#include <stdio.h>
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
    unsigned long long seed = 1773;
    unsigned long long digit = 4;
    for (int i = 0; i<5; ++i) {
        printf("X%d = %llu \n", i, seed);
        seed = middleSqaure(seed, digit);
    }

    return 0;
}