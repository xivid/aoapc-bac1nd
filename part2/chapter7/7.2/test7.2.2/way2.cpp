#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define MAXN 100
#define MAXELEMENT MAXN
void print_permutation(int n, int P[], int A[], int cur, int C[]){
  if(cur == n){
    for(int i = 0; i < n; i++) ;//printf("%d ",A[i]);
    //printf("\n");
  }
  else for(int i = 0; i < n; i++) if(!i || P[i] != P[i-1]){
    int c1=0, c2=0;
    for (int j = 0; j < cur; j++) if(A[j] == P[i]) c1++;
    //for (int j = 0; j < n; j++) if(P[j] == P[i]) c2++;
    if(c1 < C[P[i]]){
      A[cur] = P[i];
      print_permutation(n, P, A, cur + 1, C);
    }
  }
}
int main(){
  freopen("722.in", "r", stdin);
  freopen("722time.txt", "a", stdout);
  int n, A[MAXN], P[MAXN], C[MAXELEMENT];
  //预处理C数组，从而去掉算c2的步骤（只适用于最大元素和元素个数数字相当的优化） 
  scanf("%d",&n);
  memset(C, 0, sizeof(C));
  for(int i=0; i<n; i++) {scanf("%d",P+i); C[P[i]]++;} 
  std::sort(P,P+n);
  print_permutation(n, P, A, 0, C);
  printf("n=%d, way2 time used: %.4lfs\n",n, (double)clock()/CLOCKS_PER_SEC);
  return 0;
}