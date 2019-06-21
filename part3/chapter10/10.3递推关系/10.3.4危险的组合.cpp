#include<iostream>
#include<cassert>
using namespace std;
#define maxn 50
int main(){
  //f(n) = 2^(n-3) + [sigma,1<i<n-1](g(i-2)*2^(n-2-i))
  //g(i) = 2^i - f(i)
  int n;
  cin >> n;
  assert( n < maxn );
  int f[maxn], g[maxn];
  f[0] = f[1] = f[2] = 0;
  g[0] = 1; g[1] = 2; g[2] = 4;
  for(int i = 3; i <= n; ++i){
    f[i] = (1 << (i-3));
    for(int j = 2; j < i-1; ++j) f[i] += g[j-2]*(1<<(i-j-2));
    g[i] = (1<<i) - f[i];
  }
  cout << f[n] << endl;   
  return 0;
}  
