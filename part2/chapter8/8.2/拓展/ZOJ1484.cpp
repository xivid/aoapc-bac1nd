#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxn 5010
int ans, min;
int a[maxn], t[maxn], ori[maxn], n;
void count(int l, int r){
    if(l+1<r){
        int m = l + (r-l)/2;
        count(l, m);
        count(m, r);
        int p = l, q = m, i=l;
        while(p<m || q<r){
            if(q>=r || (p<m&&a[p]<=a[q])) t[i++] = a[p++];
            else {t[i++] = a[q++]; ans+=m-p;}
        }
        for(i=l; i<r; i++) a[i] = t[i];
    }
}
int main(){
    while(scanf("%d", &n) == 1){
      memset(a, 0, sizeof(a));
      memset(t, 0, sizeof(t));
      for(int i=0; i<n; i++) {scanf("%d", &a[i]); ori[i] = a[i];}
      ans = 0;
      count(0, n);
      min = ans;
      for(int start=0; start<n; ++start){
        ans += n - 1 - 2*ori[start];
        if(ans < min) min = ans;
      }
      printf("%d\n", min);
    }
    return 0;
}
