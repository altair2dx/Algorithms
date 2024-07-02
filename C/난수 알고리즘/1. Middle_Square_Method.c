/* --- 중앙제곱법 (Middle Square Method) --- */
// 수열 Xₙ₊₁ = {(Xₙ)² 중앙의 a자리} 를 이용해 난수를 생성하는 방식.
// 1949년 고안, 난수의 품질이 좋지 않아 현재는 사용하지 않는다.

// 예시
// X₁ = 1773, a = 4
// X₁² = 3143529 → X₂ = 1435
// X₂² = 2059225 → X₃ = 592
// X₃² = 350464 → X₄ = 5046
// ...

// 코드
#include <stdio.h>
#include <math.h>

unsigned long long numDigits(unsigned long long number) {
    return floor(log10(number)) + 1;
}

unsigned long long middleSqaure (unsigned long long init, unsigned long long digit) {
    unsigned long long square = init * init;
    unsigned long long squareDigit = numDigits(square);
    unsigned long long remainDigit = (squareDigit - digit) / 2;
    unsigned long long middle = (square % (unsigned long long)pow(10,squareDigit-remainDigit)) / (unsigned long long)pow(10,squareDigit-remainDigit-digit);
    return middle;
}

int main() {
    unsigned long long init = 1773;
    unsigned long long digit = 4;
    for (int i = 0; i<5; ++i) {
        printf("%llu \n", init);
        init = middleSqaure(init, digit);
    }
}