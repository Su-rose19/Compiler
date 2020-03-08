#include<bits/stdc++.h>
int main()
{
    FILE *fi,*fo;
    fi=fopen("input.cpp","r");
    fo=fopen("output.txt","w");
    char c;
    while(!feof(fi))
    {
        c=getc(fi);
       if(c=='/')
        {
            c=getc(fi);
            if(c=='/')
            {
                while(c!='\n')
                    c=getc(fi);
            }
            else if(c=='*')
            {
                while(c!='/')
                    c=getc(fi);
            }
            c=getc(fi);
        }
        printf("%c",c);
        fputc(c,fo);
    }
    return 0;
}
