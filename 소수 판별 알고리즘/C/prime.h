unsigned long long multMod(unsigned long long a, unsigned long long b, unsigned long long n) { //a*b mod n
    unsigned long long y=0;
    while (b) {
        if (b & 1) {
            unsigned long long y2 = y + a;
            if (y2 < y) y2 -= n;
            y = y2 % n;
        }
        b >>= 1;
        if (b) {
            unsigned long long a2 = a + a;
            if (a2 < a) a2 -= n;
            a = a2 % n;
        }
    }
    return y;
}

// Fast Modulo Exponential Algorithm
unsigned long long expMod(unsigned long long a, unsigned long long d, unsigned long long n) { //a^d mod n
    unsigned long long y = 1;
    while (d) {
        if (d & 1) y = multMod(y,a,n);
        d >>= 1;
        if (d) a = multMod(a,a,n);
    }
    return y;

}

int sprp(unsigned long long n, unsigned long long a){
    unsigned long long d = n - 1;
    
    // n-1 = 2^s * d
    int s = 0;
    while (!(d & 0xff)) { d>>=8; s+=8; }
    if (!(d & 0xf)) { d>>=4; s+=4; }
    if (!(d & 0x3)) { d>>=2; s+=2; }
    if (!(d & 0x1)) { d>>=1; s+=1; }
    
    unsigned long long x = expMod(a, d, n);
    
    if (x == 1 || x == n-1) return 1; //x=1 또는 x=n-1 이면 소수

    for (int i=1; i<s; i++) {
        x = multMod(x,x,n);
        if (x <= 1) return 0;
        if (x == n-1) return 1;
    }

    return 0;
}

int isPrime(unsigned long long n) {
    if (n<2||!(n&1)) return 0;
    if (n<4) return 1;
    if (!sprp(n,2)) return 0;
    if (n<2047) return 1;
    if (!sprp(n,3)) return 0;
    if (!sprp(n,5)) return 0;
    if (!sprp(n,7)) return 0;
    if (!sprp(n,11)) return 0;
    if (!sprp(n,13)) return 0;
    if (!sprp(n,17)) return 0;
    if (!sprp(n,19)) return 0;
    if (!sprp(n,23)) return 0;
    if (!sprp(n,29)) return 0;
    if (!sprp(n,31)) return 0;
    if (!sprp(n,37)) return 0;
    return 1;
}