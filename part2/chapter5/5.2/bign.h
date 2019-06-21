//此头文件似乎有问题，请慎用…… 
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define BIGN_MAXN 5000
class bign{
    private:
        int len,s[BIGN_MAXN];
    public:
        bign() {len=0; memset(s,0,sizeof(s));}
        ~bign() {}
        //visit private members
        int& at(int pos) {if(pos>len) return s[0]; else return s[pos];}
        int length() const {return len;}
        //assignment
        bign operator =(const char x[]){
            len=strlen(x);
            for(int i=1;i<=len;i++) s[i]=x[len-i]-'0';
            return *this;
        }
        bign operator =(const int x){
            char xx[BIGN_MAXN];
            sprintf(xx,"%d",x);
            *this=xx;
            return *this;
        }
        bign(const char x[]) {*this=x;}
        bign(const int x) {*this=x;}
        //to-string
        string str()const{
            string buf="";
            for(int i=len;i>0;i--) buf+=(char)(s[i]+'0');
            if(buf=="") buf = "0";
            return buf;
        }
        //comparision
        bool operator <(const bign x)const{
            if(len!=x.len) return(len<x.len);
            for(int i=len;i>0;i--) if(s[i]!=x.s[i]) return(s[i]<x.s[i]);
            return false;
        }
        bool operator >(const bign x)const { return x<*this;}
        bool operator ==(const bign x)const  { return (!(*this<x)&&!(x<*this));}
        bool operator !=(const bign x)const  { return (*this<x)||(x<*this);}
        bool operator <=(const bign x)const  { return !(x<*this);}
        bool operator >=(const bign x)const  { return !(*this<x);}
        //calculation
        bign operator + (const bign& x) const {
            bign ans;
            int len=max(this->len, x.len)+1;
            for(int i=1;i<=len;i++) {
                ans.s[i]+=this->s[i]+x.s[i];
                ans.s[i+1]=ans.s[i]/10;
                ans.s[i]%=10;
            }
            if(ans.s[len]==0&&len>0) len--;
            ans.len=len;
            return ans;
        }
        bign operator +=(const bign& x) {
            *this=*this+x;
            return *this;
        }
        bign operator - (const bign& x) const{

        }
        bign operator -=(const bign& x) {
            *this=*this-x;
            return *this;
        }
        bign operator *(const bign& x) const {
            bign ans;
            int len=this->len+x.len;
            for(int i=1;i<=this->len;i++)
             for(int j=1;j<=x.len;j++)
              ans.s[i+j-1]+=this->s[i]*x.s[j];
            for(int i=1;i<=len;i++) {
                 ans.s[i+1]+=ans.s[i]/10;
                 ans.s[i]%=10;
             }
            while(ans.s[len]==0&&len>0) len--;
            ans.len=len;
            return ans;
        }
        bign operator *=(const bign& x){
            *this=*this*x;
            return *this;
        }
        bign operator /(const int x) const {
            bign ans;
            if(*this<x) {ans=0; ans.len=1;}
            else {
                int k=0,len=this->len;
                for(int i=len;i>0;i--){
                    ans.s[i]=(k*10+this->s[i])/x;
                    k=(k*10+this->s[i])%x;
                }
                while(ans.s[len]==0&&len>0) len--;
                ans.len=len;
            }
            return ans;
        }
        bign operator /=(const int x){
            *this=*this/x;
            return *this;
        }
        /*
        // to be developed..
        bign operator /(const bign& x) const {

        }
        bign operator /=(const bign& x){
            *this=*this/l;
            return *this;
        }
        */
        // ++ --
        bign operator ++() {*this=*this+1; return *this;}
        bign operator ++(int) {*this=*this+1; return *this-1;}
};
//input&output
istream& operator >>(istream& in,bign& x ){
    string s;
    in >> s;
    x=s.c_str();
    return in;
}
ostream& operator << ( ostream& out, const bign& x){
    return out << x.str();
}
