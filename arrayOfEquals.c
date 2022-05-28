#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int main (void) {
    int test_cases;
    int sum_of_case;
    int size_of_case;
    bool result;
    double mean;
    scanf("%d", &test_cases);
    for (int i=0; i < test_cases; i++) {
        scanf("%d", &size_of_case);
        sum_of_case=0;
        result=false;
        int test_case[size_of_case];
        for (int j=0; j < size_of_case; j++) {
            scanf("%d", &test_case[j]);
            sum_of_case+=test_case[j];
        }
        mean = (double) sum_of_case / size_of_case;
        for (int j=0; j<size_of_case; j++) {
            if (test_case[j]==mean) {
                result=true;
            }
        }
        if (result==true) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    
}
