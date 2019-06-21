#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 10000
using namespace std;
int n, w[maxn], c, matched[maxn];
int main(){
  int i, j, left, cur;
  scanf("%d%d", &n, &c);
  memset(matched, 0, sizeof(matched));
  for(i=0; i<n; i++) scanf("%d", w+i);
  sort(w, w+n);
  i=0, j=n-1, cur = 0;
  while(i<j){
    while(w[i] + w[j] > c) j--;
    if(i<j) {
      matched[i] = matched[j] = 1;
      printf("Boat %d: %d and %d.\n", ++cur, w[i], w[j]);
      ++i; --j;
    }
  }
  for(int i=0; i<n; i++) if(!matched[i]) printf("Boat %d: %d alone.\n", ++cur, w[i]);
  return 0;
}
