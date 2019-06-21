///输入n，输出0..n-1的所有2^n个子集（定序，从小到大）
#include<cstdio>
#include<cstdlib>
//#include<ctime>
void print_subset(int n, int *A, int cur){
   for(int i=0; i<cur; i++) printf("%d ",A[i]);
   printf("\n"); //首行为空，代表空集
   int s = cur ? A[cur-1]+1 : 0;
   for(int i=s; i<n; i++){
       A[cur] = i;
       print_subset(n, A, cur+1);
   }
}
const int maxn = 50;
int main(){
   //freopen("time.txt","a",stdout);
   int n, A[maxn];
   //n = 30;
   scanf("%d",&n);
   print_subset(n, A, 0);
   //printf("n=%d, way1 time used: %.6lfs\n",n, (double)clock()/CLOCKS_PER_SEC);
   return 0;
}
