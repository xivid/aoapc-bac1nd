#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define N 505
long long a[N];
int mk[N];
#define MAX(a, b) (a)>(b)?(a):(b)
long long Judge(long long mid, const int m, const int k)
{
    long long sum = 0, maxt = 0;
    for(int i=m-1, j=0; i>=0; i--){
        if(j<k-1 && (i<k-j-1 || sum+a[i]>mid)){
            maxt = MAX(sum, maxt);
            sum = a[i];
            mk[i] = 1;
            j++;
        }
        else sum+=a[i];
    }
    return MAX(maxt, sum);
}
int main()
{
    int t, m, k;
    long long left, right, mid, ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &m, &k);
        left = right = 0;
        for(int i = 0; i < m; i++){scanf("%lld", &a[i]); right += a[i];}
        while(left < right){
            mid = (left + right) >> 1;
            ans = Judge(mid, m, k);
            if(ans > mid) left = mid + 1;
            else right = mid;
        }
        memset(mk, 0, sizeof(mk));
        Judge(left, m, k);
        printf("%lld", a[0]);
        if(mk[0]) printf(" /");
        for(int i = 1; i < m; i++){
            printf(" %lld", a[i]); if(mk[i]) printf(" /");
        }
        printf("\n");
    }
    return 0;
}
