#include<bits/stdc++.h>
using namespace std;
int isprime(int x){
    if(x<=1)
        return 0;
    for(int i = 2;i<x;i++)
    {
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n>0){printf("Positive Number.\n");}
        else if(n<0){printf("Negative Number.\n");}
        else if(n==0){printf("Neutral Number.\n");}

        if(n%2==0){printf("Even Number.\n");}
        else{printf("Odd Number.\n");}

        if(isprime(abs(n))==1){printf("Prime Number.\n");}
        else{printf("Not Prime Number\n");}
    }


    return 0;
}


