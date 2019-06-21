#include<cstdio>
int s[30];
//经测试，把函数或循环体里所有变量都拿出来不一定比放在里面快,inline不一定更快
bool ok(int n){
  int ans = 0, base = 10;
  bool flag;
  do{
    int l=-1, t=n;
    do{
      s[++l] = t % base;
      t/=base;
    }while(t);
    flag = true;
    for(int i=0; i<=l; i++) if(s[i]!=s[l-i]) {flag=false; break;}
    if(flag) ans++;
    base--;
  }while(base>=2 && ans<2);
  if(ans == 2) return true;
  return false;
}
int main()
{
  int n;
  scanf("%d",&n);
  //n = 1600000;
  n++; //require a number that is BIGGER than n(what if input n 1632995?)
  for(;!ok(n);n++);
  printf("%d\n",n);
  return 0;
}
//1632995: base 6,2
