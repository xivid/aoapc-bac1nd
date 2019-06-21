#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
void build(int l,char* pre,char* in,char *post){

}
int main(){
    char *post,*pre,*in;
    while(scanf("%s %s",pre,in)==2){
        int n=strlen(pre);
        build(n,pre,in,post);
        post[n]='\0';
        printf("%s\n",post);
    }
    return 0;
}
