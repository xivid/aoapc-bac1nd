#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define MAXN 50
///O(N!)
int vis[MAXN];
void print_permutation(int n, int A[], int cur){ // cur == current
  if(cur == n) {
    for(int i=0; i<n; i++) printf("%d ",A[i]);
    putchar('\n');
  }
  else for(int i=1; i<=n; i++) if(!vis[i]){
      vis[i] = 1;
      A[cur] = i;
      print_permutation(n, A, cur+1);
      vis[i] = 0;
  }
}
int main(){
  memset(vis, 0, sizeof(vis));
  int n, A[MAXN];
  scanf("%d",&n);
  print_permutation(n, A, 0);
  printf("n=%d,way2 time used: %.2lf\n",n, (double)clock()/CLOCKS_PER_SEC);
  return 0;
}
