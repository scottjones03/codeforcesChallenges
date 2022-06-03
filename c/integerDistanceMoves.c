// 0,0 to x,y via integer cartesian distances
// if 0,0 then 0 move
// else if sqrt(x**2+y**2) is int, 1 move
// else can do x then y which is 2 move

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void) {
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        int x;
        int y;
        scanf("%d %d", &x, &y);
        int moves;
        if (x==0 && y==0) {
            moves=0;
        } else if (
            floor(sqrt(pow(x, 2)+pow(y, 2)))==sqrt(pow(x, 2)+pow(y, 2))
        ) {
            moves=1;
        } else {
            moves=2;
        }
        printf("%d\n", moves);
    }
}
