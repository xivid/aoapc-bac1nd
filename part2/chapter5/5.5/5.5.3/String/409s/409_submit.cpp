//此版本在hdu和poj上均AC，但在uva上RE
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;
char dict[30][30],l=0;
char ex[30][100];
int k,e;
bool indict(char s[])
{
 for(int i=1;i<=k;i++) if(!strcmp(s,dict[i])) return true;
 return false;
}
int check(char s[])
{
    int ans=0;
    char my[100];
    int len=strlen(s)-1;
    if(s[len]=='\n') len--;
    for(int i=0;i<len;i++)
     if(isupper(s[i])) my[i]=s[i]+32;
     else if(islower(s[i])) my[i]=s[i];
     else my[i]=' ';
    my[len]='\0';
    stringstream ss(my);
    char tmp[30];
    char* pos;
    while(ss >> tmp){
        if(indict(tmp)) {
            ans++;
            }
    }
    return ans;
}
int main()
{
    int cases=0;
    while(scanf("%d%d",&k,&e) == 2)
    {
        cases++;
        memset(dict,0,sizeof(dict));
        memset(ex,0,sizeof(ex));
        int max=-1,s[30],n=0;
        char word[30];
        for(int i=1;i<=k;i++) {
            scanf("%s",dict[i]);
        }
        getchar();
        for(int i=1;i<=e;i++)
        {
            fgets(ex[i],100,stdin);
            int no=check(ex[i]);
            if(no>max) {max=no; s[n=1]=i;}
            else if(no==max) s[++n]=i;
        }
        printf("Excuse Set #%d\n",cases);
        for(int i=1;i<=n;i++) printf("%s",ex[s[i]]);
        putchar('\n');
    }
    return 0;
}
