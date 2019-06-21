#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
char dict[30][100];
char ex[30][100];
int k,e;
int s[50],n=0;
bool indict(char s[])
{
 for(int i=1;i<=k;i++) if(!strcmp(s,dict[i])) return true;
 return false;
}
char my[100],tmp[100];
//在uva上终于AC了，估计原来RE的原因是my和tmp两个数组开在check里不太合适，导致SIGSEGV
int check(char s[])
{
    int ans=0;
    my[0]='\0';
    int len=strlen(s)-1;
    if(s[len]=='\n') len--;
    for(int i=0;i<len;i++)
     if(isalpha(s[i])) my[i]=tolower(s[i]);
     else my[i]=' ';
    my[len]='\0';
    int p=0;
    for(;;)
    {
        int l=0;
        tmp[0]='\0';
        while(my[p]==' '&&p<len) p++;
        while(my[p]!=' '&&p<len)  tmp[l++]=my[p++];
        tmp[l]='\0';
        if(indict(tmp)) {ans++;}
        if(p>=len) break;
    }
    return ans;
}
int main()
{
    int cases=0;
    int max=-1;
    while(scanf("%d%d\n",&k,&e) != EOF)
    {
        cases++;
        memset(dict,0,sizeof(dict));
        memset(ex,0,sizeof(ex));
        memset(s,0,sizeof(s));
        max=-1; n=0;
        for(int i=1;i<=k;i++) gets(dict[i]);
        for(int i=1;i<=e;i++)
        {
            gets(ex[i]);
            int no=check(ex[i]);
            if(no>max) {max=no; n=1; s[n]=i;}
            else if(no==max) s[++n]=i;
        }
        printf("Excuse Set #%d\n",cases);
        for(int i=1;i<=n;i++) printf("%s\n",ex[s[i]]);
        putchar('\n');
    }
    return 0;
}

/*
5 3
dog
ate
homework
canary
died
My dog ate my homework.
Can you believe my dog died after eating my canary... AND MY HOMEWORK?
This excuse is so good that it contain 0 keywords.
6 5
superhighway
crazy
thermonuclear
bedroom
war
building
I am having a superhighway built in my bedroom.
I am actually crazy.
1234567890.....,,,,,0987654321?????!!!!!!
There was a thermonuclear war!
I ate my dog, my canary, and my homework ... note outdated keywords?
*/
