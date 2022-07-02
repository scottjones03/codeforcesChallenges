// 2**n athletes 1 to 2**n

// athlete plays another and one wins other eliminated
// Winner of 1 match and 2 match play
// -> winner of i and i+1 play for i=2k where k>=1

// if x+y odd -> lower index wins
// else higher index wins

// R1
// 2k+1 plays 2k+2 for all k>=0
// x+y=(2k+1)+(2k+2)=4k+3 -> odd -> 2k+1 wins

// R2
// 2k+1 plays 2(k+1)+1=2k+3
// x+y=4k+4 -> even -> 2k+3 wins

// R3
// 2k+3 plays 2(k+2)+3=2k+7
// x+y=4k+10 -> even -> 2k+7 wins

// R4
// 2k+7 plays 2(k+3)+7

// create array of length 2^(a+1), work out winner in each case.

// For all R1, 2k+1 plays 2k+2 -> lower wins (2k+1)
// For all R2, 2(k1)+1 plays 2(k2)+1 -> higher wins (2(k2)+1)
// Assume for all Ry, higher wins (2(ky)+1)
// For all R(y+1), 2(ky)+1 plays 2(k(y+1))+1 -> higher 2(k(y+1))+1 wins

// -> answer always 2**n -1


#include<stdio.h>
#include<math.h>


int t;
long n;
long natheletes;
int main(void) {
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%Ld", &n);
        natheletes = (long) powl((long double) 2, (long double) n) - (long) 1;
        printf("%Ld\n", natheletes);
    }
    
}