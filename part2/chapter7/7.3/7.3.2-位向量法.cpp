#include<cstdio>
#include<cstdlib>
#include<ctime>
const int maxn = 50;
void print_subset(int n, int B[], int cur){
    if(cur == n){
        for(int i=0; i<n; i++) if(B[i]) printf("%d ",i);
        printf("\n");
        return;
    }
    B[cur] = 1; //choose element cur
    print_subset(n, B, cur+1);
    B[cur] = 0; //not to choose element cur
    print_subset(n, B, cur+1);
}
int main(){
    //freopen("time.txt","a",stdout);
    int n;
    int B[maxn]={0};
    scanf("%d",&n);
    print_subset(n, B, 0);
    //printf("n=%d, way2 time used: %.6lfs\n",n, (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
