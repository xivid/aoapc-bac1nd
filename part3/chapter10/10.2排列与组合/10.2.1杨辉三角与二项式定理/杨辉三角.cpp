#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxc 110
unsigned long long c[maxc][maxc];
int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  memset(c, 0, sizeof(c));
  c[0][0] = 1; 
  for(int i = 1; i <= n; ++i) {
    c[i][0] = 1;
    for(int j = 1; j <= i; ++j) c[i][j] = c[i-1][j-1] + c[i-1][j];
  }
  printf("%lld\n", c[n][m]);
  return 0;
}
//ull 大概可以算到66C33


