#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct ext{
  int pa, pb ,id;
  ext() { pa = pb = id = 0;}
} a[10000];
int n;
bool cmp(ext a, ext b){
  return (a.pb < b.pb || (a.pb==b.pb && a.pa>b.pa) );
}
int main(){
  scanf("%d", &n);
  for(int i=1 ; i<=n; i++) {a[i].id= i; scanf("%d%d",&a[i].pa, &a[i].pb); }
  sort(a+1, a+n+1, cmp);
  int last = a[1].pb, cur = 0;
  printf("Point #%d: %d\n", ++cur, last);
  for(int i=2; i<=n; i++) if(last<a[i].pa) {
    last = a[i].pb;
    printf("Point #%d: %d\n", ++cur, last);
  }
  return 0;
}
/*
5
4 6
2 3
1 4
6 8
5 7

6
4 6
5 6
2 3
1 4
6 8
5 7
在数轴上画出这些区间，对照程序的输出，颇有一针见血的感觉。。
*/
