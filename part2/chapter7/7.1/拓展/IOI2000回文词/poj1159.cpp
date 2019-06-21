//Memory: 49864K		Time: 1391MS
//短小精悍的代码（max(int, int, int)）不一定快捷..
//果然还是要注意细节、静态查错。。一开始写成了a[i]==b[i]，这种小而致命的错误不仔细看是很难找到的。。
#include<cstdio>
char a[5050],b[5050];
int n;
short f[5050][5050];
inline int max(int a, int b, int c){return (a>b)?(a>c?a:c):(b>c?b:c);}
int main(){
  scanf("%d",&n); getchar();
  for(int i=1; i<=n; i++) {a[i]=getchar(); b[n-i+1] = a[i];}
  f[0][0] = 0;
  for(int i=1; i<=n; i++)
   for(int j=1; j<=n; j++)
    f[i][j] = max(f[i-1][j-1]+(a[i]==b[j]), f[i-1][j], f[i][j-1]);
  printf("%d\n", n-f[n][n]);
  return 0;
}
