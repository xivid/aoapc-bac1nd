#include <cstdio>
#include <cstring>
void gcd(int a, int b, int& d, int &x, int& y){
  if(!b) {d = a; x = 1; y = 0;}
  else {gcd(b, a%b, d, y, x); y-=x*(a/b);}
}  
int main(){
  int a, b, x, y, d;
  scanf("%d%d", &a, &b);
  gcd(a, b, d, x, y);
  printf("%d*%d + %d*%d = %d\n", a, x, b, y, d);
  while(1);
  return 0;
}  
  
