#include<iostream>
#include<cstdio>
using namespace std;
int node[1050000];
int main(){
    int nn,nb;
    int e2[30];
    e2[0]=1;
    for(int i=1;i<30;i++) e2[i]=2*e2[i-1];
    while(scanf("%d%d",&nn,&nb)==2){
      int now,lastl,lastr;
      lastl=e2[nn-1],lastr=e2[nn]-1;
      for(int i=1;i<=lastr;i++) node[i]=0;
      for(int i=1;i<=nb;i++){ 
          now=1;
          do{    
              node[now]=!node[now];
              if(node[now]) now=2*now;
              else now=2*now+1;
          }while(now<lastl);
      }
      printf("%d\n",now);          
    }        
    return 0;
} 

