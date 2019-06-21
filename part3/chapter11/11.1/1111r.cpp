#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
//输入无根树的结点个数n，输入n-1条边(u, v)，输入欲指定的根的编号root，建立以root为根的树
const int maxn = 10000;
int n, root, p[maxn];
vector<int> G[maxn];
void read_tree(){
  scanf("%d", &n);
  int u, v;
  for(int i = 0; i < n-1; ++i){
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }  
} 
void dfs(int u, int fa){
  int d = G[u].size();
  for(int i = 0; i < d; ++i) {
    int& v = G[u][i];
    if(v != fa) dfs(v, p[v] = u);
  }  
}  
int main(){
  freopen("11.1.1.in","r", stdin);
  read_tree();
  root = 0;
  p[root] = -1;
  dfs(root, -1);
  for(int i = 0; i < n; ++i) printf("p[%d] = %d\n", i, p[i]);
  while(1);
  return 0;
}  
  
