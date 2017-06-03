#include<stdio.h>
#include<cs50.h>
int main(void)
{
    printf("Minutes:");
    //take input
    int m = get_int();
    //calculate bottles of water
    int w= m*12;
    printf("Bottles: %d\n" , w);
}