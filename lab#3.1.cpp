#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int f ,cnt;
    while(cin>>s)
    {
        f = 0;cnt = 1;
        if((s[0]>='A' && s[0]<='Z') || (s[0]>='a' && s[0]<='z') || s[0]=='_' )
        {

            for(int i=1; i<=s.size(); i++)
            {
                if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || s[i]=='_' || (s[i]>='0' && s[i]<='9') )
                {
                    cnt++;
                }
            }
            if(cnt==s.size())
            {
                f = 1;
            }

        }
        else
        {
            f = 0;
        }
        if(f==0)
        {
            printf("Invalid identifier\n");
        }
        else
        {
            printf("Valid identifier\n");
        }
        s.clear();
    }


    return 0;
}

