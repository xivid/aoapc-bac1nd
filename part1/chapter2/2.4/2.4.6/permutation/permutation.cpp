#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
 int a,b,c,d,e,f,g,h,i,x,y,z;
 FILE *fout;
 fout=fopen("permutation.out","w");
 for(a=1;a<=3;a++) //a最大为3
  for(b=1;b<=9;b++)
   if(a!=b)
    for(c=1;c<=9;c++)
     if(b!=c&&a!=c)
      for(d=a*2;d<=9;d++) //d至少为2*a
       if(a!=d&&b!=d&&c!=d)
        for(e=1;e<=9;e++)
         if(a!=e&&b!=e&&c!=e&&d!=e)
          for(f=1;f<=9;f++)
           if(a!=f&&b!=f&&c!=f&&d!=f&&e!=f)
            for(g=a*3;g<=9;g++) //g至少为a*3
             if(a!=g&&b!=g&&c!=g&&d!=g&&e!=g&&f!=g)
              for(h=1;h<=9;h++)
               if(a!=h&&b!=h&&c!=h&&d!=h&&e!=h&&f!=h&&g!=h)
                for(i=1;i<=9;i++)
                 if(a!=i&&b!=i&&c!=i&&d!=i&&e!=i&&f!=i&&g!=i&&h!=i)
                  {/*
                   x=a*100+b*10+c;
                   y=d*100+e*10+f;
                   z=g*100+h*10+i;
                   if(y==2*x&&z==3*x) fprintf(fout,"%d %d %d\n",x,y,z);
                   */
                   if((a*100+b*10+c)*2==d*100+e*10+f&&(a*100+b*10+c)*3==g*100+h*10+i) fprintf(fout,"%d%d%d %d%d%d %d%d%d\n",a,b,c,d,e,f,g,h,i);
                  }
 fclose(fout);
 return 0;
}
