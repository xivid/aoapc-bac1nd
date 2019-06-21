#include<cstdio>
#include<cstdlib>
#include<cstring>
int top[60],pile=0; //top[i]=card number of pile i,pile=tot of pile
char s[60][60][3];
void copy(int x,int y)
{
  for(int i=1;i<=top[y];i++) {s[x][i][0]=s[y][i][0]; s[x][i][1]=s[y][i][1];}
  top[x]=top[y];
}
bool movable(int x)
{
  if(x-3>0&&(s[x-3][top[x-3]][0]==s[x][top[x]][0]||s[x-3][top[x-3]][1]==s[x][top[x]][1])) return true;
  if(x-1>0&&(s[x-1][top[x-1]][0]==s[x][top[x]][0]||s[x-1][top[x-1]][1]==s[x][top[x]][1])) return true;
  return false;
}
void move(int x)
{
  //printf("moving %d..\n",x);
  if(x-3>0&&(s[x-3][top[x-3]][0]==s[x][top[x]][0]||s[x-3][top[x-3]][1]==s[x][top[x]][1]))
  {
    //printf("move %s to %s\n",s[x][top[x]],s[x-3][top[x-3]]);
    top[x-3]++;
    strcpy(s[x-3][top[x-3]],s[x][top[x]]);
    s[x][top[x]][0]='\0';
    top[x]--;
    if(top[x]==0)
    {
      //printf("empty pile %d!\n",x);
      for(int i=x;i<pile;i++) copy(i,i+1);
      top[pile--]=0;
    }

    //printf("new(%d):\n",pile);
    //for(int i=1;i<=pile;i++) printf("%s ",s[i][top[i]]); printf("\n");
  }
  else
  {
    //printf("move %s to %s\n",s[x][top[x]],s[x-1][top[x-1]]);
    top[x-1]++;
    strcpy(s[x-1][top[x-1]],s[x][top[x]]);
    s[x][top[x]][0]='\0';
    top[x]--;
    if(top[x]==0)
    {
      //printf("empty pile %d!\n",x);
      for(int i=x;i<pile;i++) copy(i,i+1);
      top[pile--]=0;
    }
    //printf("top[%d]=%d,top[%d]=%d\n",x,top[x],x-1,top[x-1]);
    //printf("new(%d):\n",pile);
    //for(int i=1;i<=pile;i++) printf("%s ",s[i][top[i]]); printf("\n");
  }
}
int main()
{
  char buf[3];
  for(;;)
  {
    memset(s,0,sizeof(s));
    scanf("%s",buf);
    if(buf[0]=='#') break;
    for(int i=1;i<=52;i++) top[i]=1;
    strcpy(s[1][1],buf);
    for(int i=2;i<=52;i++) scanf("%s",s[i][1]);
    pile=52;
    int flag=1;
    while(flag){
      flag=0;
      for(int i=2;i<=pile;i++) if(movable(i))
      {
        //printf("%d movable\n",i); getchar();
        move(i);
        flag=1;
        break;
      }
    }
    if(pile==1) printf("1 pile remaining: 52\n");
    else{
     printf("%d piles remaining:",pile);
     for(int i=1;i<=pile;i++) printf(" %d",top[i]);
     printf("\n");
    }
  }
  return 0;
}
/*
Sample input

QD AD 8H 5S 3H 5H TC 4D JH KS 6H 8S JS AC AS 8D 2H QS TS 3S AH 4H TH TD 3C 6S
8C 7D 4C 4S 7S 9H 7C 5D 2S KD 2D QH JD 6D 9D JC 2C KH 3D QC 6C 9S KC 7H 9C 5C
AC 2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC AD 2D 3D 4D 5D 6D 7D 8D TD 9D JD QD KD
AH 2H 3H 4H 5H 6H 7H 8H 9H KH 6S QH TH AS 2S 3S 4S 5S JH 7S 8S 9S TS JS QS KS
#

Sample Output

6 piles remaining: 40 8 1 1 1 1
1 pile remaining: 52

*/
