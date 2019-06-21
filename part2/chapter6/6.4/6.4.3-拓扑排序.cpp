#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn=200;
int g[maxn][maxn]={0};
int c[maxn]={0};
int s[maxn],t,n;
bool dfs(int p){
 c[p]=-1;
 for(int i=1;i<=n;i++) if(g[p][i]) {
  if(c[i]<0) return false; //if i is being visited,i must < this, but g[p][i] means this < i,so a circle is found.
  else if(!c[i]&&!dfs(i)) return false; //nodes after i form a circle
 }
 s[t--]=p; c[p]=1;
 return true;
}
bool topo()
{
 t=n;
 memset(c,0,sizeof(c));
 for(int i=1;i<=n;i++) if(!c[i])
  if(!dfs(i)) return false;
 return true;
}
int main(){
 int k; // n nodes, k relationships
 int a,b;
 scanf("%d%d",&n,&k);
 for(int i=1;i<=k;i++) {
  scanf("%d%d",&a,&b);
  g[a][b]=1;
 }
 if(!topo()) printf("Error!");
 else for(int i=1;i<=n;i++)
  printf("%d",s[i]);
 return 0;
}
