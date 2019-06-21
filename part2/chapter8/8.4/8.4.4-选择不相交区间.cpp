#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct ext{
  int a, b, id;
  ext(int iid=0, int aa=3, int bb=4): id(iid), a(aa),b(bb){}
} a[1000];
int n;
bool cmp(ext a, ext b){
  return (a.b < b.b || (a.b==b.b && a.a>b.a));
}
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {a[i].id = i; scanf("%d%d", &a[i].a, &a[i].b);}
  sort(a+1, a+n+1, cmp);
  for(int i=1; i<=n; i++) printf("ext[%d] (%d, %d)\n", a[i].id, a[i].a, a[i].b);
  int last = 1;
  printf("ext[%d] (%d, %d) chosen.\n", a[last].id, a[last].a, a[last].b);
  for(int i=2; i<=n; i++) if(a[last].b <= a[i].a) {
    last = i;
    printf("ext[%d] (%d, %d) chosen.\n", a[last].id, a[last].a, a[last].b);
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

*/
