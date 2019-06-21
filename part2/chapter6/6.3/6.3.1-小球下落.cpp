#include<iostream>
using namespace std;
int main(){
 int D,I;
 while(cin >> D >> I){
  int now=1;
  for(int i=1;i<D;i++) {
   if(I%2) {now=now*2; I=(I+1)/2;}
   else {now=now*2+1; I/=2;}
   //now=now*2+1-(I%2); I=(I+I%2)/2;
  }
  cout << now << endl;
 }
 return 0;
}
