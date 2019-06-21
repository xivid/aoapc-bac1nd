//给出唯一分解式就太简单了！！不给了！！
#include<iostream>
using namespace std;
int main(){
  unsigned long long n, p[20];
  int a[20], c=0;
  scanf("%lld", &n);
  for(int i = 2;; ++i) if(n % i == 0){
    p[++c] = i; a[c] = 0;
    while(n % i == 0) { n/=i; ++a[c];}
    if(n == 1) break;
  }  
  for(int i = 1; i <= c; ++i) printf("%lld^%d ", p[i], a[i]);
  unsigned long long ans = 1;
  for(int i = 1; i <= c; ++i) ans *= (a[i]+1);
  printf("\n%lld\n", ans);
  return 0;
}  
