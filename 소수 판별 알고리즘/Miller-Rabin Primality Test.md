밀러-라빈 소수 판별법 (Miller-Rabin Primality Test)
=============

[C로 구현된 밀러-라빈 테스트](./C/Miller-Rabin%20Primality%20Test.c)

밀러-라빈 소수 판별법은 확률론적으로 소수를 판별하는 알고리즘으로, $O(k\log^3 N)$ 의 시간복잡도를 가진다. ($k$는 $a$의 개수)

다음 두 식이 모두 성립하지 않을 경우 n을 소수일 것 같다고 판별한다.

- $a^d\not\equiv 1(\mod n)$
- $a^{2^rd}\not\equiv -1(\mod n) \quad \text{for all} \quad 0\leq r\leq s-1$

판별할 수가 충분히 작은 경우 작은 수의 $a$만 검사하여 결정론적으로 소수를 판별할 수 있다.

- $n<1,373,653 \Rightarrow a=2,3$
- $n<9,080,191 \Rightarrow a=31,73$
- $n<25,326,001 \Rightarrow a=2,3,5$
- $n<4,759,123,141 \Rightarrow a=2,7,61$
- $n<2,152,302,898,747 \Rightarrow a=2,3,5,7,11$
- $n<3,474,749,660,383 \Rightarrow a=2,3,5,7,11,13$
- $n<341,550,071,728,321 \Rightarrow a=2,3,5,7,11,13,17$
- long long 의 범위에서는 $37$이하의 소수만 검사하면 된다.
