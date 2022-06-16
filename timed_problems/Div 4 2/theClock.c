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

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int num_palindromes = 0;

        char test_case[5]; 
        scanf("%s", test_case);

        int ih1 = (int) test_case[0] - 48;
        int ih2 = (int) test_case[1] - 48;
        int im1 = (int) test_case[3] - 48;
        int im2 = (int) test_case[4] - 48;
        int h1 = (int) test_case[0] - 48;
        int h2 = (int) test_case[1] - 48;
        int m1 = (int) test_case[3] - 48;
        int m2 = (int) test_case[4] - 48;
        

        if (h1 == m2 && h2 == m1) {
            num_palindromes++;
        }

        int step;
        scanf("%d", &step);

        int hours_step = step / 60;
        int minutes_step = step % 60;
        // printf("%d %d\n", hours_step, minutes_step);

        int hours = h1*10+h2;
        int minutes = m1*10+m2;

        for (int j = 0; j < 1440; j++)
        {
            hours=(hours+hours_step + (minutes+minutes_step)/60) % 24;
            minutes = (minutes+minutes_step) % 60;

            // printf("%d %d\n", hours, minutes);

            int h1 = hours / 10;
            int h2 = hours % 10;
            int m1 = minutes / 10;
            int m2 = minutes % 10;
            
            if (h1 == ih1 && h2 == ih2 && m1 == im1 && m2 == im2) {
                break;
            } else if (h1 == m2 && h2 == m1) {
                // printf("%d %d %d %d\n", h1, h2, m1, m2);
                num_palindromes++;
            }
        }
        printf("%d\n", num_palindromes);
        
    }
    
}