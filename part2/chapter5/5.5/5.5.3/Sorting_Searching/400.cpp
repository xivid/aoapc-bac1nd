#include<cstdio>
#include<cstdlib>
#include<cstring>
char name[110][80];
int n;
int cmp_str(const void* a,const void* b)
{
  char* aa=(char*)a; char* bb=(char*)b;
  return strcmp(aa,bb);
}
int main()
{
  while(scanf("%d\n",&n)==1)
  {
    memset(name,0,sizeof(name));
    int maxlen=-1,column,row,len;
    for(int i=1;i<=n;i++)
    {
      gets(name[i]);
      len=strlen(name[i]);
      if(len>maxlen) maxlen=len;  //strlen返回类型为size_t，不能直接与int比较
    }
    qsort(name+1,n,sizeof(name[0]),cmp_str);
    //for(int i=1;i<=n;i++) printf("%d:[%s],",i,name[i]);
    //printf("maxlen=%d,maxwidth=%d\n",maxlen,maxlen+2);
    maxlen+=2;
    column=62/maxlen; //最后一列不要2个空格也可以，所以是62！！！
    row=n/column+(n%column!=0);
    for(int i=1;i<=60;i++) putchar('-');
    putchar('\n');
    for(int i=1;i<=row;i++){
     for(int j=0;j<column;j++)
     {
       int len=strlen(name[i+j*row]);
       printf("%s",name[i+j*row]);
       for(int p=1;p<=maxlen-len;p++) putchar(' ');
     }
     putchar('\n');
    }
  }
  return 0;
}
