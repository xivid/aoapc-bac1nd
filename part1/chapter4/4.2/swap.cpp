#include<iostream>
using namespace std;
/*
//One possible version
void swap(int* a, int  *b)
{int t=*a; *a=*b; *b=t;}
int main(){
    int a,b;
    a=3; b=5;
    swap(&a,&b);
    cout << a << " " << b;
    system("PAUSE");
    return 0;
} 
*/
void swap(int& a,int& b)
{ int t=a; a=b; b=t;}
int main(){
    int a=3,b=4;
    swap(a,b);
    cout << a <<" "<< b;
    system("PAUSE");
    return 0;
}       
