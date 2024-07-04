#include <stdio.h>

#define N 624

static unsigned long mt[N];
static int mti=N+1;

int main() {
    mt[0]= 0x012BD6AAUL & 0xFFFFFFFFUL;
    printf("mt[0] : %ld \n", mt[0]);
    for (mti=1; mti<N; mti++) {
        unsigned long xor = mt[mti-1] ^ (mt[mti-1] >> 30);
        printf("XOR %d : %ld ", mti, xor);
        mt[mti] = 0x6C078965UL * xor + mti; 
        printf("mt[%d] : %ld \n", mti, mt[mti]);
        mt[mti] &= 0xffffffffUL;
    }
}


