#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define INFINITY (1<<30)
using namespace std;
struct ext{
  int pa, pb, id;
  int a0, b0;
  ext(){pa = pb = a0 = b0 = id = 0;}
} a[10000];
int n, s ,t;
bool cmp(ext a, ext b){
  return (a.pa<b.pa || (a.pa==b.pa && a.pb>b.pb));
}
int main(){
  scanf("%d%d%d",&n, &s, &t);
  for(int i =1 ;i<=n; i++) {
    a[i].id = i;
    scanf("%d%d", &a[i].pa, &a[i].pb);
    if((a[i].pa<s && a[i].pb<s) || (a[i].pa>t && a[i].pb>t) ) a[i].pa = a[i].pb = INFINITY;
    //丢到右边无穷远处不管它了，排序也是排在最右边无穷远处。。
    else{
      a[i].a0 = a[i].pa;
      a[i].b0 = a[i].pb;
      if(a[i].pa < s) a[i].pa = s;
      if(a[i].pb > t) a[i].pb = t;
    }
  }
  sort(a+1, a+n+1, cmp);
  //for(int i=1; i<=n; i++) printf("==Ext[%d](%d, %d) 0(%d, %d)\n", a[i].id, a[i].pa, a[i].pb, a[i].a0, a[i].b0);
  s = a[1].pb;
  printf("Ext[%d](%d, %d) chosen.\n", a[1].id, a[1].a0, a[1].b0);
  for(int i = 2; i<=n; i++) if(a[i].pb>s) {
    s = a[i].pb;
    printf("Ext[%d](%d, %d) chosen.\n", a[i].id, a[i].a0, a[i].b0);
    if(s==t) break;
  }
  return 0;
}
/*
8 1 10
-3 -1
13 16
0 3
2 6
3 5
6 10
5 6
4 10

*/
