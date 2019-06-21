#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
int key[100]={0},phone[10000000],saved[10000000],book[100010],t;
int sets,n;
void initkey()
{
  for(char x='0';x<='9';x++) key[(int)x]=x-'0';
  for(char x='A';x<='O';x++) key[(int)x]=2+(x-'A')/3;
  for(char x='P';x<='S';x++) key[(int)x]=7;
  for(char x='T';x<='Z';x++) key[(int)x]=8+(x-'T')/3;
}
int main()
{
  char c;
  int num;
  initkey();
  scanf("%d\n",&sets);
  while(sets--)
  {
    int flag=1;
    t=0;
    scanf("%d\n",&n);
    memset(phone,0,sizeof(phone));
    memset(saved,0,sizeof(saved));
    memset(book,0,sizeof(book));
    for(int i=1;i<=n;i++)
    {
      num=0;
      while((c=getchar())!='\n') if(c!='-') num=num*10+key[c];
      phone[num]++;
      if(phone[num]>1&&!saved[num]) {flag=0; saved[num]++; book[++t]=num;}
    }
    if(flag) puts("No duplicates.");
    else
    {
      sort(book+1,book+t+1);
      for(int i=1;i<=t;i++) printf("%3d-%4d %d\n",book[i]/10000,book[i]%10000,phone[book[i]]);
    }
    if(sets) putchar('\n');
  }
  return 0;
}
/*
 Sample Input

1

12
4873279
ITS-EASY
888-4567
3-10-10-10
888-GLOP
TUT-GLOP
967-11-11
310-GINO
F101010
888-1200
-4-8-7-3-2-7-9-
487-3279

Sample Output

310-1010 2
487-3279 4
888-4567 3
*/
