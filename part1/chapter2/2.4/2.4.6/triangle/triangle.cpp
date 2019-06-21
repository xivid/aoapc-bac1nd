#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
ifstream fin("triangle.in");
ofstream fout("triangle.out");
int main()
{
 int n,i,j;
 fin >> n;
 for(i=2*n-1;i>=1;i-=2){
  for(j=1;j<=((2*n-1)-i)/2;j++) fout<<" ";
  for(j=1;j<=i;j++) fout << "#";
  for(j=1;j<=((2*n-1)-i)/2;j++) fout<<" ";
  fout << endl;
 }
 return 0;
}
