#include<iostream>
#include<cstdio>
using namespace std;
#define MOD 1000000
#define FRELOCAL

int main()
{

  FILE *fin,*fout;
  fin=fopen("e2-4.in","rb");
  fout=fopen("e2-4.out","wb");
  //fin=stdin; fout=stdout;
  int min,max,sum=0,n=0,t;
  scanf("%d",&t); {min=max=t; sum+=t; n++;}

  while(fscanf(fin,"%d",&t) == 1)
  {
   if(min>t) min=t;
   if(max<t) max=t;
   sum+=t; n++;
  }
  fprintf(fout,"Min:%d Max:%d Sum:%d n:%d Average:%.3lf\n",min,max,sum,n,(double)sum/n);
  fclose(fin);  fclose(fout);
  return 0;
}
