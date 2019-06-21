#include<cstdio>
#include<cstring>
#define maxn 20
int n, a[maxn], isp[maxn << 1], vis[maxn], ans;
void makeprime(){
  int ok;
  memset(isp,0,sizeof(isp));
  for(int i=2; i<=(n<<1); i++){
    ok = 1;
    for(int j=2; j*j<=i; j++) if(i % j == 0) ok = 0;
    if(ok) isp[i] = 1;
  }
}
void dfs(int cur){
  if(cur == n && isp[a[0]+a[n-1]]) {
      ans++;
      for(int i=0; i<n; i++) printf("%d ",a[i]); printf("\n");
    }
  else for(int i=2;i<=n;i++) if(!vis[i] && isp[i+a[cur-1]]) {
      a[cur] = i;
      vis[i] = 1;
      dfs(cur+1);
      vis[i] = 0;
  }
}
int main(){
  scanf("%d",&n);
  //n=18;
  makeprime();
  ans=0;
  a[0] = 1;
  dfs(1);
  printf("ans=%d\n",ans);
  return 0;
}
