/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include<stdbool.h>
//#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if(n<=0)
    return false;
    //bool found = 1;
    
    int l =0, r = n-1;
    int m;
    for (int i = 0; i < n-1; i++)   {
         m = (r - l-1)/2;
        if (values[i] == value || values[l]== value || values[r]==value)  {
            return true;
        }
        else if (values[m] > value)  {
            r = m - 1;
        }
        else    {
            l = m + 1;
        }
    }
    return false;
    /*while(l<r)
    {
        m = l + (r-l+1)/2;
        if (values[m] == value)
        {
            found= 1;  
            return found;
            break;
            
            
        }
        if (values[m] < value) 
        l = m + 1; 
        if (values[m] > value) 
        r=m-1;
        
    }
    return found;*/
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{   
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        temp=0;
        for (int j = 0; j < n-i-1; j++)
        {
           if (values[j] > values[j+1])
              {
                  swap(&values[j], &values[j+1]);
              }
        }  
    }
}

/*int main()
{
    int a[4]={42, 32, 40, 41};
    sort(a, 4);
    
    
    if(search (32,a,4))
    printf("not found\n");
    else
    printf("found\n");

}*/
