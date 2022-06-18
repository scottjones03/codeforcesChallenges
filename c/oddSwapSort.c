// array a1, a2, ..., an
// can swap ai, ai+1 if sum is odd
// can it be sorted?

// if all elements are even,
// we cant change anythin

// Complexity O(n) solution

// for i in array [1:]
// if array[i]<array[i-1] && array[i]+array[i-1] is even 
// -> swap 
// if array[i]<array[i-1] && odd
// -> NO


#include<stdio.h>
#include<stdbool.h>

int main(void) {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        bool notPossible = false;
        int n;
        scanf("%d", &n);

        float last_element;
        float current_element;

        scanf("%f", &last_element);
        for (int i = 1; i < n; i++)
        {
            scanf("%f", &current_element);
            if (last_element > current_element) {
                if ((((long) last_element+ (long) current_element) % 2) == 0) {
                    notPossible = true;
                } else {
                    current_element = last_element;
                }
            }
            last_element = current_element;
        }

        if (notPossible==true) {
            printf("No\n"); 
        } else {
            printf("Yes\n");
        }
        
    }
    
}