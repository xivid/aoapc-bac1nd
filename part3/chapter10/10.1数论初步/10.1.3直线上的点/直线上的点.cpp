#include<cstdio>
#include<cmath>
#include<cstdlib>
inline int max(int a, int b){return a > b ? a : b;}
inline int min(int a, int b){return a < b ? a : b;}
void extgcd(int a, int b, int& d, int& x, int& y){
  if(!b) {d = a; x = 1; y = 0;}
  else {extgcd(b, a%b, d, y, x); y-=x*(a/b);}
}
int main(){
  int a, b, c, d, x, y, x1, y1, x2, y2, x0, y0, l, r;
  scanf("%d%d%d%d%d%d%d", &a, &b, &c, &x1, &x2, &y1, &y2);
  extgcd(a, b, d, x, y);
  //if(d<0) {d = -d; x= -x; y= -y;}
  //printf("d=%d, x=%d, y=%d\n", d,x,y);
  if((-c)%d) printf("None\n");
  else {x0 = x*(-c)/d, y0 = y*(-c)/d;}  //据说x0、y0和某个东西有命名冲突 
  ///printf("x0=%d, y0=%d\n", x0,y0);
  l = min((x1-x0)/(b/d), (y0-y2)/(a/d)), r = max((x2-x0)/(b/d), (y0-y1)/(a/d));
  //printf("l=%d, r=%d\n", l, r); 
  if(l <= r) {
    int cnt = 0;
    for(int k = l; k <= r; ++k) {
      int nx = x0+k*(b/d), ny = y0-k*(a/d);
      if(nx >= x1 && nx <= x2 && ny >= y1 && ny <= y2) {cnt++; printf("(%d, %d)\n", nx, ny);}
    }
    if(cnt) printf("%d\n", cnt);
    else printf("None\n");  
  }  
  else printf("None\n");
  return 0;
}  
/*
Test case1:
3 7 15 2 9 2 9
Test case2:
1 -1 0 1 10 1 10 
*/

