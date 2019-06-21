#include<cstdio>
#include<cmath>
double P(int n, int m){
  double ans = n;
  while(n-- && --m) ans *= n;
  return ans;
}  
double birthday(int n, int m){
  double ans = P(n, m);
  while(m--) ans /= n;
  return 1 - ans;
}  
double birthday2(int n, int m){
  double ans = 1.0;
  for(int i = 0; i < m; ++i) ans *= (double)(n-i) / n;
  return 1 - ans;
} 
int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  printf("%.8lf\n", birthday(n, m));
  printf("%.8lf\n", birthday2(n, m));
  return 0;
}  
