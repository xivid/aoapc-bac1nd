#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
  int n, m, cases;
  srand(time(NULL));
  cases = rand () % 500;
  cout << cases << endl;
  while(cases--){
    n = rand() % 500 + 1;
    m = rand() % n;
    //n = 10; m = 5;
    cout << n << " " << m << endl;
    for(int i=1; i<n; i++) cout << rand() <<" "; cout << rand() << endl;
  }
  return 0;
}
