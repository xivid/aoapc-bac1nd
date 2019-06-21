#include<cstdio>
#include<cstdlib>
#include<cstring>
int n, p[205], f[205][205]; 
const int INF = 2000000000;
int main(){
    scanf("%d", &n);
    for(int i = 0; i <= n; ++i) scanf("%d", p+i);
    for(int sep = 0; sep < n; ++sep) //设sep=j-i，要以sep递增即j-i递增也即区间长度递增的顺序DP 
      for(int i = 1; i + sep <= n; ++i){
        int j = i + sep;
        f[i][j] = i == j? 0 : INF;
        for(int k = i; k < j; ++k){
          int t = f[i][k] + f[k+1][j] + p[i-1]*p[k]*p[j];
          if(t < f[i][j]) f[i][j] = t;
        }
      }
    printf("%d\n", f[1][n]);
    return 0;
}    
