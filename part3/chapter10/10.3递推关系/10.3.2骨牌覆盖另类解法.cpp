#include<iostream>
#include<cstring>
using namespace std;
int f(int n, int* F){
  if(F[n] > 0) return F[n];
  int& ans = F[n];
  for(int i = 1; n - i >= 1; i+=2) ans += f(n-i, F);
  ans += f(0, F);
  return ans;
}  
int main(){
  int n;
  cin >> n;
  int* F = new int[n+1];
  memset(F, 0, sizeof(int)*(n+1));
  F[0] = F[1] = 1;
  cout << f(n, F) << endl;
  return 0;
}  
  
