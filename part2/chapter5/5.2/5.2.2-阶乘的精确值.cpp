#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
const int maxn=3000; 
int main()
{
    int n;
    int a[maxn]; 
    memset(a,0,sizeof(a));
    a[1]= 1;  //可保证n=0时输出1 
    scanf("%d",&n);
    for(int i=2;i<=n;i++) {
      int c=0;
      for(int j=1;j<maxn;j++){
       c=a[j]*i+c;
       a[j]=c%10;
       c=c/10;    
      }    
    } 
    int i;
    for(i=maxn-1;i>0;i--) if(a[i]>0) break;
    for(;i>0;i--) printf("%d",a[i]);
    printf("\n");
    system("pause");
    return 0;
} 
