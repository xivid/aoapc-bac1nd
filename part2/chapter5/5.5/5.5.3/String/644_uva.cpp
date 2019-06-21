#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define min(a,b) a<b?a:b
bool isprefix(char pre[],char str[])
{
    if(strlen(pre)>strlen(str)) return false;
    int l=strlen(pre);
    for(int i=0;i<l;i++) if(pre[i]!=str[i]) return false;
    return true;
}
int main()
{
    int cases=1;
    for(;;)
    {
        char code[10][15];
        int n=1,flag=0;
        for(;;)
        {
            if(scanf("%s",code[n])==EOF) return 0;
            if(code[n][0]=='9') {n--; break;}
            n++;
        }
        //printf("%d codes.\n",n);
        //for(int i=1;i<=n;i++) printf("[%s]",code[i]);
        for(int i=1;i<=n&&!flag;i++)
         for(int j=1;j<=n&&!flag;j++)
          if(i!=j)
           if(isprefix(code[i],code[j])) flag=1;
        if(flag) printf("Set %d is not immediately decodable\n",cases);
        else printf("Set %d is immediately decodable\n",cases);
        cases++;
    }
    return 0;
}
