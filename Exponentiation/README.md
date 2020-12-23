## Fast Exponentiation : a^b
> Time Complexity O(log b)

## Modular Arithmetic Properties:
   * (a+b)%c = ((a%c)+(b%c))%c
   * (a-b)%c = ((a%c)-(b%c)+c)%c
   * (a*b)%c = ((a%c)*(b%c))%c

   * [A. Arpa’s hard exam and Mehrdad’s naive cheat](https://codeforces.com/problemset/problem/742/A)
      * [Solution](https://github.com/ravi-poddar/Competitive-Programming/tree/master/Exponentiation/arpha.cpp)

## Modular Exponentiation : (a^b)%c , solve using modular exponentiation
> Time Complexity O(log b)
   * [Modular GCD](https://www.codechef.com/problems/GCDMOD)
      * [Solution](https://github.com/ravi-poddar/Competitive-Programming/tree/master/Exponentiation/gcdusingmodulo.cpp)

## Modulo Multiplicative Inverse: (a/b)%c
 To find the modulo inverse of 'b' under modulo 'c'
   * [Using Fermat's little theorem](https://github.com/ravi-poddar/Competitive-Programming/tree/master/Exponentiation/moduloInverseUsingFermat.cpp)
   
   condtions:
      - 'a' and 'c' must be coprime i.e. gcd(a,c)=1
      - 'c' must be be prime
   b^-1 = (b^m-2)%c
   i.e. modulo inverse of 'b' (let sayit 'x') = modExp(b,m-2,c);

   Then, (a/b)%c = (a*x)%c = ((a%c)(b*c))%c


## Matrix Exponentiation
>Time Complexity  O(k^3.logN), k = size of the matrix
