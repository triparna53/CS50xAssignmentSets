#include <cs50.h>
#include <stdio.h>
int main(void)
{
 int h;
 do
    {
    printf("Height:");
    h = get_int();
    } while (h<0 || h >23);
    {
        int n=h-1;
        for (int k=0; k<h; k++)
        {
            for(int i=n-k; i>=0; i--)
            {
                printf(" ");
            }
            for( int j= 0; j<k+2; j++)
            {
                printf("#");
            }
        
        printf("\n");
        }
    }
    
}