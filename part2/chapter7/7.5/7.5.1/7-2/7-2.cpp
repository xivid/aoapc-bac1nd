/*
   Try These Test Cases:
   27 441,  4 109,  59 211,  101 103,  907 911,  523 547
*/
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>

#define MAXDEPTH 10
#define MAX 2147483647L

unsigned long depth;
int found;
unsigned long answer[MAXDEPTH], d[MAXDEPTH];
unsigned long t;
unsigned long node=0;

unsigned long gcd(unsigned long a, unsigned long b)
{
  t=a%b;
  while(t){
    a=b;
    b=t;
    t=a%b;
  }
  return b;
}

/* determine the kth number d[k] */
void search(unsigned long a, unsigned long b, unsigned long k)
{
  unsigned long i,m,s,t;
  if (k==depth+1) return;
  else if (b%a==0 && b/a>d[k-1]){
    d[k]=b/a;
    if (!found || d[k]<answer[k])
      memcpy(answer,d,sizeof(d));
    found = 1;
    return;
  }
  node++;
  s=b/a;
  if (s<=d[k-1]) s=d[k-1]+1;
  t=(depth-k+1)*b/a; 
  if (t>MAX/b) t=MAX/b;
  if (found && t>=answer[depth]) t=answer[depth]-1;

  for (i=s; i<=t; i++)
  {
     d[k]=i;
     m=gcd(i*a-b,b*i);
     search((i*a-b)/m,b*i/m,k+1);
  }
}

int main()
{
  unsigned long a,b;
  int i;

  found = 0;
  d[0] = 1;
  scanf("%ld%ld",&a,&b);

  for (depth=1; depth<=MAXDEPTH; depth++){
    search(a,b,1);
    if (found){
      printf("%d/%d =", a , b);
      for(i=1;i<depth;i++) printf(" 1/%ld +",answer[i]); printf(" 1/%ld\n", answer[depth]);
      break;
    }
  }
  printf("NodeCount=%ld",node);
  system("pause");
  return 0;
}
