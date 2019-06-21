#include<cstdio>
#include<cstring>
const int INF = 0x7f7f7f7f;
const int maxn = 1010, maxm = 10010;
int d[maxn][maxn], n, m;
int min(int x, int y){return x < y? x: y;}
int main(){
  freopen("1.in", "r", stdin);
  scanf("%d%d", &n, &m);
  memset(d, INF, sizeof(d));
  for(int i = 1; i <= n; ++i) d[i][i] = 0;
  int u, v, w;
  for(int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    d[u][v] = w;
  }
  for(int k = 1; k <= n; ++k)
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      if(d[i][k]<INF && d[k][j] < INF) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
  for(int i = 1; i <= n ;++i) printf("d[1][%d] = %d\n", i, d[1][i]);
  while(1);
  return 0;
}  
/*
5 6
1 2 23
1 3 17
1 5 49
2 3 5
2 4 13
4 5 7
*/
