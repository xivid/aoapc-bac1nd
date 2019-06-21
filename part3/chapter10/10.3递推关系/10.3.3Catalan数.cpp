#include<iostream> 
#include<cassert> 
#define maxn 18
using namespace std; 
int c1[maxn];
int catalan1(int n){
  if(c1[n]>0) return c1[n]; 
  int& ans = c1[n];
  for(int k = 2; k < n; ++k) ans += catalan1(k)*catalan1(n-k+1);
  return ans;
} 
int c2[maxn]; 
int catalan2(int n){
  if(c2[n]>0) return c2[n];
  int& ans = c2[n];
  for(int k = 3; k < n; ++k) ans += catalan2(k)*catalan2(n-k+2);
  ans = ans * n / (2*n - 6);
  return ans;
}  
int catalan3(int n){
  int ans = 1; //c[3] = 1
  for(int i = 4; i <= n; ++i) ans = ans * (4*(i-1)-6)/(i-1);
  return ans;
}
int c4[maxn];
int catalan4(int n){
  memset(c4, 0, sizeof(c4));
  c4[2] = c4[3] = 1;
  for(int i = 4; i <= n; ++i)
    for(int k = 2; k < i; ++k)
      c4[i] += c4[k]*c4[i-k+1];
  return c4[n];
}  
int main(){
  int n;
  cin >> n;
  assert(n < maxn);
  memset(c1, 0, sizeof(c1));
  memset(c2, 0, sizeof(c2));
  c1[2] = c1[3] = 1;
  c2[3] = 1;
  int ans1 = catalan1(n), ans2 = catalan2(n), ans3 = catalan3(n), ans4 = catalan4(n); 
  assert(ans1 == ans2 && ans1 == ans3 && ans1 == ans4);
  cout << ans1 << endl;
  cout << ans2 << endl; //以上2个记忆化搜索 
  cout << ans3 << endl; //以下2个递推 
  cout << ans4 << endl; 
  while(1);
  return 0;
}  
