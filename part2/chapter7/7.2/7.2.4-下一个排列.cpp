#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
  int n, P[100];
  scanf("%d",&n);
  for(int i=0; i<n; i++) scanf("%d",P+i);
  sort(P,P+n);
  do{
    for(int i=0; i<n; i++) printf("%d ",P[i]);
    printf("\n");
  }while(next_permutation(P, P+n));
  return 0;
}
