#include <stdio.h>

int LENGTH =6;
typedef enum {true, false} bool;

bool isGood(void) {
    int el;
    int sum;
    for (int i=0; i<LENGTH; i++) {
        scanf("%1d", &el);
        if (i<LENGTH/2) {
            sum+=el;
        }
        else {
            sum-=el;
        }
    }
    return (sum==0);
}
int main(void) {
    int test_cases;
    scanf("%d", &test_cases);
    for (int i=0; i<test_cases; i++) {
        if (isGood()) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}
