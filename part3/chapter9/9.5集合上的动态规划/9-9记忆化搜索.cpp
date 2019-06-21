#include<cstdio>
#include<cstdlib>
#include<cmath>
#define maxn 20
#define INF (1<<30)
int n;
struct Point{
    double x, y, z; 
} p[maxn];
double f[(1<<maxn)];   
inline double dist(int i, int j)
{return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y) + (p[i].z-p[j].z)*(p[i].z-p[j].z));}
inline double min(double x, double y){if(x < y) return x; return y;}
double d(int S){
    //记忆化搜索快得要逆天了！！（因为奇数的都没有算！！ ） 
    if(f[S] != -1) return f[S];
    int i, j; 
    double& ans = f[S];
    ans = (S == 0? 0 : INF);
    for(i = n-1; i >= 0; --i) if(S & (1<<i)) break;
    for(j = 0; j < i; ++j) if(S & (1<<j))
      ans = min(ans, d(S^(1<<i)^(1<<j)) + dist(i, j));
    return ans; 
}    
      
int main(){
    freopen("pair.in2", "r", stdin);
    scanf("%d", &n);
    if(n%2) {printf("No answer!\n"); return 0;}
    for(int i = 0; i < n; ++i) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z); 
    for(int i = 0; i < (1 << n); ++i) f[i] = -1;
    printf("%.3lf\n", d((1<<n)-1));
    /*
    int cnt = 0;
    for(int i = 0; i < (1 << n); ++i) if(f[i]!=-1) ++cnt;
    printf("%d\n", cnt);
    */
    while(1);
    return 0;
}     
