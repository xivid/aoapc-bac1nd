#include<cstdio>
#include<cstdlib>
#define maxl 70 + 10
int n, L, cnt, s[maxl];
int dfs(int cur){
  if(cnt++ == n) {
    for(int i=0; i<cur; i++) printf("%c",'A'+s[i]); printf("\n");
    return 0;
  }
  for(int i=0; i<L; i++){
    s[cur] = i;
    int ok = 1;
    for(int j=1; j+j<=cur+1; j++){
      int equal = 1;
      for(int k=0; k<j; k++) if(s[cur-k]!=s[cur-k-j]) {equal=0; break;}
      if(equal) {ok=0; break;}
    }
    if(ok) if(!dfs(cur+1)) return 0;
  }
  return 1;
}
int main(){
  scanf("%d%d",&n,&L);
  cnt = 0;
  if(dfs(0)) printf("Not Found!\n");
  return 0;
}
