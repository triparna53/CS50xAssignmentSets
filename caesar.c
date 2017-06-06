#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc != 2 || argv[2] != NULL)
    {
        printf("Error!\n");
        return 1;
        
    }
    else{
    //convert console input to integer value of key    
    int k= atoi(argv[1]);
    if(k>25)
    {
        k=k%26;
    }
    //printf ("%d\n", k);
    printf("plaintext:");
    string s = get_string();
    if (s != NULL)
    {   printf("ciphertext: ");
        char c=' '; int v=0;
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) )
            {
                v=((int)s[i]+k);
            
            if(v>90 && v<97)
            {
                v=(v-90)+64;
            }
            if(v>122)
            {
                v=(v-122)+96;
            }
            c=(char)v;
            printf("%c", c);
            v=0;
        }
         else printf("%c", s[i]);   
        
    }
    printf("\n");
}
return 0;
}
}