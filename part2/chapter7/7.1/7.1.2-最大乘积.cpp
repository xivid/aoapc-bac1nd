#include<cstdio>
#include<cstdlib>
#include<cstring>
int main(){
  int S[30],n,ml,mr;
  long long ans,tmp;
  while(scanf("%d",&n) == 1){
    ans=-1;
    memset(S,0,sizeof(S));
    for(int i=1; i <= n; i++) scanf("%d",&S[i]);
    for(int l=1; l <= n; l++)
     for(int r=n; r >= l; r--){
       tmp=1;
       for(int k=l; k<=r; k++) tmp*=S[k];
       if(tmp > ans) {ans = tmp; ml=l;mr=r;}
     }
    //tmp=1;
    //printf("l:%d,r:%d\n",ml,mr);
    //for(int j=ml; j<=ml; j++) printf("S[%d]=%d\n",j,S[j]); //这一行注释掉和不注释掉，最终结果竟然不同有木有！！
    //for(int i=ml; i<=mr; i++) {printf("%lld*%d=%lld\n",tmp,S[i],tmp*S[i]); tmp*=S[i];}
    printf("%lld\n",ans>0?ans:-1ll);
  }
  return 0;
}
/*
20
13 2 -12 2 23 -32 -5 -2 19 23 5 -2 6 7 -8 9 10 -23 -5 -3
ANS:69794864455680000
*/
///拓展：NOIP2000 乘积最大（动态规划）
