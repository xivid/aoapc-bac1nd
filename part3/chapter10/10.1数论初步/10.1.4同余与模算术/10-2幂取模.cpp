//这就是传说中的“快速幂”，这里用两种方法来实现 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<iostream>
using namespace std;
int pow_mod1(int a, int n, int m){
  if(n==0) return 1;
  long long x = pow_mod1(a, n/2, m);
  long long ans = x * x % m;
  if(n%2) ans = ans * a % m;
  return (int)ans;
}  
int pow_mod2(int a, int n, int m){
  long long b = a;
  b %= m;
  long long ans = 1;
  while(n){
    if(n%2) ans = ans * b % m;
    b = b * b % m; 
    n/=2;
  }   
  return (int)ans;
}  
int main(){
  int a, n, m;
  cin >> a >> n >> m;
  int ans1 = pow_mod1(a, n, m), ans2 = pow_mod2(a, n, m);
  assert(ans1 == ans2);
  printf("(%d^%d) %% %d = %d\n", a, n, m, ans1);
  printf("(%d^%d) %% %d = %d\n", a, n, m, ans2);
  return 0;
}  
