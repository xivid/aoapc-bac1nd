#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;
const int MAXK = 10001;
int gcd(int a, int b){int t; while(b){t=a%b; a=b; b=t;} return a;} 
int x[MAXK], k;
int judge(int* x){
  x[k+1] = x[1];
  for(int i = 3; i <= k+1; ++i) {
    x[2]/=gcd(x[2], x[i]);
    if(x[2]==1) break;
  }
  return x[2]==1;
}     
int main(){
  freopen("in2.txt", "r", stdin);
  char c; int t = 0, n = 1;
  while((c=getchar())!=EOF) {
      if(isdigit(c)) t = t*10 + c - '0';
      else if(c=='/') {x[n++] = t;  t = 0;}
      else if(c=='\n') {
          x[n] = t;
          k = n;
          if(judge(x)) printf("YES\n"); else printf("NO\n");
          n = 1;
          t = 0;
      }
  }           
  return 0;
}
