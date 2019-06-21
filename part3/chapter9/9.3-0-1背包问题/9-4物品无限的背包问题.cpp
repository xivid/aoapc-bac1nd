//online judge: http://acm.sjtu.edu.cn/OnlineJudge/problem/1013
#include<cstdio>
#include<cstring>
#define maxn 1010
#define maxv 10010
int n, C, v[maxn], w[maxn], f[maxv];
int main(){
   scanf("%d%d", &C, &n);
   for (int i = 1; i <= n; ++i) scanf("%d%d", v+i, w+i);
   memset(f, 0, sizeof(f));
   for(int i = 1; i <= C; ++i)
     for(int j = 1; j <= n; ++j)
       if(i >= v[j] && f[i-v[j]] + w[j] > f[i]) f[i] = f[i-v[j]] + w[j];
   printf("%d\n", f[C]);
   return 0; 
}   
