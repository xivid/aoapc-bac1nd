#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 5000;
//idea: s[0]做符号位 s[0]=0(0),1(>0),-1(<0)
struct bign{
        int len,s[maxn+1];
        bign() { len=0; memset(s,0,sizeof(s)); s[0]=0;}
        //赋值
        bign operator = (const char* str){
            len=strlen(str);
            for(int i=1;i<=len;i++) s[i]=str[len-i]-'0';
            return *this;
        }
        bign operator = (const int num){
            char str[maxn];
            sprintf(str,"%d",num);
            *this = str;
            return *this;
        }
        bign(const char* str){*this=str;}
        bign(const int num){*this=num;}
        //字符串
        string str() const{
            string res="";
            for(int i=len;i>0;i--) res+=char(s[i]+'0');
            if(res=="") res="0";
            return res;
        }
        //比较
        bool operator < (const bign& b) const {
            if(len!=b.len) return len<b.len;
            else {
              for(int i=len;i>0;i--)
               if(s[i]!=b.s[i]) return s[i]<b.s[i];
               }
            return false;
        }
        bool operator >(const bign& b) const {return (b<*this);}
        bool operator >=(const bign& b) const {return !(*this<b);}
        bool operator <=(const bign& b) const {return !(b<*this);}
        bool operator !=(const bign& b) const {return (b<*this)||(*this<b);}
        bool operator ==(const bign& b) const {return !(b<*this)&&!(*this<b);}
        //运算
        bign operator + (const bign& b) {
          bign x;
          int k=0;
          for(int i=1;i<=max(len,b.len)+1;i++){
              k=s[i]+b.s[i]+k;
              x.s[++x.len]=k%10;
              k/=10;
             }
          if(x.s[x.len]==0) x.len--;
          return x;
        }
        bign operator += (const bign& b) {
          *this=*this+b;
          return *this;
        }
        bign operator - ( const bign& b) const {
          //暂时只支持（大-小）
          if(*this<b) {
              //to be developed..
              return -1;
              }
          else {
              if(*this==b) return 0;
              bign x;
              x.len=max(len,b.len);
              int k=1;
              for(int i=1;i<=x.len;i++){
                k=10+s[i]-1+k-b.s[i];
                x.s[i]=k%10;
                k=k/10;
              }
              if(x.s[x.len]==0) x.len--;
              return x;
          }
        }
        bign operator -=(const bign& b){
            *this=*this-b;
            return *this;
        }
        bign operator * (const int& b) const{
            bign x;
            int c=0;
            for(int i=1;i<=maxn;i++) {
              c=s[i]*b+c;
              x.s[i]=c%10;
              c/=10;
            }
            for(int i=maxn;i>0;i--) if(x.s[i]!=0) {x.len=i; break;}
            return x;
        }
        bign operator *=(const int& b){
            *this=*this*b;
            return *this;
        }
        bign operator * (const bign& b) const {
            bign x;

            return x;
        }
        bign operator *=(const bign& b){
            *this=*this*b;
            return *this;
        }
        bign operator / ( const bign& b) const {
            bign x;

            return x;
        }
        bign operator /=(const bign& b){
            *this=*this/b;
            return *this;
        }
    };
istream& operator >> (istream& in,bign& x){
    string s;
    in >> s;
    x=s.c_str();
    return in;
}
ostream& operator << (ostream& out,const bign& x){
    out << x.str();
    return out;
}
int main()
{
    bign a,b;
    cin >> a>>b;

    if(a<b) cout << "a<b"<<endl;
    if(b>a) cout <<"b>a"<<endl;
    if(a==b) cout <<"a=b"<<endl;
    if(a!=b) cout <<"a!=b" << endl;
    if(a>=b) cout <<"a>=b" << endl;
    if(b<=a) cout <<"b<=a" << endl;

    int c;
    cin >> c;
    a*=c;
    cout << a <<" "<< a.len <<endl;
    return 0;
}
