//感觉这不就是冒泡排序吗。。记录交换次数就可以了吧……
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  int n;
  int t,a[60],times,ts;
  cin >> n;
  while(n--)
  {
    memset(a,0,sizeof(a));
    times=0;
    cin >> t;
    for(int i=1;i<=t;i++) cin >> a[i];
    for(int i=1;i<=t;i++){
      for(int j=t;j>1;j--)
        if(a[j-1]>a[j]) {times++; ts=a[j-1]; a[j-1]=a[j]; a[j]=ts;}
    }
    cout << "Optimal train swapping takes "<< times << " swaps." << endl;
  }
  return 0;
}
/*
Example Input

3
3
1 3 2
4
4 3 2 1
2
2 1

Example Output

Optimal train swapping takes 1 swaps.
Optimal train swapping takes 6 swaps.
Optimal train swapping takes 1 swaps.
*/
