/*
* C Program to Print "Hello World"
*/
#include <stdio.h>
using namespace std;
 

int main(void){
    int test_cases;
    int length;
    int a[110];
    bool isDone;
    int counter;
    bool hasChanged;
    scanf("%d", &test_cases);
    for(int j=0; j<test_cases; j++) {
        isDone=false;
        counter=0;
        scanf("%d", &length);
        for (int k=0; k<length; k++) {
            scanf("%d", &a[k]);
        } 
        while (isDone==false) {
            isDone=true;
            hasChanged=false;
            for (int k=1; (k<length); k++) {
                /* Check if we are done */
                if (isDone==true && a[k]!=0) {
                    isDone=false;
                } 
            }
            for (int k=1; (k<length && hasChanged==false); k++) {
                /* Check 0,x and x,0 cases first as it's atmost 1 */
                if (a[k]==0 && a[k-1] != 0) {
                    a[k-1]=a[k];
                    counter+=1;
                    hasChanged=true;
                    
                } 
                else if (a[k]!=0 && a[k-1] == 0) {
                    a[k]=a[k-1];
                    counter+=1;
                    hasChanged=true;
                    
                } 
            } 
            for (int k=0; (k<length-1 && hasChanged==false); k++) {
                /* Check equal cases second as it's atmost 2 */
                for (int p=k+1; (p<length && a[k]!=0); p++) {
                    if (a[k]==a[p]) {
                        a[p]=0;
                        counter+=1;
                        hasChanged=true;
                        break;
                    }
                }
            } 
            for (int k=1; (k<length && hasChanged==false); k++) { 
                /* Check last as x, y where 1<=x<y is atleast 2*/
                if (a[k-1]<a[k]) {
                    a[k]=a[k-1];
                    counter+=1;  
                    hasChanged=true;  
                    
                }
                else if (a[k-1]>a[k]) {
                    a[k-1]=a[k];
                    counter+=1;
                    hasChanged=true; 
                    
                }
            }    
        }
        printf("%d\n", counter);
        
    }
}
