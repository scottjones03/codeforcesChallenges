#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int test_cases;
    int l1;
    int r1;
    int l2;
    int r2;
    scanf("%d", &test_cases);
    for (int i=0; i<test_cases; i++) {
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if (l2 <= l1 && l1 <= r2) {
            printf("%d", l1);
        } else if (l1 <= l2 && l2 <= r1) {
            printf("%d", l2);
        } else {
            printf("%d", l1+l2);
        }
        printf("\n");
    }
}
