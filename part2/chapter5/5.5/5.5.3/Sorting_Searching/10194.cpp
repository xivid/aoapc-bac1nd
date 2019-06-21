#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<map>
#include<algorithm>
using namespace std;
int N,T,G;
string tournamentname,game;
struct Tteam{
  string name;
  int win,tie,loss,gs,ga;
  int p,g,diff;
  Tteam() {name=""; p=g=win=tie=loss=diff=gs=ga=0;}
  void clear() {name=""; p=g=win=tie=loss=diff=gs=ga=0;}
};
Tteam team[110];
map<string,int> tno; //map是个好东西，谁用谁知道
bool cmp(Tteam a, Tteam b)
{
  if(a.p!=b.p) return a.p>b.p;
  if(a.win!=b.win) return a.win>b.win;
  if(a.diff!=b.diff) return a.diff>b.diff;
  if(a.gs!=b.gs) return a.gs>b.gs;
  if(a.g!=b.g) return a.g<b.g;
  string na(a.name),nb(b.name);
  for(int i=0;i<na.length();i++) na[i]=tolower(na[i]);
  for(int i=0;i<nb.length();i++) nb[i]=tolower(nb[i]);
  return na<=nb;
}
int main()
{
  string t1,t2;
  int g1,g2,tn1,tn2,geshi=0;
  scanf("%d\n",&N);
  while(N--)
  {
    getline(cin,tournamentname);
    scanf("%d\n",&T);
    for(int i=1;i<=T;i++)
    {
      team[i].clear();
      getline(cin,team[i].name);
      tno[team[i].name]=i;
    }
    scanf("%d\n",&G);
    for(int i=1;i<=G;i++)
    {
      getline(cin,t1,'#');
      scanf("%d@%d#",&g1,&g2);
      getline(cin,t2);
      tn1=tno[t1]; tn2=tno[t2];
      team[tn1].gs+=g1; team[tn2].gs+=g2;
      team[tn1].ga+=g2; team[tn2].ga+=g1;
      if(g1==g2)
      {
        team[tn1].tie++; team[tn2].tie++;
      }
      else if(g1<g2)
      {
        team[tn1].loss++; team[tn2].win++;
      }
      else
      {
        team[tn1].win++; team[tn2].loss++;
      }
      /*
      //一种装B的写法
      team[tn1].tie+=(g1==g2); team[tn2].tie+=(g1==g2);
      team[tn1].loss+=(g1<g2); team[tn2].loss+=(g1>g2);
      team[tn1].win+=(g1>g2); team[tn2].win+=(g1<g2);
      */
    }
    for(int i=1;i<=T;i++)
    {
      team[i].p=3*team[i].win+team[i].tie;
      team[i].g=team[i].tie+team[i].win+team[i].loss;
      team[i].diff=team[i].gs-team[i].ga;
    }
    sort(team+1,team+T+1,cmp);
    if(geshi) putchar('\n');
    geshi++;
    cout << tournamentname << endl;
    for(int i=1;i<=T;i++)
    {
      printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i,team[i].name.c_str(),team[i].p,team[i].g,team[i].win,team[i].tie,team[i].loss,team[i].diff,team[i].gs,team[i].ga);
    }
  }
  return 0;
}
/*
Sample Input

2
World Cup 1998 - Group A
4
Brazil
Norway
Morocco
Scotland
6
Brazil#2@1#Scotland
Norway#2@2#Morocco
Scotland#1@1#Norway
Brazil#3@0#Morocco
Morocco#3@0#Scotland
Brazil#1@2#Norway
Some strange tournament
5
Team A
Team B
Team C
Team D
Team E
5
Team A#1@1#Team B
Team A#2@2#Team C
Team A#0@0#Team D
Team E#2@1#Team C
Team E#1@2#Team D

Sample Output

World Cup 1998 - Group A
1) Brazil 6p, 3g (2-0-1), 3gd (6-3)
2) Norway 5p, 3g (1-2-0), 1gd (5-4)
3) Morocco 4p, 3g (1-1-1), 0gd (5-5)
4) Scotland 1p, 3g (0-1-2), -4gd (2-6)

Some strange tournament
1) Team D 4p, 2g (1-1-0), 1gd (2-1)
2) Team E 3p, 2g (1-0-1), 0gd (3-3)
3) Team A 3p, 3g (0-3-0), 0gd (3-3)
4) Team B 1p, 1g (0-1-0), 0gd (1-1)
5) Team C 1p, 2g (0-1-1), -1gd (3-4)
*/
