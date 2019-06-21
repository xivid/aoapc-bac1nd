#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100
int n, a[maxn][maxn], d[maxn][maxn];
int f(int i, int j){
    if(d[i][j] >= 0) return d[i][j];
    return d[i][j] = a[i][j] + (i==n ? 0 : max(f(i+1, j+1), f(i+1, j)));
}
int main(){
    freopen("test.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
      for (int j = 1; j <= i; j++) scanf("%d", &a[i][j]);
    memset(d, -1, sizeof(d));
    printf("%d\n", f(1, 1));
    return 0;
}
