메르센 트위스터
=============

![image](https://github.com/altair2dx/Algorithms/assets/167539294/fbefb217-8b1e-49f6-ad0f-2a3ac76d897c)

<br/>


<h2>Seed를 이용한 초기 배열 구성</h2>

$Seed = mt[0]$ , $i\in[1,n-1]$ 일 때, 다음과 같은 식으로 초기 배열 $(mt[1], \cdots, mt[n-1])$ 을 구한다.

$mt[i]=f \times (mt[i-1]\oplus{}(mt[i-1]>>(w-2)))+i$

<br/>

- MT19937 표준에서는 $n=624$, $w=32$, $f=1812433253_{10}=\text{0x6C078965}$ 이므로 초기 배열식은 다음과 같다.

<br/>

  $$mt[i]=\text{0x6C078965} \times (mt[i-1]\oplus{}(mt[i-1]>>30))+i$$

  $$i\in[1,623]$$

<br/>

<h2>난수의 무작위성을 위한 Twist</h2>

Twist 알고리즘은 다음과 같다.

<br/>

$i\in[1,n-1]$ 에 대하여

$x=(mt[i]\wedge\text{UMASK})+(mt[(i+1)\mod n]\wedge\text{LMASK})$

$xA=x>>1$

$\text{if}\quad x\mod2\neq0:xA=xA\oplus a$

$Twisted$_$mt[i]=mt[(i+m)\mod n]\oplus xA$

<br/>


- MT19937 표준에서 $n=624$, $m=397$, $\text{UMASK}=\text{0x80000000}$, $\text{LMASK}=\text{0x7fffffff}$, $a=\text{0x9908B0DF}$

<br/>

<h2>Temper</h2>