#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
int a, b, MAXD;
struct frac{
    int u, d;
    frac() { u=0; d=1;}
};    
int gcd(int a, int b){
    int t=a%b;
    while(t){
        a=b;
        b=t;
        t=a%b;
    }
    return b;    
}    
int found, ans[100]={0}, ansn=0, best[100]={0};
int dfs(frac s, int init, int d){
    int checker=b*(s.u)-a*(s.d);
    double remain = -(double)checker/(b*(s.d));
    if((int)ceil(init*remain)>MAXD-d+1) return 0;
    
    s.u=(s.u)*init+(s.d);
    s.d*=init;
    int g= gcd(s.u, s.d);
    s.u/=g; s.d/=g;
    ans[d]=init;
    
    checker=b*(s.u)-a*(s.d);
    if(checker>0) return -1;
    else if(checker == 0) {
        if(!found || best[d] > ans[d]){
          ansn=d;
          memcpy(best, ans, sizeof(ans));
          found = 1;
          return 1;
        }    
    }
    
    int flag = 0;
    remain = -(double)checker/(b*(s.d));
    while((int)ceil(init*remain)<=MAXD-d) {
        ++init;
        flag = dfs(s, init, d+1);
        if(flag!=-1) break;
    }
    if(flag == 1) {found=1; return 1;}
}    
int main(){
    scanf("%d%d", &a, &b);
    int init, flag;
    frac s;
    found = 0;
    for(MAXD = 2; MAXD <= 100; MAXD++){
        init = 1;
        flag = 0;
        while(1){
            flag = dfs(s, init, 1);
            if(flag == -1) init++; // s>n 
            else if(flag == 0) break; //over depth
        }    
        if(found){
            for(int i=1; i<=ansn; i++) printf("1/%d ", best[i]);
            putchar('\n');
            break;
        }    
    }    
    system("pause");
    return 0;
}    
