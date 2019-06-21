#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define maxn 100
using namespace std;
int n, a[maxn][maxn];
int f(int i, int j){
    if(i == n) return a[i][j];
    return max(f(i+1, j), f(i+1, j+1)) + a[i][j]; //max() is included in <algorithm>
}    
int d(int i, int j){
    return a[i][j] + (i == n ? 0 : max(d(i+1, j), d(i+1, j+1)));
}    
int main(){
    freopen("test.in", "r", stdin);
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= i; j++) scanf("%d", &a[i][j]);
    int ans;
    ans = d(1, 1);
    printf("%d\n", ans);
    return 0;
}    
    
