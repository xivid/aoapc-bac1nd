#include<iostream>
#include<stack>
#define MAXN 5000
using namespace std;
int main(){
    freopen("stack.in","r",stdin);
    int target[MAXN],n;
    while(cin>> n){
      stack<int> s;
      for(int i=1;i<=n;i++) cin >> target[i];
      int A=1,B=1,ok=1;
      while(B<=n){
        if(A==target[B]) {A++; B++;}
        else if(!s.empty()&&target[B]==s.top()) {s.pop();  B++;}
        else if(A<=n) s.push(A++);
        else {ok=0; break;}
      }
    if(ok) cout << "Yes";
    else cout <<"No";
    cout << endl;
    }
    return 0;
}
