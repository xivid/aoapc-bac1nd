#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXD 10
#define MAX 2147483647
int gcd(int a, int b){
    int t= a%b;
    while(t){ a=b; b=t;  t=a%b;}
    return b;
}        
int g;
int depth;
int ans[MAXD], d[MAXD], found;
void dfs(int a, int b, int cur){
    if(cur == depth + 1) return;
    if(!(b%a) && b/a>d[cur-1]){
        d[cur]=b/a;
        if(!found || d[cur]<ans[cur]) memcpy(ans, d, sizeof(d));
        found = 1;
    }        
    
    int l, r;
    l = b/a;
    if(l<=d[cur-1]) l = d[cur-1] + 1;
    r = (depth-cur+1)*b/a;
    if(r > MAX/b) r= MAX/b;
    if(found && r>=ans[depth]) r = ans[depth] - 1;
    
    for(int i=l; i<=r; i++){
      d[cur] = i;
      g=gcd(a*i-b, b*i);
      dfs((a*i-b)/g, b*i/g, cur+1);
    }    
}
int main(){
   int a,b;
   scanf("%d%d", &a, &b);
   g=gcd(a, b); a/=g; b/=g;
   memset(ans, 0, sizeof(ans));
   memset(d, 0, sizeof(d));
   found = 0;
   for(depth=1; depth<=MAXD; depth++){
       dfs(a, b, 1);
       if(found) {
           printf("%d/%d =",a, b);
           for(int i=1; i<depth; i++) printf(" 1/%d +", ans[i]); printf(" 1/%d\n", ans[depth]);
           //now that the answer is found at this depth, the length must at be this depth too
           break;
       }    
   }    
   system("pause");
   return 0;
}     
