#include<cstdio>
#include<cstdlib>
int bsearch(int* a,int l,int r, int x){
    int m;
    while(l<r){
        m = l+(r-l)/2;
        if(a[m] == x) return m;
        if(a[m] > x) r=m;
        else l=m+1;
    }
    return -1;    
}
int lower_bound(int *a, int l, int r, int x){
    int m;
    while(l<r){
        m = l+(r-l)/2;
        if(a[m] >= x) r = m;
        else l = m+1;
    }
    return l;
}
int upper_bound(int *a, int l, int r, int x){
    int m;
    while(l<r){
        m = l+(r-l)/2;
        if(a[m]<=x) l = m+1;
        else r = m;
    }
    return l;
}                
int main(){
  int a[7]={0, 1, 2, 2, 2, 2, 3};
  printf("%d\n",bsearch(a, 1, 7, 2));
  printf("%d\n",lower_bound(a, 1, 7, 2));
  printf("%d\n",upper_bound(a, 1, 7, 2));
  while(1);
  return 0;
}
