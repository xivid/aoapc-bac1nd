#include<iostream>
using namespace std;
char re[500]={0};
int isp(string s)
{
 int l=s.length()-1;
 for(int i=0;i<=l/2;i++) if(s.at(i)!=s.at(l-i)) return 0;
 return 1;
}
int ism(string s)
{
 int l=s.length()-1;
 for(int i=0;i<=l/2;i++) if(re[s.at(i)]!=s.at(l-i)) return 0;
 return 1;
}
int main()
{
 re['A']='A'; re['M']='M';  re['Y']='Y';
 re['Z']='5'; re['O']='O'; re['1']='1';
 re['2']='S'; re['E']='3'; re['3']='E';
 re['S']='2'; re['5']='Z'; re['H']='H';
 re['T']='T'; re['I']='I'; re['U']='U';
 re['J']='L'; re['V']='V'; re['8']='8';
 re['W']='W'; re['L']='J'; re['X']='X';
 string s;
 while(cin >> s)
 {
  int p=0,m=0;
  p=isp(s);
  m=ism(s);
  if(!p&&!m) cout << s <<" -- is not a palindrome." << endl;
  else if(p&&!m) cout << s << " -- is a regular palindrome." << endl;
  else if(!p&&m) cout << s << " -- is a mirrored string." << endl;
  else cout << s << " -- is a mirrored palindrome." << endl;
  cout << endl;
 }
 return 0;
}
/*
STRING	CRITERIA
" -- is not a palindrome." 	if the string is not a palindrome and is not a mirrored string
" -- is a regular palindrome." 	if the string is a Sample Input

NOTAPALINDROME
ISAPALINILAPASI
2A3MEAS
ATOYOTA

Sample Output

NOTAPALINDROME -- is not a palindrome.

ISAPALINILAPASI -- is a regular palindrome.

2A3MEAS -- is a mirrored string.

ATOYOTA -- is a mirrored palindrome.
 palindrome and is not a mirrored string
" -- is a mirrored string." 	if the string is not a palindrome and is a mirrored string
" -- is a mirrored palindrome." 	if the string is a palindrome and is a mirrored string
 Sample Input

NOTAPALINDROME
ISAPALINILAPASI
2A3MEAS
ATOYOTA

Sample Output

NOTAPALINDROME -- is not a palindrome.

ISAPALINILAPASI -- is a regular palindrome.

2A3MEAS -- is a mirrored string.

ATOYOTA -- is a mirrored palindrome.

*/
