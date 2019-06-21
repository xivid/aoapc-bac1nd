#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b) == 2) {
        if(a==0&&b==0) break;
        int ans=0,c=0;
        while(a!=0&&b!=0){
            //注意后一位进位后可以导致本位进位 
             c=(a%10+b%10+c>=10)?1:0; 
             ans+=c; 
             a/=10; b/=10;
        }
        printf("%d\n",ans);
    }       
    return 0;
}    
