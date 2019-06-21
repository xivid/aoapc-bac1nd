#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
long long f[30]={0};
long long fac(int n){
    if(f[n]!=0) return f[n];
    int t = n;
    long long ans = 1ll;
    while(n) ans*=n--;
    f[t] = ans;
    return ans;
}
int main(){
  int n;
  memset(f,0,sizeof(f));
  n=0;
  while(n++<66){
    double s = 0.;
    for(int k=0; k<n; k++) s+=1./fac(k);
    cout << n << (n<10?" : ":": ") << setiosflags(ios::fixed)<<setprecision(10) <<s << endl;
  }
  return 0;
}
