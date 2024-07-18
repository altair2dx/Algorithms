#include <stdio.h>
#include <time.h>
#include <prime.h>

int main() {
    int TIME = 0;

	clock_t start, end;
	start = clock();

    unsigned long long n;
    printf("Type any number : ");
    scanf("%llu", &n);
    printf("%llu is %s Number. \n", n, (isPrime(n) ? "Prime" : "not Prime"));
	
    end = clock();
	printf("%fms has been taken.\n", (float)(end - start)/CLOCKS_PER_SEC);
    
    return 0;
}