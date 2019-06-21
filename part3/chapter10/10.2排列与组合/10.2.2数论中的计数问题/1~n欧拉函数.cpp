#include<iostream>
#include<cmath>
#include<cassert>
#include<cstring>
using namespace std;
int phi[8000001];
int main(){
  int n; 
  cin >> n;
  assert(n <= 8000000);
  memset(phi, 0, sizeof(phi));
  phi[1] = 1; //O(nloglogn)
  for(int i = 2; i <= n; ++i) if(!phi[i]){ //只算质数i，因为合数i对应的phi[i]已经被前面的质数i在内层j循环中筛完了 
    for(int j = i; j <= n; j+=i){
      if(!phi[j]) phi[j] = j;
      phi[j] = phi[j] / i * (i-1);
    }
  }    
  for(int i = 1; i <= n; ++i) printf("phi(%d) = %d\n", i, phi[i]);
  while(1);
  return 0;
}  
    
