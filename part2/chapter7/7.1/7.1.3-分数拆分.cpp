#include<cstdio>
#include<cstdlib>
int main(){
  int x,y,k;
  while(scanf("%d",&k) == 1){
    for(y=k+1; y<=(k<<1); y++){
      x=((k*y)%(y-k))?0:((k*y)/(y-k));
      if(x) printf("1/%d = 1/%d + 1/%d\n",k,x,y);
    }
  }
  return 0;
}
