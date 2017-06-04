#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
int main(void)
{   
     string s = get_string();
     //print first character
     printf("%c", toupper(s[0]));
    if (s != NULL)
    {
        //trace through each character in string
        for (int i = 1, n = strlen(s); i < n; i++)
        
        {   //check for space
            if((int)s[i]==32)
            printf("%c", toupper(s[i+1]));
        }
        printf("\n");
    }
}
