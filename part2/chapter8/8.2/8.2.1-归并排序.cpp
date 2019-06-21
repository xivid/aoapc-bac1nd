#include<cstdio>
#include<cstdlib>
#include<ctime>
const int maxn = 100000;
int t[maxn]; 
void mergesort(int* a, int l, int r){
    if(l + 1 < r) {  //数组中有至少两个元素才排，改为if(i+1==r) return;也可 
        int m = l + (r-l)/2;
        mergesort(a, l, m);
        mergesort(a, m, r);
        int p = l, q = m, i = l;
        while(p<m || q<r){
            if(q>=r || (p<m && a[p] <= a[q])) t[i++] = a[p++];
            else t[i++] = a[q++];
        }
        for(i = l; i < r; i++) a[i] = t[i];    
    }    
}       
int n, a[maxn];
int main(){
    srand(time(NULL));
    scanf("%d", &n);
    for(int i = 1; i<=n ;i++) a[i] = rand();
    mergesort(a, 1, n+1);
    for(int i = 1; i<=n ;i++) printf("%d ", a[i]);
    while(1);
    return 0;
}    
