#include<iostream>
using namespace std;
int main()
{
    int n,v=0,e=0,f,s=0; //V-E+F=2
    cin >> n;
    for(int i=0;i<=n-2;s=s+i*(n-2-i),i++);
    v=n+n*s/4;
    e=n+n*(s+n-1)/2;  
    f=1+e-v;
    cout << f << endl;
    return 0;
}    
