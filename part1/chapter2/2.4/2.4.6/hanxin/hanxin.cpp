#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 FILE *fin,*fout;
 fin=fopen("hanxin.in","r");
 fout=fopen("hanxin.out","w");
 int a,b,c;
 bool found=false;
 fscanf(fin,"%d%d%d",&a,&b,&c);
 for(int i=10;i<=100;i++) if(i%3==a&&i%5==b&&i%7==c) {fprintf(fout,"%d\n",i); found=true;}
 if(!found) fprintf(fout,"No answer\n");
 fclose(fin);
 fclose(fout);
 return 0;
}
