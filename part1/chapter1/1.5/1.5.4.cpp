#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int a=0,b=1,c=1,x=1,y=1;
    cout<<(a&&b||c)<<endl;
    if(a)
     if(b) x++;
     else y++;
    cout<<a<<b<<x<<y<<endl;
    return 0;
}
