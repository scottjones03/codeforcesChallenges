#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        
        int first_maximum = 0;
        int second_maximum = 0;
        int val;
        for (int j = 0; j < n; j++)
        {   
            scanf("%d", &val);
            if (val>first_maximum) {
                second_maximum=first_maximum;
                first_maximum=val;
            } else if (val > second_maximum) {
                second_maximum=val;
            }
        }
        
        if (first_maximum<second_maximum+2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
        
        
        
    }
    
}