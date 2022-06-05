// Set ai = aj = |ai-aj|
// Need to prove you can't for some array
// find i and j such that sum of a decreases

// One possible could be where all are negative -1?
// |-1--1| = 0 = aj = ai
//  But negative integers are not permitted.
// 1 5 , a1 = a0 = |5-1| = 4 -> 4 4 which is an inc
// and a0 = a1 = |1-5| = 4 -> inc

// for 1 2 3 4 
// can pick 2 3 -> 1 1 1 4
// ie if you can pick ai, aj such that 
// 2|ai-aj| < ai+aj
// so either 2(ai-aj) < ai+aj -> ai<3aj for ai>=aj
//  oe -2(ai-aj) < ai+aj -> aj<3ai for aj>=ai

// so for counter example we need array where:
//  1 3 9 27 ... 3**(n-1) as you can pick any i and j
//  so you need to satisfy aj>=3ai for any i and j where aj>=ai

// floor(log3 10e9) gives the maximum allowable n

//<- loga x = loge x / loge a
//<- loge a**(loga x) = loge x
//<- loge a**(loga x)/x = 0
//<- a**(loga x)/x = 1
// <- x/x = 1 for x!=0

#include<stdio.h>
#include<math.h>

int main(void) {
    double max_a = 10e9;
    int max_n = (int) floor (log(max_a)/log(3)) - 1;

    int t; 
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        if (n>max_n) {
            printf("NO\n");
        } else {
            printf("YES\n");
            int a = 1;
            for (int j = 0; j < n; j++)
            {
                printf("%d ", a);
                a *=3;
            }
            printf("\n");
        }
    }
    
}