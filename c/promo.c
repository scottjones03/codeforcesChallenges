#include<stdio.h>

int main(void) {
          int n;
          scanf("%d", &n);
          int m;
          scanf("%d", &m);
          int a[n];
          int c;
          int temp;
          for (int j=0; j<n; j++) {
               scanf("%d",&c);
               for (int k=0; k<j; k++) {
                    if (a[k]>c) {
                         temp=a[k];
                         a[k]=c;
                         c=temp;
                    } 
               }
               a[j]=c;
          }
          for (int j=0; j<m; j++) {
               int x;
               int y;
               scanf("%d", &x);
               scanf("%d", &y);
               int free_sum=0;
               for (int k=n-x; k<n-x+y; k++) {
                    free_sum+=a[k];
               }
               printf("%d\n", free_sum);
               
               
          }
     
}
