//全排列的编码解码，在八数码问题中有 
//此程序只适用于无重复元素的情况 
#include<cstdio>
#include<cassert>
#include<cstring>
#include<algorithm>
using namespace std; 
int fact[13];
void init_fact(int n){
  fact[0] = 1;
  for(int i = 1; i <= n; ++i) fact[i] = fact[i-1] * i;
}  
int encode(char* s, int n, int& code){
  int cnt;
  code = 0;
  for(int i = 0; i <= n; ++i){
    cnt = 0;
    for(int j = i+1; j <= n; ++j) if(s[j] < s[i]) ++cnt;
    code += fact[n-i] * cnt;
  }
  return code;
} 
char ori[13];
int used[13];
char* decode(char* s, int n, int code){
  memset(used, 0, sizeof(used));
  ori[0] = s[0];
  for(int i = 0; i <= n; ++i){ 
    int ord = code / fact[n-i] + 1, found = 0, j;
    for(j = 0; j <= n; ++j) {
      if(!used[j]) ++found;
      if(found == ord) break;
    }  
    used[j] = 1;
    ori[i] = s[j];
    code %= fact[n-i];
  }   
  return ori;
}  
int main(){
  char s[13];
  int n, code;
  scanf("%s", s);
  n = strlen(s) - 1;
  assert(n < 13);
  init_fact(n);
  printf("encode: %d\n", encode(s, n, code));
  sort(s, s+n+1); //打乱原顺序，顺便生成解码所需的符号表 
  printf("decode: %s\n", decode(s, n, code));
  while(1);  
  return 0;
}  
