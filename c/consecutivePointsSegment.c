// n distinct coordinates given in strictly increasing order
// can do once: move by x-=1 or x+=1
// want to form, l, l+1, l+2, ..., l+n-1


// given points x(i-1), x(i)

// if x(i)==x(i-1), can do x(i-1), x(i)+1 OR x(i-1)-1, x(i)
// else if x(i)==x(i-1)+1, we are done OR x(i-1)-1, x(i)-1 OR x(i-1)+1, x(i)+1
// else if x(i)==x(i-1)+2, can do x(i-1), x(i)-1 OR x(i-1)+1, x(i)
// else if x(i)==x(i-1)+3, can do x(i-1)+1, x(i)-1
// else NO

// If we went through the loop from start, making x(i-1)+1==x(i)
// we constraint ourselves to l=x(0)+-1 but this is fine.

// should run through each possible cases 
// until one passes or none passes: l=x(0)-1, l=x(0), l=x(0)+1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool is_possible(int l, int n ,int * x) {
    int x_copy[n];
    for (int i = 0; i < n; i++)
    {
        x_copy[i]=x[i];
    }
    x_copy[0] = l;
    for (int j = 1; j < n; j++) {
        if (x_copy[j]==x_copy[j-1]) {
            x_copy[j]+=1;
        } else if (x_copy[j]==x_copy[j-1]+1) {
            continue;
        } else if (x_copy[j]==x_copy[j-1]+2) {
            x_copy[j]-=1;
        } else {
            x_copy[j]-=100;
            return false;
        }
    }
    return true;
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int x[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &x[j]);
        }
        bool res=false;
        int l_start = x[0]-1;
        int * px = x;
        for (int l = l_start; l<l_start+3; l++) {
            if (is_possible(l, n, px)) {
                res=true;
            }
        }
        if (res) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }        
    }
    
}