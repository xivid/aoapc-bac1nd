#include<cstdio>
#include<cstdlib>
#include<cstring>
#define maxn 5000
char word[maxn][10],sorted[maxn][10];
int cmp_str(const void* sa,const void* sb){
    char* a=(char*)sa;
    char* b=(char*)sb;
    return strcmp(a,b);
}    
int cmp_chr(const void *ca,const void *cb){
    char* a=(char*)ca;
    char* b=(char*)cb;
    return *a-*b;
}       
int main()
{
    freopen("5.3.2.in","r",stdin);
    freopen("5.3.2.out","w",stdout); 
    int count=0;
    while(1){
        scanf("%s",word[count]);
        if(word[count][0]=='*') break;
        count++;
    }       
    qsort(word,count,sizeof(word[0]),cmp_str);
    for(int i=0;i<count;i++){   //到此才可给单个单词排序 
        strcpy(sorted[i],word[i]);
        qsort(sorted[i],strlen(sorted[i]),sizeof(char),cmp_chr);
        }
    char s[10];
    while(scanf("%s",s)==1){
        qsort(s,strlen(s),sizeof(char),cmp_chr);
        int found=0;
        for(int i=0;i<count;i++) if(!strcmp(sorted[i],s)) {printf("%s ",word[i]); found=1;}
        if(!found) printf(":(");
        printf("\n");
    }     
    return 0;
}    
