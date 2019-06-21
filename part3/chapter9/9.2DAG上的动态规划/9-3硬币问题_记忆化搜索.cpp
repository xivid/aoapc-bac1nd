//在线提交：tyvjP1214 
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 102, maxv = 10005;
int n, S, v[maxn], mind[maxv], maxd[maxv];
int dp1(int s){//最小值
    int &ans = mind[s];
    if(ans != -1) return ans;
    ans = 1<<30;
    for(int i = 1; i <= n; ++i) if(v[i] <= s) ans = min(ans, dp1(s-v[i])+1);
    return ans;
}
int vis[maxv];
int dp2(int s){//最大值 
    if(vis[s]) return maxd[s];
    vis[s] = 1;
    int &ans = maxd[s];
    ans = -1<<30;
    for(int i = 1; i <= n; ++i) if(s >= v[i]) ans = max(ans, dp2(s-v[i])+1);
    return ans;
}     
void print_ans(int* d, int s){//打印的是边
    for(int i = 1; i <= n; ++i) if(v[i] <= s && d[s-v[i]]+1 ==d[s]) {
        printf("%d ",i);
        print_ans(d, s-v[i]);
        break;
    }
}        
int main(){
    freopen("9-3.in", "r", stdin);
    scanf("%d%d", &n, &S);
    for(int i = 1; i <= n; ++i) scanf("%d", v+i);
    memset(mind, -1, sizeof(mind));
    mind[0] = 0;
    printf("%d\n", dp1(S));
    print_ans(mind, S);
    printf("\n");
    memset(maxd, -1, sizeof(maxd));
    memset(vis, 0, sizeof(vis));
    maxd[0] = 0; vis[0] = 1;
    printf("%d\n", dp2(S));
    print_ans(maxd, S);
    printf("\n");
    return 0;
}     
