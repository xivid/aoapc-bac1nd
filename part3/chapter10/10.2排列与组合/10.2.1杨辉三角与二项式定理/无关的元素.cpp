#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<bitset>
using std::bitset;
int n, m, p[20]={0}, a[20]={0}, b[20]={0};
bitset<10010> flag;
int main(){
  scanf("%d%d", &n, &m);
  int k = 0;//质因数的个数 
  for(int i = 2; i <= m; ++i) if(m % i == 0){
    p[++k] = i; a[k]=0;
    while(m%i==0) { m/=i; a[k]++;}
    if(m<=1) break;
  }  
  flag.reset();
  int mid = (n-1)/2;
  for(int i = 1; i <= mid; ++i){
    int t = n-i, yes = 1;
    for(int j = 1; j <= k; ++j) {
      if(t % p[j] == 0) while(t%p[j]==0) {t/=p[j]; b[j]++;}
      if(b[j]<a[j]) yes = 0;
    }
    t = i;
    for(int j = 1; j <= k; ++j) {
      if(t % p[j] == 0) while(t%p[j]==0) {t/=p[j]; b[j]--;}
      if(b[j]<a[j]) yes = 0;
    }
    if(yes){
      //if(i==mid) printf("a%d ", mid+1); 
      //else printf("a%d a%d ", i+1, n-i); //如果需要按序输出，可以记到一个bitset里 
      flag[i+1] = flag[n-i] = 1;
    }  
  }  
  for(int i = 1; i <= n; ++i) if(flag[i]) printf("a%d ", i);
  while(1);
  return 0;
}   
