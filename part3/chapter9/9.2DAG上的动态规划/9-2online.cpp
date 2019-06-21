//在线提交地址：http://acm.nyist.net/JudgeOnline/problem.php?pid=16
//另附0ms	 236kb的DP思路：按边长降序排序，用类似LIS的方法求解，只是比较元素大小的方法变成了比较长和宽
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 1008
using namespace std;
int G[maxn][maxn], a[maxn], b[maxn], d[maxn], n;
int dp(int i){
  int& ans = d[i];
  if (ans > 0) return ans;
  ans = 1;
  for(int j = 1; j <= n; ++j) if(G[i][j]) ans = max(ans, dp(j)+1);
  return ans;
}
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d%d", a+i, b+i);
    memset(G, 0, sizeof(G));
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j) if((a[i]>a[j]&&b[i]>b[j])||(a[i]>b[j]&&b[i]>a[j]))
        G[i][j] = 1;
    int ans = -1, t, s;
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; ++i) {
      t = dp(i);
      if(ans < t) {ans = t; s = i;}
    }
    printf("%d\n", ans);
  }
  return 0;
}
