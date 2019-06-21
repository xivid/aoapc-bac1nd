#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
#define maxn 110
int main(){
  char s[maxn];
  int m, len, ans = 0;
  scanf("%s%d", s, &m);
  len = strlen(s);
  for(int i = 0; i < len; ++i) ans = (int)(((long long)ans * 10 + s[i] - '0') % m);
  printf("%d\n", ans);
  return 0;
}  
