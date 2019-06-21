#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define maxn 20
//input n, make 1~n a circle in which every two neighbour numbers together make a prime
int main(){
  int n, a[maxn], isprime[maxn<<1]={0}, ok, ans;
  scanf("%d",&n);
  //n=14;
  ans=0;
  for(int i=2; i<=(n<<1); i++){
    ok = 1;
    for(int j=2; j*j<=i; j++) if(i % j == 0) ok = 0;
    if(ok) isprime[i] = 1;
  }
  for(int i=0; i<n; i++) a[i] = i+1;
  do{
    ok = 1;
    for(int i=0; i<n; i++) if(!isprime[a[i]+a[(i+1)%n]]) {ok = 0; break;}
    if(ok) {
      for(int i=0;i<n;i++) printf("%d ",a[i]); printf("\n");
      ans++;
      }
  }while(next_permutation(a+1,a+n));
  printf("ans=%d\n",ans);
  return 0;
}
