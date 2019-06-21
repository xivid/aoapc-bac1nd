#include<stdio.h>
#include<stdlib.h>
const int maxn=500;
int main(){
    int n,queue[maxn],front=1,rear=1,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) queue[rear++]=i;
    while(front<rear){
      printf("%d ",queue[front++]);
      queue[rear++]=queue[front++];
    }
    printf("\n");
    return 0;
}
