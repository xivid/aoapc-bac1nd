#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
using namespace std;
int n,m;
char g[51][51]; //g[1..n][0..m-1]
void find(char word[])
{
 int flag=0,l=strlen(word);
 for(int i=1;i<=n;i++)
  for(int j=0;j<m;j++)
   if(word[0]==g[i][j])
   {
    //search in 8 directions
    //脑残了。。可以用dx[8]={....},dy[8]={...},我一兴奋写了8个循环。。
    //right
    if(!flag){
     flag=1;
     for(int d=1;d<l;d++) if(j+d>=m||g[i][j+d]!=word[d]) {flag=0; break;}
    }
    //left
    if(!flag){
     flag=1;
     for(int d=1;d<l;d++) if(j-d<0||g[i][j-d]!=word[d]) {flag=0;break;}
    }
    //down
    if(!flag){
     flag=1;
     for(int d=1;d<l;d++) if(i+d>n||g[i+d][j]!=word[d]) {flag=0;break;}
    }
    //up
    if(!flag){
     flag=1;
     for(int d=1;d<l;d++) if(i-d<=0||g[i-d][j]!=word[d]) {flag=0;break;}
    }
    //right-down
    if(!flag){
     flag=1;
     for(int d=1;d<l;d++) if(i+d>n||j+d>=m||g[i+d][j+d]!=word[d]) {flag=0;break;}
    }
    //right-up
    if(!flag){
     flag=1;
     for(int d=1;d<l;d++) if(i-d<=0||j+d>=m||g[i-d][j+d]!=word[d]) {flag=0;break;}
    }
    //left-down
    if(!flag){
     flag=1;
     for(int d=1;d<l;d++) if(i+d>n||j-d<0||g[i+d][j-d]!=word[d]) {flag=0;break;}
    }
    //left-up
    if(!flag){
     flag=1;
     for(int d=1;d<l;d++) if(i-d<=0||j-d<0||g[i-d][j-d]!=word[d]) {flag=0;break;}
    }
    if(flag) {printf("%d %d\n",i,j+1); return;} //array right move
   }
}
int main()
{
 int cases,k;
 char word[51];
 scanf("%d",&cases);
 while(cases--)
 {
  memset(g,0,sizeof(g));
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
  {
   scanf("%s",g[i]);
   for(int j=0;j<m;j++) if(isupper(g[i][j])) g[i][j]+=32;
  }
  scanf("%d",&k);
  for(int i=1;i<=k;i++){
    scanf("%s",word);
    int len=strlen(word);
    for(int j=0;j<len;j++) if(isupper(word[j])) word[j]+=32;
    find(word);
  }
  if(cases) printf("\n");
 }
 return 0;
}
/*

 Sample Input

1

8 11
abcDEFGhigg
hEbkWalDork
FtyAwaldORm
FtsimrLqsrc
byoArBeDeyv
Klcbqwikomk
strEBGadhrb
yUiqlxcnBjf
4
Waldorf
Bambi
Betty
Dagbert

Sample Output

2 5
2 3
1 2
7 8

*/
