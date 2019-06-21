//无向图中有最小生成树，有向图中的类似结构叫做最小树形图 （朱刘算法） 
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100, maxm = 6000;
int u[maxm], v[maxm], w[maxm], r[maxm], p[maxn];
int n, m;
bool cmp(int i, int j){return w[i] < w[j];}
int find(int x){ return p[x] == x ? x : p[x] = find(p[x]);}
int Kruskal(){
  int ans = 0, k = 0;
  for(int i = 0; i < m; ++i) r[i] = i;
  for(int i = 0; i < n; ++i) p[i] = i;
  sort(r, r+m, cmp);
  for(int i = 0; i < m; ++i){
    int e = r[i];
    int x = find(u[e]), y = find(v[e]);
    if(x != y){ ans += w[e]; ++k; p[x] = y;}
    if(k == n-1) break;
  }  
  for(int i =0 ;i < n; ++i) printf("%d\n", find(i));
  if(k == n-1) return ans;
  else return -1;
}      
int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; ++i) scanf("%d%d%d", u+i, v+i, w+i);
  printf("%d\n", Kruskal());
  while(1);
  return 0;
}  
/*
5 7
0 1 5
0 2 1
0 3 2
0 4 4
1 3 1
2 3 5
2 4 2
*/
