// n= length of array and z
// next line is array

// ai = ai | z and z = ai & z

// say z is zb bits and m is mb bits
// in the arr, either z or m has max number of bits

// 3, 4=11, 100 and z = 11
// 011, 100 and 011 can do 100 | 011 = 111
// 0, 2, 4, 6, 8 = 0000,0010,0100,0110,1000 and z=0101
// 0000,0111,0100,0110,1000 and z=0000
// ie anding can only add zeros to z
// so highest is amax|z

#include<stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        long long z;
        scanf("%lld", &z);

        long long max_val = (long long) 0;
        long long current_val;

        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &current_val);
            if ((current_val | z) >= max_val) {
                max_val = current_val | z;
            }
        }

        // long long res = (long) 39548743 | (long) 13635445;
        printf("%lld\n", max_val);
        
    }
    
}