//字符串最后一题，就牺牲一下让我练习c++ string吧。。
#include<iostream>
#include<string>
using namespace std;
int main()
{
  int rule;
  while(cin >> rule)
  {
    if(rule == 0) break;
    string f[15],r[15],text;
    cin.get(); //eat '\n'
    for(int i=1;i<=rule;i++) {getline(cin,f[i]); getline(cin,r[i]);}  //getline恰好可以读取空串有木有，神器啊
    getline(cin,text);
    for(int i=1;i<=rule;i++)
    {
       int pos;
       while((pos=text.find(f[i]))<text.size()) text.replace(pos,f[i].length(),r[i]); //find找不到时的返回值很奇葩
    }
    cout << text << endl;
  }
    return 0;
}
//感想：20行瞬间AC，简直像作弊器一样。c++ string 果然强大。等时间稍充足的时候一定要好好研究一下那些字符串函数。
/*
Example input:

4
ban
bab
baba
be
ana
any
ba b
hind the g
banana boat
1
t
sh
toe or top
0

Example output:

    behind the goat
    shoe or shop
*/
