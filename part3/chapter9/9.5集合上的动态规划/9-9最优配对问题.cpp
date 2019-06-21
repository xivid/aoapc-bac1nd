#include<cstdio>
#include<cstdlib>
#include<cmath>
#define maxn 20
#define INF (1<<30)
int n;
struct Point{
    double x, y, z; 
} p[maxn];
double f[maxn][(1<<maxn)];   
inline double dist(int i, int j)
{return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y) + (p[i].z-p[j].z)*(p[i].z-p[j].z));}
inline double min(double x, double y){if(x < y) return x; return y;}
int main(){
    freopen("pair.in", "r", stdin);
    scanf("%d", &n);
    if(n%2) {printf("No answer!\n"); return 0;}
    for(int i = 0; i < n; ++i) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z); 
    
    for(int i = 0; i < n; ++i)
      for(int S = 0; S < (1 << (i+1)); ++S){
          double& ans = f[i][S];
          ans = (S==0 ? 0 : INF);
          if(S & (1 << i)) {
            for(int j = 0; j < i; ++j) if(S & (1 << j))
              ans = min(ans, f[i-1][S^(1<<i)^(1<<j)] + dist(i, j));
          }
          else if(i!=0) f[i][S] = f[i-1][S]; //S中啥也不选 
        }    
    printf("%.3lf\n", f[n-1][(1<<n)-1]);
    while(1);
    return 0;
}     
