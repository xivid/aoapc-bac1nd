#include<cstdio>
int c(int n,int m)
{
 long long ans=1;  //long long在m<=20内不会溢出
 if(m>n/2) m=n-m;
 if(m==0) return 1;
 if(m==1) return n;
 for(int i=n;i>n-m;i--) ans*=i;
 for(int i=m;i>0;i--) ans/=i;
 return ans;
}
int main()
{
 int m , n ;
 scanf("%d%d",&m,&n);
 printf("%d\n",c(n,m));  // n选m
 return 0;
}
