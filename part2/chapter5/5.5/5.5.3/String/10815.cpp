#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
char dict[5010][200];
int n=1;
int cmp_str(const void* a,const void* b)
{
    char* aa=(char*)a;
    char* bb=(char*)b;
    return strcmp(aa,bb);
}
bool exist(char word[])
{
    for(int i=1;i<n;i++) if(!strcmp(word,dict[i])) return true;
    return false;
}
int main()
{
    char c;
    int l=0;
    while((c=getchar())!=EOF)
    {
        if(isalpha(c)) dict[n][l++]=tolower(c);
        else
        {
            dict[n][l]='\0';
            l=0;
            if(dict[n][0]!='\0'&&!exist(dict[n])) n++;
        }
    }
    n--;
    qsort(dict+1,n,sizeof(dict[1]),cmp_str);
    for(int i=1;i<=n;i++) printf("%s\n",dict[i]);
    return 0;
}
/*
Adventures in Disneyland

Two blondes were going to Disneyland when they came to a fork in the
road. The sign read: "Disneyland Left."

So they went home.

Sample Output

a
adventures
blondes
came
disneyland
fork
going
home
in
left
read
road
sign
so
the
they
to
two
went
were
when
*/
