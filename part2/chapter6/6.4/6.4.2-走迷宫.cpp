#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=120;
int n,m,fa[maxn][maxn]={0},dist[maxn][maxn]={0},vis[maxn][maxn]={0};
int last_dir[maxn][maxn]={0},maze[maxn][maxn]={0};
int q[maxn*maxn];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
char name[4]={'U','D','L','R'};
void bfs(int x,int y)
{
    int front=0,rear=0,d,u;
    u=x*m+y;
    vis[x][y]=1; fa[x][y]=u; dist[x][y]=0;
    q[rear++]=u;
    while(front<rear)
    {
        u=q[front++];
        x=u/m; y=u%m;
        for(d=0;d<4;d++)
        {
            int nx=x+dx[d], ny=y+dy[d];
            if(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny] && !vis[nx][ny])
            {
                int v=nx*m+ny;
                q[rear++]=v;
                vis[nx][ny]=1;
                fa[nx][ny]=u;
                dist[nx][ny]=dist[x][y]+1;
                last_dir[nx][ny]=d;
            }
        }
    }
}
void print_path1(int x, int y) {
    int fx=fa[x][y] / m;
    int fy= fa[x][y] %m ;
    if(fx!=x||fy!=y){
        print_path1(fx,fy);
        putchar(name[last_dir[x][y]]);
    }
}
int dir[maxn*maxn];
void print_path(int x ,int y )
{
    int c=0;
    for(;;)
    {
        int fx=fa[x][y] / m ;
        int fy=fa[x][y] % m;
        if(fx==x&&fy==y) break;
        dir[c++] = last_dir[x][y];
        x=fx;
        y=fy;
    }
    while(c--)
      putchar(name[dir[c]]);
}
int main(){
    char s[maxn];
    cin >> n>> m;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<m;j++) maze[i][j]=s[j]-'0';
    }
    bfs(0,0);
    print_path(0,4);
    //system("pause");
    return 0;
}
/*
6 5
11011
10111
10100
10111
11101
11111
*/
