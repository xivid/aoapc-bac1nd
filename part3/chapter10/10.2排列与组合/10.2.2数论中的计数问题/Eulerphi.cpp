#include<cstdio>
#include<cmath>
int euler_phi(int n){
    int s = (int)sqrt(n);
    int ans = n;
    for(int i = 2; i <= s; i++) if(n % i == 0){
        ans = ans / i * (i-1);
        while(n % i == 0) n/=i;
    }
    if(n > 1) {printf("n=%d>1\n", n); ans = ans / n * (n-1);}
    return ans;
}    
int main(){
    int n;
    while(scanf("%d", &n) == 1){
        printf("¦Õ(%d) = %d\n", n, euler_phi(n));
    } 
    return 0;
}    
