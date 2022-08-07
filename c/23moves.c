#include<stdio.h>
#include<stdlib.h>

int main(void) {
    // let x be point we want to get to
    // x = 2p+3q for any p,q integers
    // Minimise number of mins by maximising qs magnitude
    // x could be 3q, 3q-2, 3q+2 -> 3q, 3(q-1)+1, 3q+2
    // if x mod 3 = 0 , then x/3
    // if x mod 3 = 1, then x=3(quo(x/3)-1)+2*2 then quo(x/3)+1
    // if x mod 3 = 2, then x=3quo(x/3)+2 then quo(x/3)+1
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        long x;
        scanf("%Ld", &x);
        long q = x/((long) 3);
        long r = x - ((long) 3)*q;
        
        long mins;
        if (r==0) {
            mins=q;
        } else if (r==1) {
            if (q==0) {
                mins=((long) 2);
            } else {
                mins=q+((long) 1);
            }
        } else {
            mins=q+((long) 1);
        }
        printf("%Ld\n", mins);


    }
}