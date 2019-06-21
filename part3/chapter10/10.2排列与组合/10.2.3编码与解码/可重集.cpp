#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ull unsigned long long
char s[100], ori[100], minchar;
int chrcount[255];//记录每个字符的出现次数，支持ASCII码0~254的字符
size_t len;
ull code;
ull fact[21] = {1ull, 1ull, 2ull, 6ull, 24ull, 120ull, 720ull, 5040ull, 40320ull, 362880ull, 3628800ull, 39916800ull, 479001600ull, 6227020800ull, 87178291200ull, 1307674368000ull, 20922789888000ull, 355687428096000ull, 6402373705728000ull, 121645100408832000ull, 2432902008176640000ull};
ull f(int* chrcount){
  ull div = 1, tot = 0;
  for(int i = 0; i < 255; ++i) if(chrcount[i]){
    tot += chrcount[i];
    div *= fact[chrcount[i]];
  }
  return (fact[tot] / div);
}
ull encode(char* str, int pos){
  if(pos == len) return 0;
  ull ret = 0;
  for(char i = minchar; i < str[pos]; ++i) if(chrcount[i]){
    --chrcount[i];
    ret += f(chrcount);
    ++chrcount[i];
  }
  --chrcount[str[pos]];
  ret += encode(str, pos+1);
  return ret;
}
bool decode(char* str, char* ans, ull code, int cur){//构造字符串
  //经验：凡是有构造功能的函数，通常有一个参数cur表示当前构造位置，并用来判断递归是否终止
  if(cur == len){
     //on error make ans "Input too large!"
     for(int i = 0; i < 255; ++i) if(chrcount[i]){
      ans[cur] = i;
      ans[cur+1] = '\0';
     }
     return true;
  }
  ull now = 0;
  for(int i = 0; i < 255; ++i) if(chrcount[i]){
    --chrcount[i];
    int F = f(chrcount);
    now += F;
    if(now >= code){ //now >= code若怎么也成立不了，就return false了
      ans[cur] = i;
      if(decode(str, ans, code - now + F, cur + 1)) return true;
      //这是试构造，真的可以（返回true）才跳出，否则重新尝试此位置的字符
    }
    ++chrcount[i];
  }
  return false;
}
int main(){
  memset(chrcount, 0, sizeof(chrcount));
  scanf("%s", s);
  len = strlen(s) - 1;
  minchar = s[0];
  for(int i = 0; i <= len; ++i) {
    chrcount[s[i]]++;
    if(s[i] < minchar) minchar = s[i];
  }
  printf("%lld\n", code = encode(s, 0) + 1);

  sort(s, s+len+1); //打乱顺序，生成符号表，可以理解为新输入了一个有序的可重字符集合
  len = strlen(s) - 1;
  memset(chrcount, 0, sizeof(chrcount));
  for(int i = 0; i <= len; ++i) ++chrcount[s[i]];
  //printf("%s\n", decode(s, ori, code, 0));
  if(decode(s, ori, code, 0)) printf("%s\n", ori);
  return 0;
}
