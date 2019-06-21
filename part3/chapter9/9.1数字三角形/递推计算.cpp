#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define maxn 100
using namespace std;
int n, a[maxn][maxn], f[maxn][maxn];
int main(){
    freopen("test.in", "r", stdin);
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
      for (int j = 1; j <= i; ++j) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[n][i]);
        f[n][i] = a[n][i]; //边界的预处理和最后一行数据的读入结合了 
    }
    for (int i = n-1; i > 0; --i)
      for (int j = 1; j <= i; ++j)
        f[i][j] = a[i][j] + max(f[i+1][j], f[i+1][j+1]);
    printf("%d\n", f[1][1]);
    return 0;
}    
    
    
