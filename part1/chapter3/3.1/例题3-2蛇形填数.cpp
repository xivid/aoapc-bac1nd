#include<iostream>
#include<cstdio>
#define MAXN 50
using namespace std;
int main()
{
    int a[MAXN][MAXN]={0};
    int num=1,n,x=1,y=1;
    scanf("%d",&n);
    a[x][y]=1;
    while(num<n*n)
    {
      while(a[x+1][y]==0&&x+1<=n) {num++; x++; a[x][y]=num;}
      while(a[x][y+1]==0&&y+1<=n) {num++; y++; a[x][y]=num;} 
      while(a[x-1][y]==0&&x-1>0)  {num++; x--; a[x][y]=num;}
      while(a[x][y-1]==0&&y-1>0)  {num++; y--; a[x][y]=num;}          
    }
    for(int i=1;i<=n;i++)
     {for(int j=1;j<=n;j++)
      printf("%5d",a[j][i]);
      printf("\n");
      }
    return 0;
}
