#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int * getDigits(int n) {
    int power_result;
    int *out = malloc(10);
    for (int i=9; i >= 0; i--) {
        power_result = (int) pow((double) 10, (double) i);
        if (power_result <= n) {
            out[i] = (int) floor((double) n / power_result);
            n = n % power_result;
        } else {
            out[i]=0;
        }
       
    }
    return out;
}
int main(void) {
    int test_cases;
    int test_case;
    int min_d;
    int length;
    test_cases = 2;
    //scanf("%d", &test_cases);
    for (int i = 0; i < test_cases; i++) {   
        length=0;
        min_d=10;
        /* test case */
        test_case = 213;
        //scanf("%d", &test_case);
        int *test_case_arr = getDigits(test_case);
        for (int j = 0; test_case_arr[j]!=0; j++) {
            length+=1;
            if (test_case_arr[j] < min_d) {
                min_d=test_case_arr[j];
            }
        }
        if (length == 2) {
            // Must always swap the minimum
            printf("%d\n", test_case_arr[0]);
        } else {
            // Don't need to swap the minimum
            printf("%d\n", min_d);
        }
        free(test_case_arr);
        
    }
}
    