#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAXN 100 + 10
int maze[MAXN][MAXN]={0};
int father[MAXN*MAXN]={0},dir[MAXN*MAXN]={0},visited[MAXN][MAXN]={0};
//maze[i][j] <-> graph[i*m+j]
//path length not saved
char d[4]={'U','D','R','L'};
int dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
int n,m;
int q[MAXN*MAXN]={0},front=0,rear=1;
void bfs(int qd,int zd){
 int x,y;
 q[rear++]=qd;
 father[qd]=qd;
 while(front<rear){
  front++;
  x=q[front]/m; y=q[front]%m;
  visited[x][y]=1;
  //cout << "出队 Node "<<front <<" :"<<q[front] << endl;
  //getchar();
  for(int i=0;i<4;i++){
    int fx=x+dx[i],fy=y+dy[i];
    if(fx>=0&&fx<n&&fy>=0&&fy<n&&!visited[fx][fy]&&maze[fx][fy]){
    visited[fx][fy]=1; father[fx*m+fy]=q[front]; dir[fx*m+fy]=i;
    q[rear++]=fx*m+fy;
    //cout << "入队 Node "<<rear-1 <<" :"<<fx*m+fy << endl;
    if(q[rear]==zd) return;
    }
  }
 }
 //cout << "BFS successful ended." << endl;
 if(!visited[zd/m][zd%m]) {printf("Path Not Found!"); exit(0);}
}
void print(int qd,int zd){
 if(zd==qd) return;
 print(qd,father[zd]);
 putchar(d[dir[zd]]);
}
int stack[MAXN*MAXN],top=0;
void print_stack(int qd,int zd){
 while(qd!=zd){
  stack[++top]=dir[zd];
  zd=father[zd];
 }
 while(top) putchar(d[stack[top--]]);
}
int main()
{
 char buf[MAXN];
 int qx,qy,zx,zy;
 scanf("%d%d",&n,&m);
 for(int i=0;i<n;i++) {
   scanf("%s",buf);
   for(int j=0;j<m;j++) maze[i][j]=buf[j]-'0';
 }
 /*Print Maze
 for(int i=0;i<n;i++){
  for(int j=0;j<m;j++) printf("%d",maze[i][j]);
  putchar('\n');
 }
 */
 scanf("%d%d%d%d",&qx,&qy,&zx,&zy);
 bfs(qx*m+qy,zx*m+zy);
 print(qx*m+qy,zx*m+zy);
 putchar('\n');
 print_stack(qx*m+qy,zx*m+zy);
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
