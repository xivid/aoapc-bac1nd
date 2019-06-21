#include<iostream>
#include<cstring>
using namespace std;
//实现赋值、返回string、输入输出 
const int maxn = 5000;
class bign{
    private:
        int len,s[maxn];
    public:
        bign() { len=0; memset(s,0,sizeof(s));}
        bign operator = (const char* str){
            len=strlen(str);
            for(int i=1;i<=len;i++) s[i]=str[len-i]-'0'; //注意char->int有'0' 
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
        string str() const{        
            string res="";
            for(int i=len;i>0;i--) res+=char(s[i]+'0');
            if(res=="") res="0";
            return res;
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
    bign a=300,b="123";
    cout << a.str() << b.str() << endl;
    a=123; b="4564";
    cout << a.str() << b.str() << endl;
    cin >> a >> b;
    cout << a <<" "<< b;
    system("pause");
    return 0;
} 
