# Fibonacci numbers are a series of numbers in which each number is the sum of the two preceding numbers .

#### You will be given three numbers X , Y , N . You have to find F(n).

         F(0) = X
         F(1) = Y
         F(i) = F(i-1) + F(i-2) for i>=2
Since the number can be very large , output it modulo 10^9 + 7 .

#### Input Format

The first line of input contains T , the total number of test cases .

T lines follow each containing 3 inputs X , Y , N .

#### Constraints

1 <= T <= 10^9

1 <= X , Y , N <= 10^9

#### Output Format

For each test case print F(n) .

#### Sample Input 0

                  8
                  2 3 1
                  9 1 7
                  9 8 3
                  2 4 9
                  1 7 2
                  1 8 1
                  4 3 1
                  3 7 5

#### Sample Output 0

                  3
                  85
                  25
                  178
                  8
                  8
                  3
                  44
