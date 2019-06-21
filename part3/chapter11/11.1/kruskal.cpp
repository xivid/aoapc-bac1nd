#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10000;
int u[maxn], v[maxn], w[maxn];
int n, m;
int p[maxn], r[maxn];
bool cmp(int i, int j){return w[i] < w[j];}
int find(int x){return p[x] == x? x: p[x] = find(p[x]);}
int Kruskal(){
  for(int i = 1; i <= m; ++i) r[i] = i;
  for(int i = 1; i <= n; ++i) p[i] = i;
  sort(r+1, r+m+1, cmp);
  int k = 0, ans = 0;
  for(int i = 1 ; i <= m; ++i) {
    int e = r[i]; int x = find(u[e]), y = find(v[e]);
    if(x!=y){ ans += w[e]; ++k; p[x] = y;}
    if ( k == n-1 )break;
  }  
  int root = find(1);
  for(int i =1 ;i <=n; ++i) if(find(i)!=root) return -1;
  return ans;
}  
int main(){
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; ++i) scanf("%d%d%d", u+i, v+i, w+i);
  printf("%d\n", Kruskal());
  return 0;
}  
/*
5 7
1 2 5
1 3 1
1 4 2
1 5 4
2 4 1
3 4 5
3 5 2
(6)
5 7
1 5 6
2 5 7
2 4 7
2 3 9
1 4 5
1 2 4
3 4 2
(17)
*/
