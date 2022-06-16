// n tasks, s given and unique for each, f given and work out d
// completed in order

// given all the start and finish times
#include<stdio.h>
#include<math.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        long s[n];
        long f[n];

        long duration;
        long time=(long) 0;

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &s[j]);
        }
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &f[j]);
        }
        for (int j = 0; j < n; j++)
        {
            if (time<s[j]) {
                duration = f[j]-s[j];
            } else {
                duration = f[j]-time;
            }
            printf("%d ", duration);
            time = f[j];
        }
        printf("\n");
        
        

    }
    
}
