#include <cs50.h>
#include <stdio.h>
#include<math.h>
int main(void)
{
    float f;
    printf("O hai!");
    //take input
    do
    {
        printf("How much change is owed?\n");
        f= get_float(); 
    } while (f<0);
   int n=0;
    //convert to integer
   float  x=(f*100.0);
   int p= (int)x;
   
    //greedy algorithm implemented
    while(p>0)
    {
     if(p>=25)
        {
         n+=(p/25);
         
         p%=25;
        }
     if(p>=10 && p<25)
        {
         n+=(p/10);
         
         p%=10;
        }
     if(p>=5 && p<10)
        {
         n+=(p/5);
         
         p%=5;
        }
     if(p>=1 && p<5)
        {
         n+=p;
         
         break;
        }
    
    }
    printf("%d\n", n);
}

    