#include<stdio.h>
#include<stdlib.h>


int main(void) {
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        int n;
        scanf("%d", &n);

        int max[4] = {0, 0,0,0};

        int x;
        int y;

        for (int j=0; j<n; j++) {
            scanf("%d", &x);
            scanf("%d", &y);
            if (x==0) {
                if (y < max[1]) {
                    max[1]=y;
                } else if (y > max[3]) {
                    max[3]=y;
                }
            } else {
                if (x < max[0]) {
                    max[0]=x;
                } else if (x > max[2]) {
                    max[2]=x;
                }
            }
        }

        int total_moves = 2*(-max[0]-max[1]+max[2]+max[3]);
        printf("%d\n", total_moves);
    }
}