#include<cstdio>
#include<cstdlib>
#include<cstring>
int main()
{
 int cases;
 scanf("%d\n",&cases);
 for(int no=1;no<=cases;no++){
  double x1,x2;
  char v1,e,v2,d11,d12,d21,d22;
  printf("Problem #%d\n",no);
  //get sequence 1
  v1=getchar(); e=v1;
  while(e!='=')
  {
   v1=e;
   e=getchar();
  }
  scanf("%lf",&x1);
  d12=d11=getchar(); if(d11=='m'||d11=='k'||d11=='M') d12=getchar();
  //printf("%c%c%lf%c%c\n",v1,e,x1,d11,d12);
  if(d11=='m') x1/=1000; //弱智错误！==写成=！
  else if(d11=='k') x1*=1000;
  else if(d11=='M') x1*=1000000;
  //get sequence 2
  v2=getchar(); e=v2;
  while(e!='=')
  {
   v2=e;
   e=getchar();
  }
  scanf("%lf",&x2);
  d22=d21=getchar(); if(d21=='m'||d21=='k'||d21=='M') d22=getchar();
  //printf("%c%c%lf%c%c\n",v2,e,x2,d21,d22);
  if(d21=='m') x2/=1000;
  else if(d21=='k') x2*=1000;
  else if(d21=='M') x2*=1000000;

  if(v1=='P'&&v2=='U') printf("I=%.2lfA\n\n",x1/x2);  //调试完毕后忘记修改回要求的输出列表导致输出错误，又浪费一部分时间！
  else if(v1=='U'&&v2=='P') printf("I=%.2lfA\n\n",x2/x1);
  else if(v1=='P'&&v2=='I') printf("U=%.2lfV\n\n",x1/x2);
  else if(v1=='I'&&v2=='P') printf("U=%.2lfV\n\n",x2/x1);
  else if(v1=='U'&&v2=='I') printf("P=%.2lfW\n\n",x1*x2);
  else if(v1=='I'&&v2=='U') printf("P=%.2lfW\n\n",x1*x2);

 }

 return 0;
}
/*
 Sample Input

3
If the voltage is U=200V and the current is I=4.5A, which power is generated?
A light-bulb yields P=100W and the voltage is U=220V. Compute the current, please.
bla bla bla lightning strike I=2A bla bla bla P=2.5MW bla bla voltage?

Sample Output

Problem #1
P=900.00W

Problem #2
I=0.45A

Problem #3
U=1250000.00V

*/
