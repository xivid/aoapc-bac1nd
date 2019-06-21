#include<cstdio>
#include<cstdlib>
#define MAXN 50
///O(N!)
void print_permutation(int n, int A[], int cur){ // cur == current
  if(cur == n) {
    for(int i=0; i<n; i++) printf("%d ",A[i]);
    putchar('\n');
  }
  else for(int i=1; i<=n; i++){
    int ok = 1;
    for (int j=0; j<cur; j++) if(A[j] == i) {ok = 0; break;} //再次强调，静态查错，不经大脑的写错变量用这种方式是最容易查出来的
    if(ok) {
      A[cur] = i;
      print_permutation(n, A, cur+1);
    }
  }
}
int main(){
  int n, A[MAXN];
  //scanf("%d",&n);
  n = 8;
  print_permutation(n, A, 0);
  return 0;
}
