#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool isPalindrome(int string_length, char * test_case) {
    // if 2k then compare [0, 2k-1], [1, 2k-2], ..., [k-1, k]
    // if 2k+1 then compare [0, 2k], [1, 2k-1], ..., [k-1, k+1], [k, k]
    int k;
    if (string_length % 2 == 0) {
        k = string_length / 2;
        for (int i=0; i<k; i++) {
            if (test_case[i] != test_case[2*k-(i+1)]) {
                return false;
            }
        }
    } else {
        k = (string_length-1) / 2;
        for (int i=0; i<k; i++) {
            if (test_case[i] != test_case[2*k-i]) {
                return false;
            }
        }
    }
    return true;
}
char * removeCharAtIdx(int string_length, char * test_case, int delIdx) {
    char *new_string = malloc(string_length-1);
    int idx = 0;
    for (int i=0; i<string_length; i++) {
        if (i!=delIdx) {
            new_string[idx]= test_case[i];
            idx+=1;
        }
    }
    return new_string;
}
int main(void) {
    int test_cases;
    int string_length;
    int num_palindromes;
    scanf("%d", &test_cases);
    for (int i=0; i<test_cases; i++) {
        scanf("%d", &string_length);
        num_palindromes = 0;
        char test_case[string_length]; 
        char *temp_case;
        scanf("%s", test_case);
        for (int j=0; j<string_length; j++) {
            temp_case = removeCharAtIdx(string_length, test_case, j);
            if (isPalindrome(string_length-1, temp_case)==true) {
                num_palindromes+=1;
            }
        }
        printf("%d\n", num_palindromes)
    }
}
