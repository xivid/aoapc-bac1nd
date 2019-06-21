#include<iostream>
#include<cstdio>
using namespace std;
#define MOD 1000000
#define FRELOCAL

int main()
{
  #ifndef WRONG
  int min,max,sum=0,n=0,t;
  scanf("%d",&t); {min=max=t; sum+=t; n++;}
  #else
  int min,max,sum=0,n=0,t;
  #endif
  #ifdef FRELOCAL
  freopen("e2-4.in","r",stdin);
  freopen("e2-4.out","w",stdout);
  #endif
  #ifdef FINLOCAL
  FILE *fin,*fout;
  fin=fopen("e2-4.in","r");
  fout=fopen("e2-4.out","w");
  while(fscanf(fin,"%d",&t)==1)
  #else
  while(scanf("%d",&t)==1)
  #endif
  {
   if(min>t) min=t;
   if(max<t) max=t;
   sum+=t; n++;
  }
  #ifdef FINLOCAL
  fprintf(fout,"Min:%d Max:%d Sum:%d n:%d Average:%.3lf\n",min,max,sum,n,(double)sum/n);
  fclose(fin);  fclose(fout);
  #else
  printf("Min:%d Max:%d Sum:%d n:%d Average:%.3lf\n",min,max,sum,n,(double)sum/n);
  #endif
  return 0;
}
