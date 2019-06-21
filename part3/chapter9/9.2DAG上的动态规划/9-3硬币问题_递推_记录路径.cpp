#include <cstdio>
#include <cstring>
const int maxn = 110, maxv = 10086, INF = 1234567890;
int v[maxn], S, n, maxf[maxv], minf[maxv], min_coin[maxv], max_coin[maxv];
void print_ans(int *d, int s){
    while(s){
        printf("%d ", d[s]);
        s-=v[d[s]];
    }
}        
int main(){
    freopen("9-3.in", "r", stdin);
    scanf("%d%d", &n, &S);
    for(int i = 1; i <= n; ++i) scanf("%d", &v[i]);
    for(int i = 1; i <= S; ++i) {
        //最应注意的是边界条件、初始化，因为递推作为重点一般不会写错，就是在这种细节处出错 
        maxf[i] = -INF; 
        minf[i] = INF;
    }    
    maxf[0] = minf[0] = 0;
    for(int i = 1; i <= S; ++i)
      for(int j = 1; j <= n; ++j) if(i >= v[j]){
          if(maxf[i-v[j]] + 1 > maxf[i]){
              maxf[i] = maxf[i-v[j]] + 1;
              max_coin[i] = j;
          }
          if(minf[i-v[j]] + 1 < minf[i]){
              minf[i] = minf[i-v[j]] + 1;
              min_coin[i] = j; 
          }
      }
    printf("%d\n", minf[S]);
    print_ans(min_coin, S);
    printf("\n");
    printf("%d\n", maxf[S]);
    print_ans(max_coin, S);
    printf("\n");
    return 0;
}    
