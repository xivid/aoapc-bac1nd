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
    my[len]='\0'; //essential
    //printf("newstring:%s",my);
    stringstream ss(my);
    char tmp[30];
    char* pos;
    while(ss >> tmp){
        if(indict(tmp)) {
            ans++;
            //printf(" keyword %s found. ",tmp);
            }
    }
    return ans;
}
int main()
{
    freopen("excuse.in","r",stdin);
    freopen("excuse.out","w",stdout);
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
        //for(int i=1;i<=k;i++) printf("No%d.%s ",i,dict[i]);
        getchar();
        for(int i=1;i<=e;i++)
        {
            fgets(ex[i],100,stdin);
            //if(ex[i][strlen(ex[i])-1]=='\n') ex[i][strlen(ex[i])-1]='\0';
            //printf("readed %s.",ex[i]);
            int no=check(ex[i]);
            //printf("It has %d keywords.",no);
            if(no>max) {max=no; s[n=1]=i;}
            else if(no==max) s[++n]=i;
        }
        printf("Excuse Set #%d\n",cases);
        for(int i=1;i<=n;i++) printf("%s",ex[s[i]]);
        putchar('\n');
    }
    return 0;
}
/*
Sample Input

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

Sample Output

Excuse Set #1
Can you believe my dog died after eating my canary... AND MY HOMEWORK?

Excuse Set #2
I am having a superhighway built in my bedroom.
There was a thermonuclear war!
*/
