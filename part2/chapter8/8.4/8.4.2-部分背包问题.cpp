#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define maxn 100000
int n;
double c;
struct matter{
  int id;
  double w, v, div;
} a[maxn];
bool cmp(matter a, matter b){
  return a.div > b.div;
}
int main(){
  scanf("%d%lf", &n, &c);
  for(int i=1; i<=n; i++) {
    scanf("%lf%lf", &a[i].w, &a[i].v);
    a[i].id = i;
    a[i].div = a[i].w/a[i].v;
  }
  sort(a+1, a+n+1, cmp);
  for(int i=1; i<=n; i++) printf("[%d]: w-%.2lf, v-%.2lf, div-%.2lf\n", a[i].id, a[i].w, a[i].v, a[i].div);
  int cur = 1;
  while(c>1e-2){
    if(c>a[cur].w) {c-=a[cur].w; printf("take all %d\n", a[cur++].id);}
    else {printf("take %.2lf%% of %d\n", c/a[cur].w*100, a[cur].id); c=0; break;}
  }
  return 0;
}
/*
4 30
8 2
19 3
5 9
2 1
*/
