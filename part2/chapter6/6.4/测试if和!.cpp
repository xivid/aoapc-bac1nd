#include<iostream>
#include<cstdio>
using namespace std;
int main(){
 int a;
 printf("TEST\n");
 a=1; printf("a=%d,!a=%d",a,!a); if(a) printf("true!\n");
 a=0; printf("a=%d,!a=%d\n",a,!a); if(a) printf("true!\n");
 a=-1; printf("a=%d,!a=%d",a,!a);  if(a) printf("true!\n");
 a=-123; printf("a=%d,!a=%d",a,!a);  if(a) printf("true!\n");
 a=123; printf("a=%d,!a=%d",a,!a);  if(a) printf("true!\n");
 printf("Test\n只要a是非零值，！a都是0，if(a)都会起作用。\n");
 return 0;
}
