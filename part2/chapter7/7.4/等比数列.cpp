///S=(b^L-1)/(b-1) b太大或L太大，结点数都会是一个天文数字？
#include<cstdio>
#include<cstdlib>
int main(){
  int b,L;
  //scanf("%d%d",&b,&L);
  for(b=2; b<=20; b++)
  for(L=2; b+L<=20; L++){
  unsigned long long s=1, t=1, l=L;
  while(--l){
    s+=(t*=b);
  }
  printf("b=%2d,L=%2d->%lld\n",b,L,s);
  }
  return 0;
}
