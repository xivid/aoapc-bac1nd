#include<iostream>
using namespace std;
int* f()
{
    int a=3;
    for(int i=1;i<=10;i++) if(a%2) a*=3; else a-=5;
    cout << a<< endl;
    return &a;
}
int main()
{
    int* b=f();
    for(int i=1;i<=3;i++) if((*b)%2) (*b)*=3; else (*b)-=5;
    cout << *b << endl;
    return 0;
}
