#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
//我就用DP，你能怎么样~（O(n^2)）
using namespace std;
const int maxn = 10000;
int n, c;
int w[maxn], f[maxn][maxn];
int main(){
  memset(w, 0, sizeof(w));
  memset(f, 0, sizeof(f));
  scanf("%d%d",&n,&c);
  for(int i=1; i<=n; i++) scanf("%d",&w[i]);
  for(int i=n; i>=1; i--)
    for(int j=0; j<=c; j++){
    f[i][j] = (i==n)?0:f[i+1][j];
    if(j>=w[i]) f[i][j] = max(f[i][j], f[i+1][j-w[i]] + 1);
  }
  printf("%d\n",f[1][c]); //f[i][j]代表在i..n物品中可选的最大件数
}
/*
10 10
10 2 1 1 1 1 1 1 1 1
*/
