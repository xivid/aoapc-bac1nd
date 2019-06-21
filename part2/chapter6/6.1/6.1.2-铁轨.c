#include<stdio.h>
#include<stdlib.h>
#define maxn 5000
int n,target[maxn],c[maxn];
int main(){
   freopen("stack.in","r",stdin);
   while(scanf("%d",&n)==1){
       int A=1,B=1,top=0,i,ok;
       for(i=1;i<=n;i++) scanf("%d",&target[i]);
       ok=1;
       while(B<=n){
         if(A==target[B]) {++A; ++B;}
         else if(top&&c[top]==target[B]) {top--; B++;}
         else if(A<=n) c[++top]=A++;
         else {ok=0; break;}
       }
       printf("%s\n",ok?"Yes":"No");
   }
   return 0;
}
