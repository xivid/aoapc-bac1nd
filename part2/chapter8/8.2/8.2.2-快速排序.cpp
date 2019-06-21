#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
void quicksort(int *a, int l, int r){
  //貌似这个是确定不了枢纽元素的位置的
  int tl = l, tr = r, m = a[(tl+tr)>>1];
  while(tl<tr){
    while(a[tl] < m) tl++;
    while(a[tr] > m) tr--;
    if(tl <= tr){ int t=a[tl]; a[tl] = a[tr]; a[tr] = t; tl++; tr--;}
  }
  //printf("tl=%d,tr=%d\n",tl,tr);
  //if (a[tl] == m) printf("tl!\n");
  //if (a[tr] == m) puts("tr!");
  if(tl < r) quicksort(a, tl, r);
  if(tr > l) quicksort(a, l, tr);
}
void qsort(int a[], int l, int r){
  if(l>r) return;
  int i = l, j = r, k = a[(l+r)>>1]; a[(l+r)>>1] = a[l];  a[l] = k;
  do{
    while(i<j && a[i] <= k) i++; if(i<j) {a[j] = a[i]; j--;}
    while(i<j && a[j] >= k) j--; if(i<j) {a[i] = a[j]; i++;}
  }while(i!=j);
  a[i] = k;
  qsort(a, l, i-1);
  qsort(a, i+1, r);
}
int main(){
  srand(time(NULL));
  int a[100], n;
  //scanf("%d",&n);
  n = rand() % 100;
  assert(n < 100);
  for(int i=1; i<=n; i++) a[i] = rand();//scanf("%d", a + i);
  qsort(a,1,n);
  for(int i=1; i<=n; i++) printf("%d ", a[i]);
  return 0;
}
