#include<cstdio>
#include<queue>
using namespace std;
struct cmp{
  bool operator () (const int& a, const int& b) const{
    return a%10 > b%10;
  }
};    
int main(){
  {
    priority_queue<int> q;
    int a;
    for(int i = 1; i <= 10; ++i) {scanf("%d", &a); q.push(a);}
    while(!q.empty()) printf("%d ", q.top()), q.pop();
  }  
  {
    priority_queue<int, vector<int>, cmp> q;
    int a;
    for(int i = 1; i <= 10; ++i) {scanf("%d", &a); q.push(a);}
    while(!q.empty()) printf("%d ", q.top()), q.pop();
  }  
  {
    typedef pair<int, int> pii;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(make_pair(6,2));
    q.push(make_pair(2,6));
    printf("%d,%d ", q.top().first, q.top().second); q.pop();
    printf("%d,%d ", q.top().first, q.top().second); q.pop();
  }  
  while(1);
  return 0;
}  
