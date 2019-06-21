#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 1000
using namespace std;
int G[maxn][maxn], a[maxn], b[maxn], d[maxn], n, answer;
int dp(int i){
  int& ans = d[i];
  if (ans > 0) return ans;
  ans = 1;
  for(int j = 1; j <= n; ++j) if(G[i][j]) ans = max(ans, dp(j)+1);
  return ans;
}
void print_ans(int i){
  printf("%d(%d, %d) ", i, a[i], b[i]);
  for(int j = 1; j <= n; ++j) if(G[i][j] && d[j]+1 == d[i]){
    print_ans(j);
    break;
  }
}

int path[maxn] = {0}, cnt = 0;
void print_all(int i){
  //输出所有符合条件的路径
  path[++cnt] = i;
  if(cnt == answer) {
    for(int j = 1; j <= cnt; ++j) printf("%d(%d, %d) ", path[j], a[path[j]], b[path[j]]);
    printf("\n");
  }
  else for(int j = 1; j <= n; ++j) if(G[i][j] && d[j]+1 == d[i]){
    print_all(j);
  }
  --cnt;
}
/*
//作者的方法
int path[maxn];
void print_all(int cur, int i) {
  path[cur] = i;
  if(d[i] == 1) {
    for(int j = 0; j <= cur; j++) printf("%d ", path[j]);
    printf("\n");
  }
  for(int j = 1; j <= n; j++) if(G[i][j] && d[i] == d[j]+1)
    print_all(cur+1, j);
}
*/
int main(){
  freopen("9-2.in", "r", stdin);
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) scanf("%d%d", a+i, b+i);
  memset(G, 0, sizeof(G));
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j) if((a[i]>a[j]&&b[i]>b[j])||(a[i]>b[j]&&b[i]>a[j]))
      G[i][j] = 1;
  int t, s;
  answer = -1;
  memset(d, 0, sizeof(d));
  for (int i = 1; i <= n; ++i) {
    t = dp(i);
    if(answer < t) {answer = t; s = i;}
  }
  printf("%d\n", answer);
  print_ans(s);
  printf("\nAll routes:\n");
  //print_all(0, s);
  print_all(s);
  return 0;
}
