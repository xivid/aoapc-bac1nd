/***************************************\
*解方程 ax ≡b (mod n) 各数范围 1~10^9  * 
* ax % n = b % n                        *
* (ax - b) % n = 0                      *
* ax - b = ny                           *
* ax - ny = b                           *
* d = gcd(a, n)                         *
* if b % d == 0                         *
*   ax - ny = d => x1, y1               *
*   x = x1*b/d(, y = y1*b/d)            *
* else                                  *
*   NO ANSWER                           *
\***************************************/
#include <cstdio>
#include <cstdlib> 
void gcd(int a, int b, int& d, int& x, int &y){
  if(!b) {d = a; x = 1; y = 0;}
  else {gcd(b, a%b, d, y, x); y-=x*(a/b);}
}  
int main(){
  int a, x, b, n, x1, y1, d;
  scanf("%d%d%d", &a, &b, &n);
  gcd(a, n, d, x1, y1);
  if(b % d == 0) {
    x = x1*b/d;
    printf("x = %d\n", x);
  }  
  else printf("No Answer.\n");
  while(1);
  return 0;
}  
