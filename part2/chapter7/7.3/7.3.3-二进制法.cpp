#include<cstdio>
//#include<ctime>
void print_subset(int n, int s){
    for(int i=0; i<n; i++)
      if(s&(1<<i)) printf("%d ", i);
    printf("\n");
}
int main(){
    //freopen("time.txt","a",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0; i<(1<<n); i++)
      print_subset(n, i);
    //printf("n=%d, way3 time used: %.6lfs\n",n, (double)clock()/CLOCKS_PER_SEC);
    return 0;
}
