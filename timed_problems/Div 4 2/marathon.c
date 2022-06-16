// 4 distinct ints abcd
// a=Timur dis, b,cd=others

// out: num ppl ahead of Timur

#include<stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int a;
        int b;
        int c;
        int d;

        scanf("%d %d %d %d", &a, &b, &c, &d);

        int num_ahead = 0;
        if (b>a) {
            num_ahead++;
        }
        if (c>a) {
            num_ahead++;
        }
        if (d>a) {
            num_ahead++;
        }
        printf("%d\n", num_ahead);
    }
    
}