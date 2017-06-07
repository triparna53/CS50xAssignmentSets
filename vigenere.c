
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{
    if(argc != 2 || argv[2] != NULL)
    {
        printf("Error!\n");
        return 1;
        
    }
    
    else{
        string k=argv[1]; 
        int n= strlen(k); int x=0;
        for(int i=0; i<n; i++ ){
        if((k[i]>=65 && k[i]<=90) || (k[i]>=97 && k[i]<=122) )
        {
            x++;
        
        }
        
        }   
        if(x!=n)
        {
            printf("Error!\n");
            return 1;
            
           
        }
        if(x== n){
        printf("plaintext: ");
        
        string s= get_string();
        //int a[]= new int(n);
        if(s!=NULL)
        {
            //covert cipher to int value
            int *p= (int*)malloc(sizeof(int)*n);
            for(int i=0; i<n; i++)
            {
                p[i]= (int)((toupper(k[i]))-65);
                //printf("%d" ,p[i]);
            }
            printf("ciphertext: ");
            int v=0;
            //encrypt only alphabets
            for(int i=0, counter=0, m= strlen(s); i<m; i++)
            {
            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) )
            {
                if(isupper(s[i]))
                //
                {
                v=(int)s[i]+p[(i-counter)%n];
                    //roll over ending alphabets
                    if(v>90) 
                    {
                    v=(v-90)+64;
                    }
                     s[i]= (char)v;
                }
                if(islower(s[i]))
                //if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) )
                {
                v=(int)s[i]+p[(i-counter)%n];
                    if(v>122)
                    {
                    v=(v-122)+96;
                    }
               s[i]= (char)v;
                }
                printf("%c", s[i]);
                }
            
               else
               {
                counter++;
                printf("%c", s[i]);
               }
            }
        }
    
        printf("\n");
        }
    }
         return 0;
}
