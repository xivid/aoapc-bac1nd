#include <iostream>
using namespace std;

const int MAXSIZE=100000;
char str[MAXSIZE];
char in[MAXSIZE];
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

int getStr(int pos)
{
	if(pos==len)
	{
		return 0;
	}

	int ret=0;

	for(int i=0;i<in[pos-1]-'a';++i)
	{
		if(l[i]>0)
		{
			--l[i];
			ret+=f();
			++l[i];
		}
	}
	--l[in[pos-1]-'a'];
	ret+=getStr(pos+1);
	return ret;
}

int main()
{
	memset(str,0,sizeof(str));
	memset(in,0,sizeof(in));
	memset(l,0,sizeof(l));

	cin>>str>>in;
	//cin >> in;
  //strcpy(str,in);
	len=strlen(str);

	for(int i=0;i<len;++i)
	{
		l[str[i]-'a']++;//l[]统计各个字符出现的次数 
	}
	
	cout<<getStr(1)+1<<endl;
  
  while(1);
	return 0;
}
