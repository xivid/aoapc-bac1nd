#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define maxl 1000010
#define a(i) a[(i)-shift]
int a[maxl], shift;
short vis[1020];
int prime2[200];
int getprime(int n){
  int c = 0;
  memset(vis, 0, sizeof(vis)); 
  int m = (int)sqrt((double)n + 0.5);
  for (int i = 2; i <= m; ++i) if(!vis[i])
    for (int j = i*i; j <= n; j+=i) vis[j] = 1;
  for (int i = 2; i <= n; ++i) if(!vis[i]) prime2[++c] = i*i; //保存素数的平方 
  return c;
}  
int main(){ 
  long long n, m;
  int ans = 0;
  scanf("%lld%lld", &n, &m);
  shift = n-1;
  memset(a, 0, sizeof(a));
  int c = getprime((int)sqrt((double)m + 0.5));
  for(int i = 1; i <= c; ++i)
    for(long long j = prime2[i]; j <= m; j+=prime2[i]) if(j>=n && j<=m && !a(j))
      a(j) = 1;
  for(long long i = n; i <= m; ++i) if(!a(i)) ans++;
  printf("%d\n", ans);
  for(long long i = n; i <= m; ++i) if(!a(i)) printf("%d ", i);
  return 0;
}  
