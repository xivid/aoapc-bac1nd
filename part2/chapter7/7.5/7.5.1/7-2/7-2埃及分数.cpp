#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
using namespace std;
int gcd(int n, int m){ return m?gcd(m,n%m):n;}
struct frac{ //fraction
    int u,d; // up/down
    frac(){u=1; d=1;} 
    void assign(int xu, int xd){u=xu; d=xd;}
    void reduce(){
        int g=gcd(u,d);
        u/=g; d/=g;    
    }
    frac operator +(const frac& x) const {
        frac ans;
        ans.u = u * (x.d) + d * (x.u);
        ans.d = d * (x.d);
        ans.reduce(); 
        return ans;
    }
    frac operator -(const frac& x) const{
        frac ans;
        ans.u = u * (x.d) - (x.u) * d;
        ans.d = d * (x.d);
        ans.reduce();
        return ans;
    }    
    int operator /(const frac& x) const{
        return (int)ceil((double)(u*(x.d))/(d*(x.u)));
    }    
    frac operator = (const char s[]){
        sscanf(s, "%d/%d", &u, &d);
        return *this;
    }     
    double ans(){return (double)u/d;}
    frac(const char s[]) { *this = s;}
    bool operator ==(const frac x){ if(x.u==u&&x.d==d) return true; return false;}
}; 
istream& operator >> (istream& in, frac& x){
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream& operator << (ostream& out, const frac& x) {
    out << x.u << "/" << x.d;
}
int num, depth;
frac ans[1000], n;    
bool dfs(frac s, frac last, int depth, int maxdepth){
    ans[depth] = last;
    cout << "s=" << s <<"+"<<last <<"=" << s+last << endl;
    s=s+last; 
    if(s==n&&depth<=maxdepth) {num=depth; return true;}
    else if(depth>=maxdepth) return false;
    if((s-n).u>0) {cout <<"da le\n";cin.get();}
    frac t=last; t.d++;
    int ok=1;
    while(!dfs(s, t, depth+1, maxdepth)) {
        t.d++;
        cout << "maxd=" << maxdepth << "depth =" << depth << ", over?";
        cout <<(n-s)/t << endl;
        cin.get();
        if((n-s)/t>(maxdepth-depth)) {cout <<"strongly cut!!\n"; ok=0; break;}
    }
    if(ok) return true;
    return false;
}    
void out(){
    if(flag) {
        cout << n << " = ";
        for(int i=1; i<num; i++) cout << ans[i] <<" + "; 
        cout << ans[num] << endl;
    }
    else cout << "Not Found.\n";
}    
int main(){
    frac init="1/2";
    cin >> n;
    n.reduce();
    
    out();
    system("pause");    
    return 0;
}    
// 2/3 = 1/2 + 1/6
// 19/45 = 1/5 + 1/6 + 1/18
