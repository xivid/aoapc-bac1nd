#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 FILE *fout;
 fout=fopen("daffodil.out","w");
 for(int i=1;i<=9;i++)
  for(int j=0;j<=9;j++)
   for(int k=0;k<=9;k++)
   {
    if(i*100+j*10+k==i*i*i+j*j*j+k*k*k) fprintf(fout,"%d\n",i*100+j*10+k);
   }
  fclose(fout);
  return 0;
}
