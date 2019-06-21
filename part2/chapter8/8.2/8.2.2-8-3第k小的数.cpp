#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
using namespace std;
int qsort(int a[], int l, int r, int k){
  if(l>r) return 0;
  int i = l, j = r, key = a[(l+r)>>1]; a[(l+r)>>1] = a[l];  a[l] = key;
  do{
    while(i<j && a[i] <= key) i++; if(i<j) {a[j] = a[i]; j--;}
    while(i<j && a[j] >= key) j--; if(i<j) {a[i] = a[j]; i++;}
  }while(i!=j);
  a[i] = key;
  if(i==k) return key;
  else{
    if(i>k) return(qsort(a, l, i-1, k));
    if(i<k) return(qsort(a, i+1, r, k));
  }
}
const int maxn = 1000;
int main(){
  srand(time(NULL));
  int a[maxn], n, k, ans;
  //scanf("%d",&n);
  n = rand() % maxn + 1;
  assert(n < maxn+1);
  k = rand() % (n-1) + 1;
  for(int i=1; i<=n; i++) a[i] = rand();//scanf("%d", a + i);
  printf("n=%d\n",n);
  ans = qsort(a,1,n,k);
  printf("the %dth smallest number is %d\n",k,ans);
  sort(a+1, a+n+1);
  for(int i=1; i<=n; i++) printf("[%d]%d ",i, a[i]); putchar('\n');
  return 0;
}
