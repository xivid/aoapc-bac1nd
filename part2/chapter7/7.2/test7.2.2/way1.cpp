#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#define MAXN 100
void qsort(int a[], int l, int r){
  // 其实这快排和取中快排比起来效率还是很渣的
  if(l>=r) return;
  int i=l, j=r, x=a[(i+j)>>1]; a[(i+j)>>1] = a[i]; a[i] = x;
  do{
    while(i<j && a[j] >= x) j--; if(i<j) {a[i] = a[j]; i++;}
    while(i<j && a[i] <= x) i++; if(i<j) {a[j] = a[i]; j--;}
  }while(i!=j);
  a[i] = x;
  qsort(a, l, i-1); qsort(a, i+1, r);
}
void print_permutation(int n, int P[], int A[], int cur){
  if(cur == n) {
    for(int i=0; i<n; i++) ;//printf("%d ",A[i]);
    //putchar('\n');
  }
  else for(int i=0; i<n; i++) if(!i || P[i] != P[i-1]) {
    //if的意�? 对于重复元素（排序后已经挨在一起），只试它们中的第一个，其余跳过
    //P[0]是必然要试的：若有多个等于P[0]的值，P[0]必为第一�?0-1=-1不在数组下表范围�?；若只有一个，更理所当然地要试P[0]�?!i即为i==0)
    int c1 = 0, c2 = 0;
    for(int j=0; j<cur; j++) if(A[j] == P[i]) c1++;
    for(int j=0; j<n; j++) if(P[j] == P[i]) c2++;
    if(c1 < c2) {
      A[cur] = P[i];
      print_permutation(n, P, A, cur+1);
    }
  }
}
int main(){
  freopen("722.in", "r", stdin);
  freopen("722time.txt", "a", stdout);
  int n, A[MAXN], P[MAXN];
  scanf("%d",&n);
  for(int i = 0; i < n; i++) scanf("%d",&P[i]);
  //n = 4;
  std::sort(P,P+n);
  //for(int i= 0;i< n;i++) printf("%d ",P[i]);
  print_permutation(n, P, A, 0);
  printf("n=%d, way1 time used: %.4lfs\n",n, (double)clock()/CLOCKS_PER_SEC);
  return 0;
}
//10    2 4 0 3 1 9 7 6 2 7