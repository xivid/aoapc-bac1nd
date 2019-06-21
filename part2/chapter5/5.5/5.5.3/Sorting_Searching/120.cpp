#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char s[4000];
int cake[50]={0},n=0;
int main()
{
  while(gets(s))
  {
    n=1;
    memset(cake,0,sizeof(cake));
    int l=strlen(s);
    for(int i=0;i<l;i++)
     if(s[i]!=' ') cake[n]=cake[n]*10+s[i]-'0';
     else if(cake[n]) n++;
    for(int i=1;i<n;i++) printf("%d ",cake[i]); printf("%d\n",cake[n]);
    for(int i=1;i<=n/2;i++) {int t=cake[i]; cake[i]=cake[n+1-i]; cake[n+1-i]=t;}
    l=1;
    while(l<n)
    {
      int max=l;
      for(int i=l;i<=n;i++) if(cake[i]>cake[max]) max=i;
      if(max==l) l++;
      else if(max==n){
        printf("%d ",l);
        for(int i=l;i<=(l+n)/2;i++) {int t=cake[i]; cake[i]=cake[n+l-i]; cake[n+l-i]=t;}
        l++;
      }
      else {
        printf("%d ",max);
        for(int i=max;i<=(max+n)/2;i++) {int t=cake[i]; cake[i]=cake[max+n-i]; cake[max+n-i]=t;}
        printf("%d ",l);
        for(int i=l;i<=(l+n)/2;i++) {int t=cake[i]; cake[i]=cake[n+l-i]; cake[n+l-i]=t;}
        l++;
      }
    }
    printf("0\n");
  }
  return 0;
}

/*
Sample Input

1 2 3 4 5
5 4 3 2 1
5 1 2 3 4

Sample Output

1 2 3 4 5
0
5 4 3 2 1
1 0
5 1 2 3 4
1 2 0
*/
