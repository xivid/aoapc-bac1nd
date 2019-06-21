#include<cstdio>
#include<cstdlib>
int main(){
  double a, c, l, r, m, f;
  int b;
  scanf("%lf%d%lf", &a, &b, &c);
  l = 0; r = 100;
  while(r - l > 1e-5){
    m = l + (r-l) / 2;
    f = a;
    for(int i = 1 ; i <= b; i++) f += m * f/100.0 - c;
    if(f<0) l = m;
    else r = m;
  }
  printf("%.3lf%%\n", l);
  return 0;
}
