#include <cstdio>
#include <cstdlib>
#include <cstring>
int n, p[205], d[205][205];
const int INF = 2000000000;
int f(int i, int j){
    if(d[i][j]>=0) return d[i][j];
    int& ans = d[i][j];
    int t;
    ans = INF;
    for (int k = i; k < j; k++) {
        t = f(i, k) + f(k+1, j) + p[i-1]*p[k]*p[j];
        if(t < ans) ans = t;
    }
    return ans;    
}    
int main(){
   scanf("%d", &n);
   for(int i = 0; i <= n; ++i) scanf("%d", p + i);
   memset(d, -1, sizeof(d));
   for(int i = 0; i <= n; ++i) d[i][i] = 0;
   printf("%d\n", f(1, n));
   while(1);
   return 0;
}     
