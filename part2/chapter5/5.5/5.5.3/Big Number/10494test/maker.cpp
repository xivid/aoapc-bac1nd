#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
  srand(time(NULL));
  int mode=rand()%2;
  int len=rand()%20;
  cout << rand() % 9 + 1;
  while(--len) cout << rand()%10;
  cout << " ";
  if(mode) cout << '/'; else cout << '%';
  cout << " " << (int)((double)rand()/RAND_MAX *2147483647) << endl;
  return 0;
}
