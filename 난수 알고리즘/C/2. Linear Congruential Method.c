// [0,1] 범위에서 난수 출력
#include <stdio.h>
#include <time.h>

#define A 1103515245
#define C 12345
#define M 0x7fffffff

// LCG 함수
int LCG(unsigned int seed) {
    return ((seed * A) + C) & M;
}

int main() {
    unsigned int seed = time(NULL); // 현재 시간을 시드로 설정
    for(int i = 0; i < 4; i++) {
        seed = LCG(seed); // 난수 생성
        double result = (double)seed / M; // 난수를 [0,1] 범위로 정규화
        printf("%lf \n", result);
    }
    
    return 0;
}