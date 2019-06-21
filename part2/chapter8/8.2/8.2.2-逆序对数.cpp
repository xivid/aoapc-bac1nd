#include<cstdio>
#include<cstdlib>
#include<ctime>
const int maxn = 100000;
int ans, t[maxn];
void count(int *a, int l, int r){
    if(l+1 < r){
        int m = l + (r-l)/2;
        count(a, l, m);
        count(a, m, r);
        int p = l, q = m, i = l;
        while(p<m || q<r){
            if(q>=r || (p<m && a[p] <= a[q])) t[i++] = a[p++];
            else {t[i++] = a[q++];ans += m - p; }//说明左边比a[q]小的都复制完了 
            
        }    
        for(i = l; i < r; i++) a[i] = t[i];
    }
}        
int n, a[maxn];
int main(){
    srand(time(NULL));
    //srand(1);
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", a+i);//a[i] = rand();
    ans = 0;
    count(a, 1, n+1);
    printf("%d\n", ans);
    while(1);
    return 0;
}    
