#include<iostream>
#include<cassert>
using namespace std;
#define ull unsigned long long
typedef long long ll;
ull f(int n)

{    //ll ans;
     //ans =  n==0?1:f(n-1)*n;
     //assert(ans>0); 
     //return ans;
     return n==0?1:f(n-1)*n;
     }
     
int main(){
    int i=100000000;
    //for(int i=0;i<=100;i++)
    cout <<i <<":" <<f(i) << endl;
    //system("pause");
    return 0;
}    

