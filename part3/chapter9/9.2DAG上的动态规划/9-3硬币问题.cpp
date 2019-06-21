//在线提交：tyvjP1214 
#include<cstdio>
#include<cstdlib>
const int maxn = 110, maxv = 10086, INF = 123456789;
int n, S, v[maxn], min[maxv], max[maxv];
int main(){
    scanf("%d%d", &n, &S);
    for(int i = 1; i <= n; ++i) scanf("%d", v+i);
    min[0] = max[0] = 0;
    for(int i = 1; i <= S; ++i) {min[i] = INF; max[i] = -INF;}
    for(int i = 1; i <= S; ++i)
      for(int j = 1; j <= n; ++j) if(v[j] <= i){
          if(min[i-v[j]] + 1 < min[i]) min[i] = min[i-v[j]] + 1;
          if(max[i-v[j]] + 1 > max[i]) max[i] = max[i-v[j]] + 1;
      }
    printf("%d\n", min[S]);
    printf("%d\n", max[S]);
    return 0;
}         
