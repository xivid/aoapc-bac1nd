/*
复习回溯法基本框架：
设置标记；
若未达目标
  下一步；
否则
  处理；
拆除标记（回溯）；
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10],w[10],x,y,z;
void trace(int step,int num)
{
 a[num]=1;
 w[step]=num;
 if(step==9)
 {
  /*x=w[1]*100+w[2]*10+w[3];
  y=w[4]*100+w[5]*10+w[6];
  z=w[7]*100+w[8]*10+w[9];
  if(y==2*x&&z==3*x) printf("%d %d %d\n",x,y,z);*/
  /*
  if((w[4]*100+w[5]*10+w[6])==2*(w[1]*100+w[2]*10+w[3])&&(w[7]*100+w[8]*10+w[9])==3*(w[1]*100+w[2]*10+w[3]))
   printf("%d%d%d,%d%d%d,%d%d%d\n",w[1],w[2],w[3],w[4],w[5],w[6],w[7],w[8],w[9]);
  */
 }
 for(int i=1;i<=9;i++)
  if(!a[i]) trace(step+1,i);
 a[num]=0;
}
int main()
{
 memset(a,0,sizeof(0));
 for(int i=1;i<=9;i++) trace(1,i);
 return 0;
}
