#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s =  "int main()    \n"
                "{      \n"
                "//this a simple program    \n"
                "   printf(\"hello world\");    \n"
                "   /*this is        \n"
                "   a comment   \n"
                "   in the program */   \n"
                "}      \n";

    int a=0,b=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='/' && s[i+1]=='/')
        {
            a = 1;
            i++;
        }
        else if(a==1 && s[i]=='\n')
        {
            a = 0;
        }
        else if(s[i]=='/' && s[i+1]=='*')
        {
            b = 1;
            i++;
        }
        else if(b==1 && s[i]=='*' && s[i+1]=='/')
        {
            b = 0;
            i++;
        }
        else if(a==1 || b==1)
        {
            continue;
        }
        else
        {
            cout<<s[i];
        }

    }
    cout<<endl;

    return 0;
}
