#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

bool same_parity_possible(int n, int * a) {
    int evenIdxs = a[0]%2;
    int oddIdxs = a[1]%2;
    for (int i = 2; i < n; i++)
    {  
        if (i % 2 == 0 && a[i]%2 != evenIdxs) {
            return false;
        } else if (i % 2 == 1 && a[i]%2 != oddIdxs) {
            return false;
        }
    }
    return true;
}
int main(void) {
    int t;

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        int a[n];

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }
        int * p = a;

        if (same_parity_possible(n, p)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
}