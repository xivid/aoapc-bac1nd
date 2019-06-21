#include<iostream>
#include<cstdio>
using namespace std;
bool check(int abc,int def,int ghi)
{
 int a[10],top=0;
 for(int i=1;i<=9;i++) a[i]=0;
 while(abc) {a[abc%10]++; if(a[abc%10]>1) return false; abc/=10;}
 while(def) {a[def%10]++;if(a[def%10]>1) return false; def/=10;}
 while(ghi) {a[ghi%10]++; if(a[ghi%10]>1) return false;ghi/=10;}
 for(int i=1;i<=9;i++) if(a[i]==0) return false;
 return true;
}
int main()
{
  FILE *fout;
  fout=fopen("permutation.out","w");
  int abc,def,ghi;
  for(abc=123;abc<=333;abc++)
   for(def=246;def<=666;def++)
    for(ghi=369;ghi<=987;ghi++){
     if(check(abc,def,ghi)&&ghi==3*abc&&def==2*abc) fprintf(fout,"%d:%d:%d=1:2:3\n",abc,def,ghi);
    }

}
