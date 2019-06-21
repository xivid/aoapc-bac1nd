#include<iostream>
using namespace std;
int main()
{int a[10];
for(int i=0;i<10;i++) a[i]=i;
memset(a,0,sizeof(a));
for(int i=0;i<10;i++) cout << a[i]; 
system("pause");
return 0;
}
