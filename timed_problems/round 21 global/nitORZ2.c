// mex(S) = smallest +ve int not in S

// n=length of arr, next line=arr (long)

// Operation:select l, r (l<=r) where w=mex([al,...ar]) set al,...ar to w
// destroys <=> ai=0 for all i

// min number of time need to snap fingers

// ie pick biggest region with 0 not in it -> set region to 0
// pick next biggest region -> 0
// number of non-zero groups = number of snaps

#include<stdio.h>
#include<stdbool.h>
int main(void) {
    long long t;
    scanf("%lld", &t);
    for (long long i = 0; i < t; i++)
    {
        long long n;
        scanf("%lld", &n);

        long long non_zero_regions = 0;
        bool was_zero = true;

        long long current_val;
        for (long long j = 0; j < n; j++)
        {
            scanf("%lld", &current_val);
            if (current_val > 0) {
                if (was_zero) {
                    non_zero_regions++;
                    was_zero=false;
                }
            } else {
                was_zero=true;
            }
            
        }
        if (non_zero_regions >= 2) {
            printf("%d\n", 2);
        } else {
            printf("%lld\n", non_zero_regions);
        }
        
    }
    
    
}