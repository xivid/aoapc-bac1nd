//本程序会溢出，修改版见e4-1ok.cpp
#include<cstdio>
int f(int n)
{
 int i,m=1;
 for( i = 1 ; i <= n ; i++)
  m*=i;
 return m;
}
int main()
{
 int m , n ;
 scanf("%d%d",&m,&n);
 printf("%d\n",f(n)/(f(m)*f(n-m)));
 return 0;
}
