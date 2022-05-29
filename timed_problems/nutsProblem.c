#include<stdlib.h>
#include<stdio.h>

int main(void) {
    int n;
    int x;
    int k;
    int current_idx;
    int sum_allowed=0;
    scanf("%d", &n);
    scanf("%d", &x);
    int types_of_nuts_arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &types_of_nuts_arr[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &current_idx);
        sum_allowed+=types_of_nuts_arr[current_idx-1];
    }
    printf("%d", x-(sum_allowed-1));    
}