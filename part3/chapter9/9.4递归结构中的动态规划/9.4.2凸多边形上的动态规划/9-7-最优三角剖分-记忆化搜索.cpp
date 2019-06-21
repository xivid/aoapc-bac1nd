#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 1000
#define INF 2000000000
int n, v[maxn], f[maxn][maxn];
inline int max(int a, int b){return a > b ? a : b;}
inline int w(int i, int j, int k){if(i==j||j==k||i==k) return 0; return v[i]+v[j]+v[k];}
int d(int i, int j){
    if(f[i][j] != -1) return f[i][j];
    int& ans = f[i][j];
    ans = (i==j ? 0 : -INF);
    if(i <= j) for(int k = i; k <= j; k++) ans = max(ans, d(i, k) + d(k, j) + w(i, j, k));
    else {
        for(int k = i+1; k <= n; k++) ans = max(ans, d(i, k) + d(k, j) + w(i, j, k));
        for(int k = 1; k < j; k++) ans = max(ans, d(i, k) + d(k, j) + w(i, j, k));
    }
    return ans;
}        
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)  scanf("%d", v+i);   
    memset(f, -1, sizeof(f));    
    printf("%d\n", d(1, 1));
    //这题我写的有问题，仅供参考 
    return 0;
}    
/*
7
1 2 3 4 5 6 7
*/
