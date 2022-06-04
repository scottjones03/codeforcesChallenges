#include<stdio.h>


int main(void) {
    int n;
    scanf("%d", &n);
    // All factorials are even apart from 1!
    // Even x Even = Even
    //  n=1, then John wins as all Odd
    // n=2, then John picks 1! (+1) Katya choose 2! and 2!x1!=EVEN (0) so DRAW
    // n=3, 1! (+1) 1!2! (0) 1!2! 1!2!3! (-1)   

    // General, n=1 then WIN, n=2 then DRAW, n>2 then LOSE
    if (n==1) {
        printf("Win");
    } else if (n==2) {
        printf("Draw");
    } else {
        printf("Lose");
    }
}