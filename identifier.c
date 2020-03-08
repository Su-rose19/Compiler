#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    freopen("Checking_Identifier_In.txt","r",stdin);
    freopen("Checking_Identifier_Out.txt","w",stdout);
    char keyword[][10]={"auto","break","case","char","const","continue","default","printf", "double",
                         "else","enum","extern","float","for","goto","if","int","do", "long","register",
                         "return","short","signed","sizeof","static","struct","switch","typedef","union",
                         "unsigned","void","volatile","while"};

    char str[1000];
    int i,flag;
    while(gets(str)!='\0')
    {
        getchar();
        flag=0;
        i=0;
        int l=strlen(str);
        for(i=0;i<=32;i++)
            {
                if(strcmp(keyword[i],str)==0)
                {

                    flag=3;
                }

            }
        if(flag==3) flag=2;

       else if(isdigit(str[0]))
        {
                flag=2;
        }

        else if(isalpha(str[0])||str[0]=='_')

        {

            for(i=0;i<l;i++)
        {
            if(isalpha(str[i])||str[i]=='_'||isdigit(str[i])) flag=1;
            else {flag=2;break;}
        }
        }

        if(flag==1)
           printf("%s is valid identifier\n",str);
        else if(flag==2)
           printf("%s is invalid identifier\n",str);

    }
}
