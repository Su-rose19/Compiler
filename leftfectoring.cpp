#include<bits/stdc++.h>
using namespace std;
struct s
{
    string nt;
    string pro;
} cfg[10];
int n;
int main()
{
    int i,k;
    printf("enter no of production: ");
    cin>>n;
    string s;
    for(k=1; k<=n; k++)
    {
        cin>>s;
        cfg[k].nt=s.substr(0,1);
        cfg[k].pro=s.substr(3);
    }
    for(k=1; k<=n; k++)
    {
        string s1[10];
        int p=0;
        int j=1;
        for(i=0;i<cfg[k].pro.length(); i++)
            if(cfg[k].pro[i]=='|')
            {
                s1[j]=cfg[k].pro.substr(p,i-p);
                j++;
                p=i+1;
            }
        if(j==1)
            cout<<cfg[k].nt<<"->"<<cfg[k].pro<<endl;
        else if(s1[1][0]!=s1[2][0])
             cout<<cfg[k].nt<<"->"<<cfg[k].pro<<endl;
        else{
            s1[j]=cfg[k].pro.substr(p);
            cout<<cfg[k].nt<<"->";
            for(i=0; i<s1[1].length(); i++)
            {
                if(s1[1][i]==s1[2][i])
                {
                    cout<<s1[1][i];
                }
                else
                    break;
            }
            cout<<cfg[k].nt<<"\'|"<<s1[3]<<endl;
            j=i;
            cout<<cfg[k].nt<<"\'->";
            for(i=j; i<s1[1].length(); i++)
                cout<<s1[1][i];
            if(j==s1[1].length())
                printf("$");
            printf("|");
            for(i=j; i<s1[2].length(); i++)
                cout<<s1[2][i];
            if(j==s1[2].length())
                printf("$");
            printf("\n");
        }
    }
    return 0;
}
