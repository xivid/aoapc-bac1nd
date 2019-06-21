#include<cstdio>
#include<cstdlib>
#include<cstring>
const int n = 8;
int flag[3][20], ans; //!!!!数组别开小了！！0..2是3！！
int A[n];
void search(int step){
    if(step == n) {
        ans++;
        //for(int i=0; i<8; i++) printf("%d",A[i]);
        //printf("\n");
    }
    else for(int i=0; i<n; i++)
          if(!flag[0][i] && !flag[1][i+step] && !flag[2][n+step-i]){
            flag[0][i] = flag[1][i+step] = flag[2][n-i+step] = 1;
            A[step] = i;
            search(step+1);
            flag[0][i] = flag[1][i+step] = flag[2][n-i+step] = 0;
           }
}
int main(){
  memset(flag, 0, sizeof(flag));
  memset(A, 0, sizeof(A));
  ans = 0;
  search(0);
  printf("%d\n",ans);
  return 0;
}
