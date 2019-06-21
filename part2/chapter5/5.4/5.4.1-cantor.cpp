#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,k,s;
    while(cin >> n){
        k=(int)ceil((sqrt(1+8.0*n)-1)/2);
        s=k*(k-1)/2;
        if(k%2)
            cout << k+1-n+s<<"/" << n-s<<endl;
        else cout<< n-s <<"/"<<k+1-n+s<<endl;
    }
    return 0;
}        
