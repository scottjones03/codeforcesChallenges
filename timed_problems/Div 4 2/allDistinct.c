// operation: choose 2 distinct indicies i and j and remove ai and aj
// longest array with only distinct integers


// Picture we have 5554444321, 5 unique, 10 el, 5 duplicates
// out: length of final array


#include<stdio.h>


int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        // int u[n][2];
        int u[n];
        int usize=0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
            // printf("%d ", a[j]);
            for (int k = 0; k <= usize; k++)
            {
                if (k==usize) {
                    // u[k][0] = a[j];
                    // u[k][1] = 1;
                    u[k]=a[j];
                    usize++;
                    break;
                } else if (u[k]==a[j]) {
                    // u[k][1]++;
                    break;
                }
            }
        }
        int duplicates = n - usize;
        int unique_arr_length;
        if (duplicates % 2==0) {
            unique_arr_length = n - duplicates;
        } else {
            unique_arr_length = n - (duplicates + 1);
        }
        printf("%d\n", unique_arr_length);

        
    }
    
}