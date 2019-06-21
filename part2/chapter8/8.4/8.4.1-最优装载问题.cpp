#include<cstdio>
#include<cstdlib>
#include<cstring>
const int maxn = 10000;
int n, c;
int w[maxn], a[maxn];
//O(N)桶排序完爆DP
int main(){
  memset(w,0,sizeof(w));
  memset(a,0,sizeof(a));
  scanf("%d%d",&n,&c);
  int maxw=-1, t=0, sum=0, num=0;
  for(int i=1; i<=n; i++) {scanf("%d",w+i); a[w[i]]++; if(w[i]>maxw) maxw=w[i];}
  for(int i=1; i<=maxw; i++) if(a[i])
    while(a[i]--) w[++t] = i;
  for(int i=1; i<=n; i++) {if(sum+w[i]<=c) {sum+=w[i]; num++;} else break;}
  printf("%d\n",num);
  return 0;
}
