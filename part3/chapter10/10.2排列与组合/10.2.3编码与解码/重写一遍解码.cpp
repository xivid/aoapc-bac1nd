#include<cstdio>
#include<cstring>
char s[100], ans[100], len;
int code; //粗心错也是错！！一开始把code 声明成了char！ 
int count[255];
int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
int f(){
  int div = 1, cnt = 0;
  for(int i = 0; i < 255; ++i) if(count[i]){
    cnt += count[i];
    div *= fact[count[i]];
  }
  return fact[cnt] / div;
}  
bool encode(int left, int cur){
  if(cur == len) {
    for(int i = 0; i < 255; ++i) if(count[i]) {
      ans[cur] = i;
      ans[cur+1] = '\0';
      break;
    }
    return true;
  }
  int now = 0;
  for(int i = 0; i < 255; ++i) if(count[i]){
    --count[i];
    int F = f();
    now += F;
    if(now >= left){
      ans[cur] = i;
      if(encode(left-now+F, cur+1)) return true;
    }  
    ++count[i];
  }
  return false;
}    
int main(){
  scanf("%s %d", s, &code);
  len = strlen(s) - 1;
  memset(count, 0, sizeof(count));
  for(int i = 0; i <= len; ++i) ++count[s[i]];
  if(encode(code, 0)) printf("%s", ans);
  else printf("Wrong\n");
  return 0;
}  
