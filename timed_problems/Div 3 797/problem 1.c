// need to use n blocks to build pedestal
// 3 cols , 2nd 1st and 3rd place, each strictly higher than other
// height of each must be greater than zero
// want to minimise 1st place height

// to minimise 1st place, we need to maximise 2nd and 3rd
// h1 = h2+1, h2 = h3+1
// n = h1+h2+h3 = h2+1+h2+h3= 3*h3 + 3, so h3 = (n-3)/3
// n = 3*h2 , h2 = n/3
// if h2 = floor(n/3) = n/3 - (n mod 3)/3
// n = n - n mod 3 + x - 1, so x = n mod 3 + 1, h1 = n/3 + 2*(n mod 3)/3+1
// else if h2 = ceil(n/3) = n/3 + (1 - (n mod 3)/3)
// n = n + 3 - n mod 3 + 1 - y, ie h1 = n/3 + 2 - n mod 3 / 3

#include<stdio.h>
#include<math.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int idx = 0; idx < t; idx++)
    {
        float n;
        scanf("%f", &n);
        int h1;
        int h2;
        int h3;

        int intPart;
        int nMod3;
        
        nMod3 = (int) n % 3;
        intPart = (int) floor (n/3);
        if (nMod3 == 0) {
            h1 = intPart + 1;
            h2 = intPart;
            h3 = intPart - 1;
        } else {
            if (nMod3 + 1 <= 2 ) {
                h2 = intPart;
                h3 = intPart-1;
                h1 = intPart + nMod3 + 1;
            } else {
                h2 = intPart + 1;
                h1 = intPart + 2;
                h3 = intPart - 3 + nMod3;
            }
        }
        printf("%d %d %d\n", h2, h1, h3);
    }
    
}