#include<cstdio>
#include<cstdlib>
#include<ctime>
int main()
{
  srand(time(NULL));
  int pos=rand()%4+1;
  for(int i=0;i<pos;i++) printf("%d",rand()%10);
  putchar('.');
  for(int i=pos+1;i<6;i++) printf("%d",rand()%10);
  printf("%3d\n",rand()%25+1);


  pos=rand()%4+1;
  for(int i=0;i<pos;i++) printf("%d",rand()%10);
  putchar('.');
  for(int i=pos+1;i<6;i++) printf("%d",rand()%10);
  printf("%3d\n",rand()%25+1);
  return 0;
}
