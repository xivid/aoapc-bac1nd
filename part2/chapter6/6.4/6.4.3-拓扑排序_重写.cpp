#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxn 100
int n;
int g[maxn][maxn]={0};
int c[maxn]={0};
int s[maxn],t;
bool dfs(int u)
{
 c[u]=-1;
 for(int i=1;i<=n;i++) if(g[u][i]){
  if(c[i]<0) return false;
  else if(!c[i]&&!dfs(i)) return false;
 }
 s[t--]=u;
 c[u]=1;
 return true;
}
bool topo(){
 t=n;
 memset(c,0,sizeof(c));
 memset(s,0,sizeof(s));
 for(int i=1;i<=n;i++) if(!c[i])
  if(!dfs(i)) return false;
 return true;
}
int main(){
 int k; //k relations
 int a,b;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=k;i++) {
  scanf("%d%d",&a,&b);
  g[a][b]=1;
 }
 if(!topo()) printf("Error!");
 else for(int i=1;i<=n;i++) printf("%d",s[i]);
 return 0;
}
