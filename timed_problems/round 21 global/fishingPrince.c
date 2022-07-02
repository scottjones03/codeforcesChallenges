// [a1,...,an] and magic m

// op1: if ai % m =0 then replace ai with m copies of ai/m 
// e.g [2, 3], 2, i=1 -> [1, 1, 3]

// op2: if ai=ai+1=...=ai+m-1 then replace all m elements with m*ai

// can her turn a into b using operatiions


// only way to inc size is with op1
// only way to dec is with op2

// go through a and b , 

// if element differs: can we form element from sum of elements at and after i
// are each these elements 

// 3 3 3 3 3 3 3 3
// 9 9 3 3 -> 9 9 1 1 1 1 1 1

// pick every element in a where a % m = 0 and expand
// [1, 11, 11, 1111 1111, 11, 11]
// compare every element with b
// when theres a difference, combine 
// to make m*k
// if element in b is still different
// combine other elements to make m*k
// combine ms to form m**2*k

// split as much as possible for all elements in a
// try to combine to form bi for each b
// 


#include<stdio.h>
#include<stdbool.h>
#include<math.h>


int main(void) {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        int m;
        scanf("%d", &n);
        scanf("%d", &m);

        int a[n];

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[n]);
        }
        
        int k;
        scanf("%d", &k);
        int b[k];

        for (int j=0; j<k; j++) {
            scanf("%d", &b[j]);
        }

        int split_a[n*m];

        int enda = 0;

        for (int _ = 0; _ < 100; _++)
        {
            int split_a[n*m];

            int enda = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[j] % m == 0) {
                    for (int r = enda; r < m; r++)
                    {
                        split_a[r]=a[j]/m;
                    }
                    enda+=m;
                } else {
                    split_a[enda]=a[j];
                    enda++;
                }
                
            }
            if (n==enda) {
                break;
            } else {
                int n = enda;
                int a[n];
                for (int j = 0; j < n; j++)
                {
                    a[j]=split_a[j];
                }
            }
        }


        int split_b[k*m];

        int endb = 0;

        for (int _ = 0; _ < 100; _++)
        {
            int split_b[k*m];

            int endb = 0;
            for (int j = 0; j < k; j++)
            {
                if (b[j] % m == 0) {
                    for (int r = endb; r < m; r++)
                    {
                        split_b[r]=b[j]/m;
                    }
                    endb+=m;
                } else {
                    split_b[endb]=b[j];
                    endb++;
                }
                
            }
            if (k==endb) {
                break;
            } else {
                int k = enda;
                int b[k];
                for (int j = 0; j < k; j++)
                {
                    b[j]=split_b[j];
                }
            }
        }
        if (k==n) {
            for (int j = 0; j < k; j++)
            {
                /* code */
            }
        }
        
        

        
        
        
        
    }
    
}

