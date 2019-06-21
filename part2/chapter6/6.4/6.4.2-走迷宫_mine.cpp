#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define maxn 100 + 10
int g[maxn][maxn],vis[maxn][maxn];
int fa[maxn][maxn],last_dir[maxn][maxn],dist[maxn][maxn],n,m;
int q[maxn*maxn],path[maxn*maxn];
char name[4]={'R','D','U','L'};
int dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};
void bfs(int x0,int y0){
    int u;
    int front=1,rear=1;
    u=q[rear++]=x0*m+y0;
    vis[x0][y0]=1; fa[x0][y0]=u; dist[x0][y0]=0;
    while(front<rear){
     u=q[front++];
     int x=u/m,y=u%m;
     int fx,fy;
     for(int i=0;i<4;i++){
         fx=x+dx[i]; fy=y+dy[i];
         if(fx>=0&&fx<n&&fy>=0&&fy<m&&g[fx][fy]&&!vis[fx][fy]){
             q[rear++]=fx*m+fy;
             vis[fx][fy]=1;
             last_dir[fx][fy]=i;
             dist[fx][fy]=dist[x][y]+1;
             fa[fx][fy]=u;
         }
     }            
    }    
}    
void print(int x,int y){
    //recursion
    int u=fa[x][y];
    int fx=u/m,fy=u%m;
    if(x!=fx||y!=fy){
        print(fx,fy);
        printf("(%d,%d)",fx,fy);
    }
}        
void nprint(int x,int y){
    int c=0;
    for(;;){
        int fx=fa[x][y]/m,fy=fa[x][y]%m;
        if(fx==x&&fy==y) break;   
        path[c++]=last_dir[x][y];
        x=fx; y=fy;
    }
    while(c--) putchar(name[path[c]]);    
    putchar('\n');
}    
int main(){
    int sx,sy,tx,ty;
	char s[maxn];
    memset(g,0,sizeof(g));
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%s",s);
        for(int j=0;j<m;j++) g[i][j]=s[j]-'0';
    }    
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty); //origin&goal
    bfs(sx,sy);
    print(tx,ty);
    printf("(%d,%d)\nShortest path:\n",tx,ty);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout << dist[i][j] <<" ";
        cout << endl;
    }    
    cout <<"Last dir:\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout << last_dir[i][j] <<" ";
        cout << endl;
    }    
    nprint(tx,ty);
    system("pause");
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
0 0
0 4
*/
