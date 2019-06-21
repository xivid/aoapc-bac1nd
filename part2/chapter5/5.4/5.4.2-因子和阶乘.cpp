#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool isprime(int x)
{
    for(int i=2;i*i<=x;i++) if(x % i == 0) return false;
    return true;
}    
int main()
{
    int n;
    int prime[100],geshu[100],top=0;
    memset(prime,0,sizeof(prime));
    for(int i=2;i<100;i++) if(isprime(i)) prime[++top]=i; 
    while(cin>>n)
    {
        memset(geshu,0,sizeof(geshu));
        int max=-1;
        for(int m=2;m<=n;m++){
            for(int i=1;i<=top;i++)
            {
              int k=m;
              while(k%prime[i]==0) {geshu[prime[i]]++; k/=prime[i];}
              if(geshu[prime[i]]!=0&&prime[i]>max) max=prime[i];
            }    
        }    
        for(int i=1;i<=top;i++) 
         if(prime[i]<=max) cout << geshu[prime[i]] <<" ";
        cout << endl;
    
    }         

    return 0;
}    
