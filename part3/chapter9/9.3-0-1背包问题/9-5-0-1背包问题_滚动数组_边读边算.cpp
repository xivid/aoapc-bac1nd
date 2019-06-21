//online judge: TYVJ P1005 ≤…“© 
#include<cstdio>
#include<cstring>
const int maxt = 1010; 
int T, M, v, t, f[maxt];
int main(){
    scanf("%d%d", &T, &M);
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= M; ++i) {
        scanf("%d%d", &t, &v);
        for(int j = T; j >= 0; --j){
            if(j>=t && f[j-t] + v > f[j]) f[j] = f[j-t] + v;
        }
    }
    printf("%d\n", f[T]);
    return 0;
}   
