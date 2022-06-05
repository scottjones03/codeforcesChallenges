// Need to replace n tires
// there 2 bus types one with 4 wheels and one with 6
// determine min and max number of buses

// e.g if n =12, min=2, max=3
// e.g. if n=11, -1 as can't make 11 from 4 and 6
// n must be even >= 4, 
// n==2k where k>=2 and n==4*k1+6*k2,
// then k==2*k1+3*k2
// if we set k2=0, k == 2*k1, so k can be any positive even>=2
// if we ket k2=1, k==2*k1+3==2*(k1+1)+1, so k can be any positive odd>=3
// so k is any integer>=2, which means n is all evens>=4

// max is when n==4*k1+6*k2==4*(k1+k2)+2*k2 where k2=[0, 1]
// if n mod 4 == 0 then k2 = 0 then k1+k2 = n/4
// else (n-2) mod 4 == 0 then k2 = 1 then k1+k2 = (n-2)/4

// min is when n==6*(k2+k1)-2*k1 where k1=[0,1,2]
// if n mod 6 == 0 then k1 = 0 then k1+k2=n/6
// else (n+2) mod 6 == 0 then k1 = 1 then k1+k2 = (n+2)/6
// else (n+4) mod 6 == 0  then k1 = 2 then k1+k2 = (n+4)/6



#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        float n;

        scanf("%f", &n);

        float i, f;
        f = modf(n/2, &i);
        if (f != 0 || n < 4) {
            printf("-1\n");
        } else {
            float max_buses;
            for (int j = 0; j < 2; j++)
            {
                float i, f;
                f = modf((n-2*j)/4, &i);
                if (f==0)
                {
                    max_buses = (n-2*j)/4;
                    break;
                }
            }
            float min_buses;
            for (int j = 0; j < 3; j++)
            {
                float i, f;
                f = modf((n+2*j)/6, &i);
                if (f==0)
                {
                    min_buses=(n+2*j)/6;
                    break;
                }
            }
            
            printf("%.0f %.0f\n", min_buses, max_buses);
        }
    }
    
}