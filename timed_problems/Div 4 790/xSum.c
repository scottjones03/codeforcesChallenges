#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        int m;
        scanf("%d %d", &n, &m);
        int board[n][m];
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                scanf("%d", &board[j][k]);
            }
        }
        int max_sum=0;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {   
                int sum = board[j][k];
                bool did_add = true;
                for (int q = 1; q < m && did_add==true ; q++)
                {
                    did_add = false;
                    if (j-q>=0 && k-q>=0) {
                        sum+=board[j-q][k-q];
                        did_add = true;
                    } 
                    if (j-q>=0 && k+q<m) {
                        sum+=board[j-q][k+q];
                        did_add=true;
                    }
                    if (j+q<n && k-q>=0) {
                        sum+=board[j+q][k-q];
                        did_add=true;
                    }
                    if (j+q<n && k+q<m) {
                        sum+=board[j+q][k+q];
                        did_add=true;
                    }
                    
                }
                if (sum>max_sum) {max_sum=sum;}
            }
            
        }
        printf("%d\n", max_sum);
        
        
    }
    
}