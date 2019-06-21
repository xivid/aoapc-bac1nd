#include<cstdio>
#include<cmath>
#include<cstring>
short vis[10000000];
int prime[10000];
int get_prime(int n){
  int c = 0;
  memset(vis, 0, sizeof(vis));
  int m = (int)sqrt((double)n + 0.5);
  for(int i = 2; i <= m; ++i) if(!vis[i]) //书上的代码只能保存1~m内的质数 
    for(int j = i * i; j <= n; j+=i) vis[j] = 1;
  for(int i = 2; i <= n; ++i) if(!vis[i]) prime[++c] = i;
  return c;
}   
int main(){
  int n, c;
  while(scanf("%d", &n) == 1 && n){
    c = get_prime(n);
    printf("%d primes found, the last one is %d\n", c, prime[c]);
  }  
  return 0;
}  
