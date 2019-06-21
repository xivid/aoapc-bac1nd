#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
    freopen("ipp.out", "w", stdout);
    for(int d = 1; d <= 10; d++)
    for(int c = 1; c <= 10; c++)
    for(int b = 1; b <= 10; b++)
    for(int a = 1; a <= 10; a++)
    for(int p = 1; p <= 10; p++)
    for(int j = 1; j <= 10; j++)
    for(int i = 1; i <= 10; i++) printf("%d ",i * i/10 + i%10);
    freopen("time.txt", "a", stdout);
    printf("i++ time used: %.3lfs\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}    
