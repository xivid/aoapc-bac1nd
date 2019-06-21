#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<ctime>
#define maxn 10000010
int n, a[maxn]={0}; 
long long n3(){
    long long max=a[1], sum=0;
    for(int i=1; i<=n; i++)
      for(int j=i; j<=n; j++){
          sum = 0;
          for(int k=i; k<=j; k++) sum+=a[k];    
          if(max < sum) max =sum;
      }
     return max;
}
long long s[maxn];
long long n2(){
    long long max = a[1];
    s[0] = 0;
    for(int i=1; i<=n; i++) s[i] = s[i-1] + a[i];
    for(int i=1; i<=n; i++)
      for(int j=i; j<=n; j++)
        if(s[j] - s[i-1] > max) max = s[j] - s[i-1];
    return max;
}
long long nlogn(int l, int r) { //[l,r)
    if(l+1 == r) return a[l];
    int m = l + (r - l)/2;
    long long max = nlogn(l, m);
    long long v = nlogn(m, r);
    if(v > max) max = v;
    long long lmax = a[m-1], rmax = a[m];
    v = 0; 
    for(int i = m-1; i>=l; i--) {v+=a[i]; if(v>lmax) lmax = v;}
    v = 0; 
    for(int i = m; i < r; i++) {v+=a[i]; if(v>rmax) rmax = v;}
    if(lmax+rmax > max) max = lmax+rmax;
    return max;
}
long long n1() {
    s[0] = 0;
    long long min=0, best = 0;
    for(int i=1; i<=n; i++) s[i] = s[i-1] + a[i];
    for(int j=1; j<=n; j++){
        if(s[j]-min>best)  best = s[j] - min;
        if(s[j]<min) min = s[j];
    }    
    return best; 
}
long long ngreedy(){
    long long t = 0;
    for(int i=1; i<=n; i++){
        if(t<0) t=a[i];
        if(t+a[i]>t) t+=a[i];
    }    
    return t;
}     
long long ndp(){
    long long t = 0, max = a[1];
    for(int i = 1; i<=n; i++){
        if(t+a[i]<0) t=a[i];
        else t+=a[i];
        if(t>max) max = t;
    }
    return max;
}        
int main(){
    srand(time(NULL));
    scanf("%d", &n);
    for(int i=1; i<=n; i++) a[i] = rand();
    long long ans6 = ndp();
    printf("O(n) DP : %lld\n", ans6);
    long long ans5 = ngreedy();
    printf("O(n) greedy : %lld\n", ans5);
    long long ans4 = n1();
    printf("n : %lld\n", ans4);
    long long ans3 = nlogn(1, n+1);
    printf("nlogn : %lld\n", ans3);    
    long long ans2 = n2();
    printf("n^2 : %lld\n", ans2);
    long long ans1 = n3();
    printf("n^3 : %lld\n", ans1);

    assert(ans1 == ans2 && ans2 == ans3 && ans3 == ans4 && ans4 == ans5);
    system("pause");
    return 0;
}    
