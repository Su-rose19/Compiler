#include<bits/stdc++.h>
using namespace std;
struct
{
    string nt,pro;
} g[10];
int n,m;
char flw[100];
void follow(char c);
void first(char c);
void addrslt(char c);
void check(char k)
{
    int i,l,j;
    for(i=1; i<=n; i++)
    {
        if(g[i].nt[0]==k)
        {
            l=g[i].pro.length();
            for(j=0; j<l; j++)
            {
                if(j==0)
                    if(g[i].pro[j]>='A'&&g[i].pro[j]<='Z')
                        check(g[i].pro[j]);
                    else
                        printf("%c, ",g[i].pro[j]);
                else if(g[i].pro[j-1]=='|')
                    if(g[i].pro[j]>='A'&&g[i].pro[j]<='Z')
                        check(g[i].pro[j]);
                    else
                        printf("%c, ",g[i].pro[j]);
            }
        }
    }
}
void addrslt(char c)
{
    int i;
    for(i=0; i<m; i++)
        if(flw[i]==c)
            return;
    if(c!='&'&&c!='|')
        flw[m++]=c;
}
void follow(char c)
{
    int j,i,l;
//   printf("%c ",c);
    if(c==g[1].nt[0])
        addrslt('$');
    for(i=1; i<=n; i++)
    {
        l=g[i].pro.length();
        for(j=0; j<l; j++)
            if(g[i].pro[j]==c)
            {
                if(((j+1)==l||g[i].pro[j+1]=='|')&&c!=g[i].nt[0])
                {
                    //   printf("%c",g[i].nt[0]);
                    follow(g[i].nt[0]);
                }
                else
                {
                    first(g[i].pro[j+1]);
                }
            }
    }
}
void first(char c)
{
    if(!isupper(c)&&c!='|'&&c!='&')
        addrslt(c);
    int i,l,j;
    for(i=1; i<=n; i++)
    {
        l=g[i].pro.length();
        if(g[i].nt[0]==c)
        {
            for(j=0; j<l; j++)
            {
                if(j==0)
                {
                    if(isupper(g[i].pro[j]))
                        first(g[i].pro[j]);
                    else
                        addrslt(g[i].pro[j]);
                }
                else if(g[i].pro[j-1]=='|')
                {
                    if(g[i].pro[j]=='&')
                        follow(g[i].nt[0]);
                    if(isupper(g[i].pro[j]))
                        first(g[i].pro[j]);
                    else
                        addrslt(g[i].pro[j]);
                }

            }
        }
    }
}

int main()
{

    printf("enter no of production: ");
    scanf("%d",&n);
    string s;
    int i,j,l;
    for(i=1; i<=n; i++)
    {
        cin>>s;
        g[i].nt=s.substr(0,1);
        g[i].pro=s.substr(3);
    }
    printf("\nFirst:\n");
    for(i=1; i<=n; i++)
    {
        printf("frist of %c : { ",g[i].nt[0]);
        l=g[i].pro.length();
        for(j=0; j<l; j++)
        {
            if(j==0)
                if(g[i].pro[j]>='A'&&g[i].pro[j]<='Z')
                    check(g[i].pro[j]);
                else
                    printf("%c, ",g[i].pro[j]);

            else if(g[i].pro[j-1]=='|')
                if(g[i].pro[j]>='A'&&g[i].pro[j]<='Z')
                    check(g[i].pro[j]);
                else
                    printf("%c, ",g[i].pro[j]);
        }
        printf("}\n");
    }
    printf("\nFollow:\n");
    int p,k,cnt=0;
    for(i=1; i<=n; i++)
    {
        m=0;
        printf("frist of %c : { ",g[i].nt[0]);
        memset(flw,'\0',sizeof(flw));
        follow(g[i].nt[0]);
        for(j=0; j<m; j++)
            printf("%c, ",flw[j]);
        printf("}\n");
    }
    return 0;
}
/*5
E->TX
X->+TX|#
T->FY
Y->*FY|#
F->(E)|id
*/
