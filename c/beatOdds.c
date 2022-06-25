// min number of elemnets to remove

// ak+a(k+1) % 2 == 0
// O + O = E, E+O=O, E+E=E
// ie need to remove all EOs

// Can have EEE...EE, or OO...OO but not EEE...EOO...OOO
// ie all even or all odd and nothing else

// count number of evens and number of odds
// if evens > odds then remove all odds
// else remove all evens (O(n) which is optimal)

#include<stdio.h>


int t;
int n;

int main(void) {
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        long a;
        int num_evens = 0;
        int num_odds = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%ld", &a);
            if (a % ((long) 2) == 0) {
                num_evens++;
            } else {
                num_odds++;
            }
        }
        if (num_evens >= num_odds) {
            printf("%d\n", num_odds);
        } else {
            printf("%d\n", num_evens);
        }
        
        
        
    }
        
}