#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int n, m, ans;
  cin >> n;
  m = (int)sqrt((double)n + 0.5);
  ans = n;
  for(int i = 2; i <= m; ++i) if(n % i ==0){
    ans = ans / i * (i-1);
    while(n % i == 0) n /= i;
    if(n==1) break;
  }
  if(n > 1) ans = ans / n * (n-1);
  cout << ans << endl;
  return 0;
}      
    
