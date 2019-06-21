#include<cstdio>
#include<cstdlib>
#include<ctime>
int gcd(int a, int b){int t; while(b){ t=a%b; a=b; b=t; } return a;}
int maxn;
int main(){
    freopen("gcd.in", "r", stdin);
    freopen("gcd.time", "a", stdout);
    scanf("%d", &maxn);
    int a, b, g;
    for(a = 2; a <= maxn; a++)
      for( b = 2; b <= maxn; b++){
        g = gcd(a, b);
        }
    printf("#2 time used: %.4lfs\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}    
