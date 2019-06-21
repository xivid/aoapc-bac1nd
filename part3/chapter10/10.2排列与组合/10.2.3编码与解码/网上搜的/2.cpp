#include <iostream> 
#include <cstring>
using namespace std;

const int MAXSIZE=100000;
char str[MAXSIZE];
char out[MAXSIZE];
int l[26];
int len;
int num;

int g(int n)
{
	int ret=1;
	for(int i=1;i<=n;++i)
	{
		ret*=i;
	}
	return ret;
}

int f()
{
	int top=0,bot=1;
	for(int i=0;i<26;++i)
	{
		top+=l[i];
		bot=bot*g(l[i]);
	}
	int ret=g(top)/bot;
	return ret;
}

bool getStr(int pos,int cur){
	if(cur==len){ 
	  //cout << "try.." << out << "?..try" << endl;
		for(int j=0;j<26;++j) if(l[j]){
     out[cur-1] =j+'a';
     break;
		}
		cout<<out<<endl;
		return true;
	}
	else{
		int now=0;
		for(int i=0;i<26;++i) if(l[i]>0){
				l[i]--;
				now+=f();
				if(now>=pos){
					out[cur-1]=i+'a';
					if(getStr(pos-(now-f()),cur+1))	return true;
				}
				l[i]++;
			}
		}
	return false;
}
int main()
{
	memset(str,0,sizeof(str));
	memset(out,0,sizeof(out));
	memset(l,0,sizeof(l));
	cin>>str>>num;
	len=strlen(str);
	memset(l,0,sizeof(l));
	for(int i=0;i<len;++i)
	{
		l[str[i]-'a']++;
	}
	if(!getStr(num,1))
	{
		cout<<"false"<<endl;
	}
	while(1);
	return 0;
}
