#include<iostream>
#include<cstring>
using namespace std;
#define maxn 1000 + 10
int g[maxn][maxn];
int vis[maxn][maxn];
int n;
int sx[maxn],sy[maxn]; 
void dfs(int x,int y) {
 int top=0;
 sx[++top]=x; sy[top]=y;
 while(top) {
  int tx=sx[top],ty=sy[top];  
  //一定要注意不能直接用x和y，这个错误浪费了我一节课 
  if(vis[tx][ty]||!g[tx][ty]) {
      vis[tx][ty]=1; top--;continue;}
  vis[tx][ty]=1;
  sx[++top]=tx-1;sy[top]=ty-1;  
  sx[++top]=tx-1;sy[top]=ty; 
  sx[++top]=tx-1;sy[top]=ty+1;
  sx[++top]=tx;sy[top]=ty-1;
  sx[++top]=tx;sy[top]=ty+1;   
  sx[++top]=tx+1;sy[top]=ty-1; 
  sx[++top]=tx+1;sy[top]=ty;   
  sx[++top]=tx+1;sy[top]=ty+1;  
 }    
}        
int main(){
    memset(g,0,sizeof(g));
    memset(vis,0,sizeof(vis));
    char s[maxn];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        for(int j=1;j<=n;j++) g[i][j]=s[j-1]-'0';
    }    
    int ans=0;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      if(g[i][j]&&!vis[i][j]) {ans++; dfs(i,j); }
    printf("%d\n",ans);
    system("pause");    
    return 0;
}    
/*
Sample Input1:
6
100100
001010
000000
110000
111000
010100
SampleOutput1:
3

SampleInput2:
10
1011100101
1100001111
0001110000
0000000000
0110010101
0001101010
1110010101
0000000111
1101010100
0001111011
SampleOutput2:
4
*/
