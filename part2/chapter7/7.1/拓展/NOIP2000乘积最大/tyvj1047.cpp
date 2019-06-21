#include<cstdio>
#include<cstdlib>
#include<cstring>
int n,k;
const int MAXN = 40, MAXK = 5;
int num[41];
struct bign{
  int s[41],len;
  bign() {memset(s,0,sizeof(s)); len=1;}
  bign(int x) {*this=x;}
  bign(const char a[]){*this=a;}
  bign operator =(const char a[]){
    len=strlen(a);
    for(int i=1; i<=len; i++) s[i] = a[len-i] - '0';
    this->clear();
    return *this;
  }
  bign operator =(int x){
    char a[41];
    sprintf(a,"%d",x);
    *this = a;
    return *this;
  }
  bool operator >(bign& y){
    if(len>y.len) return true;
    if(len<y.len) return false;
    for(int i=len; i>0; i--)
      if(s[i] > y.s[i]) return true;
      else if(s[i] < y.s[i]) return false;
    return false;
  }
  void clear(){
    while(s[len]==0) len--;
  }
  bign operator *(bign& x){
    bign ans;
    ans.len=len+x.len;
    for(int i=1;i<=len;i++)
      for(int j=1; j<=x.len; j++){
        ans.s[i+j-1]+=s[i]*(x.s[j]);
      }
    for(int i=1;i<=ans.len;i++) {ans.s[i+1]+=ans.s[i]/10; ans.s[i]%=10;}
    ans.clear();
    return ans;
  }
  void writeln(){
    for(int i=len;i>0;i--) printf("%d",s[i]);
    putchar('\n');
  }
};
bign sum[MAXN + 1][MAXN + 1];
void getsum(){
  for(int l=1; l<=n; l++)
    for(int r=l; r<=n; r++){
      bign ret;
      for(int i=r; i>=l; i--) {ret.s[ret.len] = num[i]; if(i>l) ret.len++;}
      ret.clear();
      sum[l][r] = ret;
    }
}
bign F[MAXN + 1][MAXK + 1];
int main(){
  char buf[41];
  scanf("%d%d",&n,&k);
  scanf("%s",buf);
  for(int i=1;i<=n;i++) num[i] = buf[i-1] - '0';

  getsum();
  for(int i=1; i<=n; i++) F[i][0] = sum[1][i];
  bign max,tmp;
  for(int i=1; i<=n; i++)
   for(int j=1; j<=k; j++){
      max = 0;
      for(int m=1; m<i; m++){
        tmp = F[m][j-1] * sum[m+1][i];
        if(tmp>max) max = tmp;
      }
      if(max > F[i][j]) F[i][j] = max;
   }

   F[n][k].writeln();
  return 0;
}
/*
样例输入 SampleInput
4 2
1231

样例输出 SampleOutput
62
*/
