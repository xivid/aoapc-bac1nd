#include<cstring>
#include<cstdio>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
int main()
{
  {char tmp[100];
  fgets(tmp,100,stdin);
  printf("[%s]\n",tmp);
  }

{char tmp[100], c;
  gets(tmp);
  printf("[%s]\n",tmp);
  c=getchar();
  printf("[%c]\n",c);
  getchar();
  }
{
  string t;
  getline(cin,t);
  cout << "[" << t <<"]" << endl;
}
 char s[15]="123 456 789";
 int a;
 sscanf(s,"%d",&a);
 printf("%d\n",a);


 sscanf(s,"%d",&a);
 printf("%d\n",a);


 sscanf(s,"%d",&a);
 printf("%d\n",a);

 printf("c++ string\n");
 string k="123 456 789";
 stringstream kk(k);
 char b[10];

 kk >> b;
 cout << b << endl;

 kk >> a;
 cout << a << endl;
  puts("str");
  putchar('e');
 return 0;
}
