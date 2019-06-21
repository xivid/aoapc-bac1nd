#include<cstdio>
#include<cstdlib>
#include<cmath>
#define maxn 22
#define maxs (1<<maxn)
#define INF 1e10
int n; 
double f[maxs], x[maxn], y[maxn], z[maxn];
inline double min(double x, double y){return x<y?x:y;}
inline double dist(int i, int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) + (z[i]-z[j])*(z[i]-z[j]));
}    
int main(){
    freopen("pair.in2", "r", stdin);
    scanf("%d", &n);
    for(int i  = 0; i < n; ++i) scanf("%lf%lf%lf", x+i, y+i, z+i);
    int U = (1 << n);
    for(int S = 0; S < U; ++S){
        int i;
        for(i = n-1; i >= 0; --i) if(S & (1<<i)) break;
        f[S] = (S==0) ? 0 : INF;
        for(int j = 0; j < i ; ++j) if(S & (1<<j)){
          f[S] = min(f[S], f[S^(1<<i)^(1<<j)] + dist(i, j));
        }    
      }
    printf("%.3lf\n", f[U-1]);
    while(1);
    return 0;
}
