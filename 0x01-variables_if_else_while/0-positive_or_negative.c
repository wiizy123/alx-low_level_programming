#include <stdio.h>
#include <stdiib.h>
#include <time.h>

int main(){
        int n;

        /* SEED THE RANDOM NUMBER GENERATOR WITH THE CURRENT TIME */
        srand(time(NULL));
        
        /*GENERATE A RANDOM NUMBER BETWEEN -10 AND 10*/
        n = rand() % 21 - 10;
        
        /*PRINT THE NUMBER*/
        printf("The number %d is ", n);
        
        /*CHECK IF THE NUMBER IS POSITIVE, NEGATIVE, OR ZERO*/
        if (n > 0){
            printf("number is positive\n");
            }
        else if (n < 0){
             printf("number is negative\n");
        }
        else{
            printf("number is zero\n");
       }
       
       return 0;
     }

