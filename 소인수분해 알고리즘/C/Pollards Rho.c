#include <stdio.h>
#include <stdlib.h>
#include </workspaces/Algorithms/소수 판별 알고리즘/C/prime.h>

unsigned long long GCD(unsigned long long a, unsigned long long b) {
    unsigned long long R;
    while (b) {
        R = a % b;
        a = b;
        b = R;
    }
    return a;
}

unsigned long long findFactor(unsigned long long n, int c) {
    unsigned long long g(int x) {
        return ((x*x)+c) % n;
    }
    if (!(n & 1)) return 2;
    int x = rand() % (n+1);
    int y = x;
    while (1) {
        x = g(x);
        y = g(g(y));
        unsigned long long d = GCD(abs(y-x),n);
        if (d>1&&d<n) return d;
        if (x==y) return n;
    }
}

int main () {
    unsigned long long n;
    scanf("%llu", &n);
    
    printf("%llu = ", n);
    unsigned long long pf[63] = {0};
    int index = 0;
    while (n != 1) {
        if (isPrime(n)) {
            pf[index] = n;
            index++;
            break;
        }
        else {
            int c = findFactor(n,rand() % n);
            if (isPrime(c)) {
                pf[index] = c;
                index++;
                n /= c;
            }
        }
    }
    
    for (int i = 0; i < 63; i++) {
        if (pf[i]) {
            printf("%llu", pf[i]);
        }
        if (pf[i+1]!=0 && i<62) printf(" * ");
    }
    

    // system("read -p 'Press Enter to continue...' var");

    return 0;
}


