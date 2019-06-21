//C(n, k) =  C(n, k-1)*(n-k+1)/k
#include<cstdio>
#include<cstdlib>
const int maxl = 66;
unsigned long long c[maxl]; 
int main(){
  int n, k;
  scanf("%d%d", &n, &k);
  c[0] = 1; c[1] = n;
  for(int i = 2; i <= k; ++i) c[i] = c[i-1] * (n-i+1) / i;
  printf("%lld\n", c[k]);
  return 0; 
} 
