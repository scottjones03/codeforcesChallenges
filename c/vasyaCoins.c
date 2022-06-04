#include<stdio.h>


// a coins of 1burie, b of 2burie
// s = minimum positvie integer at which he 
// would would need change

// Given x a and y b , 
// can make buries 1, 2, ..., x
// can make buries 1+2, 2+2, ..., x+2
// can make buries [1, 1+2, 1+4, ..., 1+2*y], [2, 2+2, 2+4, ..., 2+2*y], ..., [x, x+2, x+4, ..., x+2*y]
// can be reordered:

// [1, 2, ..., x], [3, 4, ..., x+2], [5, 6, ..., x+4], ... , [2y, 2y+1, ..., 2y+x]

// so if 2y <= 2(y-1)+x , then we can go up to 2y+x, s=2y+x+1

// so if 2y > 2(y-1)+x, 2>x
// is 2(y-1) > 2(y-2)+x? Well 2>x in this case, so yes.
// when x=1, y=1 we can make 1, 2, 3 but not 4
// so s=y*2
// when x=0, we can't make 1 -> s=1

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int a;
        int b;
        scanf("%d", &a);
        scanf("%d", &b);    
        int s;
        if (a>=2) {
            s = 2*b+a+1;
        } else if (a==1) {
            s = 2*(b+1);
        } else {
            s = 1;
        }
        printf("%d\n", s);
    }
    
}