#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int st=0;
    char input[20];
    printf("Enter String:");
    scanf("%s",input);
    for(int i=0;input[i]!='\0';i++)
    {
        switch(st)
        {
            case 0:
                if(input[i]=='a')
                {
                    st=1;
                }
                else if(input[i]=='b')
                {
                    st=3;
                }
                else
                {
                    printf("Invalid");
                    exit(0);
                }
            break;
            case 1:
                if(input[i]=='a')
                {
                    st=0;
                }
                else if(input[i]=='b')
                {
                    st=2;
                }
                else
                {
                    printf("Invalid");
                    exit(0);
                }
            break;
            case 2:
                if(input[i]=='a')
                {
                    st=3;
                }
                else if(input[i]=='b')
                {
                    st=1;
                }
                else
                {
                    printf("Invalid");
                    exit(0);
                }
            break;
            case 3:
                if(input[i]=='a')
                {
                    st=2;
                }
                else if(input[i]=='b')
                {
                    st=0;
                }
                else
                {
                    printf("Invalid");
                    exit(0);
                }
            break;
        }
    }
    if(st==0)
    {
        printf("String Accepted");
    }
    else
    {
        printf("Not Accepted");
    }
    return 0;
}
