#include<cstdio>
#include<cstring>
#define maxv 10010
#define maxn 110
int n, C, w[maxn], v[maxn], f[maxn][maxv];
int main(){
    scanf("%d%d", &C, &n);
    for(int i = 1; i <= n; ++i) scanf("%d%d", v+i, w+i);
    memset(f, 0, sizeof(f)); //
    for(int i = 1; i <= n; ++i)
      for(int j = 0; j <= C; ++j){
          //f[i][j] = i==1 ? 0 : f[i-1][j];
          f[i][j] = f[i-1][j];
          if(j>=v[i] && f[i-1][j-v[i]] + w[i]>f[i][j]) f[i][j] = f[i-1][j-v[i]] + w[i];
      }
    printf("%d\n", f[n][C]);
    //while(1);
    return 0;
}        

