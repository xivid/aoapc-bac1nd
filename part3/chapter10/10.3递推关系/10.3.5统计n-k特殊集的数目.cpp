#include<iostream>
#include<cstring>
#define f(i, j) (f[(i)+1][(j)+1])
using namespace std;
const int maxn = 200, maxk = 500;
typedef int bign;//bignÉ¾µôÕâ¾ä×Ô¼º»» 
bign f[maxn+10][maxk+10]; 
int main(){
  int n, k;
  cin >> n >> k;
  for(int i = -1; i <= k; ++i) f(-1, i) = f(0, i) = 0; //i=0?
  f(-1, -1) = f(0, -1) = 1;
  for(int i = 1; i <= n; ++i)
    for(int j = -1; j <= k; ++j){
      f(i, j) = f(i-1, j);
      if(j >= i) f(i, j) += f(i-2, j-i);
      else f(i, j) += f(i-2, -1);
    }
  cout << f(n, k) << endl;
  while(1);  
  return 0;
}   
