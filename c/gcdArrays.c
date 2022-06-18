// array of integers from l to r shuffled
// Operation: choose 2 numbers, remove one occurrence for each of them
// ie remove both numbers & replace with product
// gcd(arr)=greatest common divisor of integers
// we need gcd(arr) > 1, given l, r and k operations: 

// [3, 4, 5, 6, 7]
// 4,6 divisible by 2, 3,6 divisible by 3 and 5,7 
// Pick largest set (probably 2 or 3)
// Operate on everything out the set: 3,5,7 in our case

// For set n, there's atleast floor(n/i) items divisible by i
// and atmost ceil(n/i) items divisible by i

// If floor(n/i)<1, then ceil(n/(i+1))==1
// Floor when n%i!=0 and start with not divisible (3,4,5)
// Ceil when n%i!=0 and start with divisible (4,5,6)

// For l=r, no operation is needed if l!=1 else No.
// For l<r, y operations are needed. y<=r-1


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        long l;
        long r;
        long k;
        scanf("%ld", &l);
        scanf("%ld", &r);
        scanf("%ld", &k);

        long n = r-l+1;
        // printf("%ld", n);
        if (n==1) {
            if (l==1) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        } else {
            long twoSet;
            long threeSet;
            if (n % 2 != 0) {
                if (l % 2 != 0) {
                    twoSet = n / 2;
                } else {
                    twoSet = n / 2 + 1;
                }
            } else {
                twoSet = n /2;
            }
            if (n % 3 != 0) {
                if (l % 3 != 0) {
                    threeSet = n / 3;
                } else {
                    threeSet = n / 3 + 1;
                }
            } else {
                threeSet = n / 3;
            }
            long y;
            if (twoSet > threeSet) {
                y = n - twoSet;
            } else {
                y = n - threeSet;
            }
            // printf("%d %d %d", y, twoSet, threeSet);
            if (k >= y) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    
}
