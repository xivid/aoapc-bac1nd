#include<cstdio>
#include<cstdlib>
const int maxn = 30;
int ans, n, a[maxn][maxn], cnt;
void trace(int x, int y, int s){
    if(x == n){
        if(s > ans) ans = s;
        cnt++; 
        return;
    }
    trace(x+1, y, (s+a[x+1][y]));
    trace(x+1, y+1, (s+a[x+1][y+1]));
}        
int main(){
    freopen("test.in", "r", stdin); 
    ans = 0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
      for(int j=1; j<=i; j++)
        scanf("%d", &a[i][j]);
    cnt = 0;
    trace(1,1,a[1][1]);
    printf("%d\n", ans);
    printf("%d routines in total.\n", cnt);
    return 0;
}    
