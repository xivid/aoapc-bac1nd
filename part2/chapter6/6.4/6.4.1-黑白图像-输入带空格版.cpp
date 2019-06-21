#include<iostream>
#include<cstring>
using namespace std;
#define maxn 1000 + 10
int g[maxn][maxn];
int vis[maxn][maxn];
int n,ans=0;
void dfs(int x, int y) {
    if(vis[x][y]||!g[x][y]) return;
    vis[x][y]=1;
    dfs(x-1,y-1); dfs(x-1,y); dfs(x-1,y+1);
    dfs(x,y-1);               dfs(x,y+1);
    dfs(x+1,y-1); dfs(x+1,y); dfs(x+1,y+1);
}    
int main(){
    memset(g,0,sizeof(g));
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
         scanf("%d",&g[i][j]);
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      if(g[i][j]&&!vis[i][j]) {ans++; dfs(i,j);}
    printf("%d\n",ans);
    system("pause");    
    return 0;
}    
/*
Sample Input1:
6
1 0 0 1 0 0
0 0 1 0 1 0
0 0 0 0 0 0
1 1 0 0 0 0
1 1 1 0 0 0
0 1 0 1 0 0
Sample Output1:
3

Sample Input2:
10
1 0 1 1 1 0 0 1 0 1
1 1 0 0 0 0 1 1 1 1
0 0 0 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 1 1 0 0 1 0 1 0 1
0 0 0 1 1 0 1 0 1 0
1 1 1 0 0 1 0 1 0 1
0 0 0 0 0 0 0 1 1 1
1 1 0 1 0 1 0 1 0 0
0 0 0 1 1 1 1 0 1 1
Sample Output2:
4
*/
