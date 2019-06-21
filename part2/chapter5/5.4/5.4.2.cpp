#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int prime[100],p[100];
bool is_prime(int x)
{
    //DO NOT USE THIS FOR A VERY LARGE X
    for(int i=2;i*i<=x;i++) if(x%i==0) return false;
    return true;
}
int main()
{
    memset(prime,0,sizeof(prime));
    int count=0,n;
    for(int i=2;i<=99;i++) if(is_prime(i)) prime[++count]=i;
    while(cin >> n)
    {
        memset(p,0,sizeof(p));
        int maxp=-1;
        for(int m=2;m<=n;m++)
        {
            for(int i=1;i<=count;i++)
            {
                int k=m;
                while(k%prime[i]==0) {p[i]++; k/=prime[i]; maxp<i?maxp=i:0;}
            }
        }
        cout << n <<"! =";
        for(int i=1;i<=maxp;i++) cout << " " << p[i];
        cout << endl;
    }
    return 0;
}
