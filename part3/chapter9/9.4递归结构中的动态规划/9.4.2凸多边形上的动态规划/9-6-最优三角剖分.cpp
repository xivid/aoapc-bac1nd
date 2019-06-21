#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 1000
#define INF 2000000000
int n, v[maxn], f[maxn][maxn];
inline int w(int i, int j, int k){return v[i]+v[j]+v[k];}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)  scanf("%d", v+i);
    for(int itv = 0; itv < n; ++itv)
      for(int i = 1; i + itv <= n; ++i){
        int j = i + itv;
        f[i][j] = (itv<=1 ? 0 : -INF);
        for(int k = i; k <= j; ++k) {
            int t = f[i][k] + f[k][j] + w(i, j, k);
            if(t > f[i][j]) f[i][j] = t;
        }
    }        
    printf("%d\n", f[1][n]);
    //这题我写的好像有问题，仅供参考 
    return 0;
}    
