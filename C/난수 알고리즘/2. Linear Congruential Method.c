/* --- 선형합동법 (Linear Congruential Method) --- */
// 수열 Xₙ₊₁ = (aXₙ+c) mod m 를 이용해 난수를 생성하는 방식
// m, m > 0; 계수 (modulus) | 최대주기
// a, 0 < a < m; 승수 (multiplier)
// c, 0 ≤ c < m; 증분 (increment)
// X₀, 0 ≤ X₀ < m; 초기값 (seed)
// parameter에 의해 난수분포와 주기성이 바뀜
// parameter를 잘못 선택하면 편향된 난수분포, 주기성으로 인해 난수 품질이 좋지 않을 수 있음
// ANSI C 표준 : a = 1103515245, c=12345, m=2³¹

// 최대주기 조건
// 1. m과 c는 서로소 관계이다. (최대공약수 = 1)
// 2. m이 임의의 소수 p로 나누어 떨어지면 a-1도 p로 나누어 떨어진다.
// 3. m이 4로 나누어 떨어지면 a-1도 4로 나누어 떨어진다.

// 예시 ([0,1]에서 난수 출력)
#include <stdio.h>
#include <time.h>

int LCG(unsigned int seed) {
    unsigned int val = ((seed * 1103515245) + 12345) & 0x7fffffff;
    return val;
}

int main() {
    unsigned int seed = time(NULL);
    for(int i = 0; i < 4; ++i) {
        seed = LCG(seed);
        double result = (double)seed / 0x7fffffff;
        printf("%lf \n", result);
    }
    
}