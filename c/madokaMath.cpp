// Find max decimal number without zeros ans no equal digits
// sum of digits must be n

// since it is in digits, we want to maximise
// the number of digits rather than the digits themselves
// alternate between 1 and 2?
// floor(n/3) is number of consecutive 1,2 and n mod 3 determines the remainder
// if n mod 3 = 0, then 2121...21
// if n mod 3 =1 then 12121...21
// if n mod 3 = 2 then 2121...212


#include<stdio.h>
#include<math.h>
using namespace std;

int t;
int n;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    int num12;
    int remainder;
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        num12 = n /3;
        remainder = n % 3;
        if (n%3==1) {
            printf("1");
        }
        for (int j = 0; j < n/3; j++)
        {
            printf("21");
        }
        if (n%3==2) {
            printf("2");
        }
        printf("\n");
    }
    
}