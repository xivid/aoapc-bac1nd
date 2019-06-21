//使用高精度类
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXK = 10001;

int x[MAXK], k;
const int BIGNMAXL = 90010;
struct bign{
  short s[BIGNMAXL], len;
  bign(){memset(s, 0, sizeof(s)); len = 1;}
  void clear(){
    while(len > 1 && s[len]==0) --len;
  }
  string str() const{
    string a;
    for(int i = len; i>0; --i) a+=char(s[i]+'0');
    if(a=="") a="0";
    return a;
  }
  bign operator = (const char* p){
    len = strlen(p);
    for(int i=1;i<=len;++i) s[i] = p[len - i] - '0';
    clear();
    return *this;
  }
  bign operator = (const int& p){
    char a[100];
    sprintf(a, "%d", p);
    *this = a;
    return *this;
  }
  bign(const char* p){*this = p;}
  bign(int p){*this = p;}
  bign operator *(const bign& b){
    bign ans;
    ans.len = b.len + len;
    for(int i = 1; i <= len; ++i)
      for(int j = 1; j <= b.len; ++j)
        ans.s[i+j-1] += s[i] * b.s[j];
    for(int i = 1; i <= ans.len; ++i) {ans.s[i+1]+=ans.s[i]/10; ans.s[i]%=10;}
    ans.clear();
    return ans;
  }
  bign operator *=(const bign& b){*this = (*this) * b; return *this;}
  int operator %(int b){
    int t=0;
    bign ans;
    for(int i = len; i > 0; --i){
      t = t * 10 + s[i];
      ans.s[i] = t/b;
      if(ans.s[i]) t%=b;
    }
    return t;
  }
};
ostream& operator <<(ostream& out,const bign& x){
  out << x.str();
  return out;
}
int main(){
  //typedef int bign;
  freopen("in.txt", "r", stdin);
  scanf("%d", &k);
  for(int i = 1; i <= k; ++i) scanf("%d", x+i);
  bign up = x[1];
  int down = x[2];
  for(int i = 3; i <= k; ++i) up*=x[i];
  if(up%down) printf("No\n");
  else printf("Yes\n");
  /*   TEST
  up = 2147483647;
  down = 10007;
  cout << up%down << endl;
  */
  while(1);
  return 0;
}
