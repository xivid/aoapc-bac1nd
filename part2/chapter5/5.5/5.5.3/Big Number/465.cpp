#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxlongint 2147483647
int main()
{
  double a,b; char c; char s[200];
  while(gets(s))
  {
    puts(s);
    sscanf(s,"%lf %c %lf",&a,&c,&b);
    if(a>maxlongint) printf("first number too big\n");
    if(b>maxlongint) printf("second number too big\n");
    if(c=='+'&&a+b>maxlongint) printf("result too big\n");
    else if(c=='*'&&a*b>maxlongint) printf("result too big\n");
  }

  return 0;
}
/*
//因为担心输入中的空格不一定会那么规则，我采用以下处理方式，但貌似不怎么正确，懒得改了……
  char c,f;
  long long a=0,b=0;
  int flag=0,la=0,lb=0,w1=0,w2=0,w3=0;
  for(;;)
  {
    if((c=getchar())==EOF) break;
    putchar(c);
    if(c=='\n'){ a=b=0; flag=la=lb=w1=w2=w3=0; continue;}
    if(!flag)
    {
      if(c>='0'&&c<='9'){ la++; a=a*10+c-'0'; }
      if(!w1&&(la>10||a>maxlongint)) {printf("first number too big\n"); w1=1;}
      do{c=getchar(); putchar(c); }while(c!='+'&&c!='*'); f=c;
      flag=!flag;
    }
    else
    {
      if(c>='0'&&c<='9') {lb++; b=b*10+c-'0';}
      if(!w2&&(lb>10||b>maxlongint)) {printf("second number too big\n"); w2=1;}
    }
    if(f=='+'&&a+b>maxlongint) w3=1;
    else if(f=='*'&&a*b>maxlongint) w3=1;
    if(w1||w2||w3) printf("result too big\n");
    printf("a=%lld,%c,b=%lld",a,f,b);
  }
  */
