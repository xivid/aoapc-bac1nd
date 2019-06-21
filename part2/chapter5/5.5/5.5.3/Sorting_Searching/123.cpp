//搞出了这个超级麻烦题，振奋人心啊
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cctype>
using namespace std;
map<string,int> isign,iskey; //isignore  iskeyword
string title[201];
int totkey,tott;
struct key{
  string word;
  int tot;
  int tno[201][2];
}keyword[1000];
bool cmp_key(key a,key b)
{
  return a.word < b.word;
}
void print(string title,int pos)
{
  int l=title.length(),b=1;
  for(int i=0;i<l;i++)
  {
    if(b!=pos) cout <<(char)tolower(title[i]);
    else cout << (char)toupper(title[i]);
    if(title[i]==' ') b++;
  }
  cout << '\n';
}
int main()
{
  tott=totkey=0;
  string buf,word;
  while(getline(cin,buf))
  {
    if(buf=="::")
    {
      //cout <<"ignore all.\n";
      break;
    }
    isign[buf]=1;
    //if(isign[buf]) cout << buf << " ignored.\n";
  }
  while(getline(cin,buf))
  {
    title[++tott]=buf;
    //cout << "Title " << tott << ":"<< title[tott] <<":"<< endl;
    int p=0,l=buf.length(),no=0;
    while(p<l){
      word=""; no++;
      while(buf[p]==' '&&p<l) p++;
      while(buf[p]!=' '&&p<l) {word+=tolower(buf[p]); p++;}
      if(isign[word])
        {
        //cout << "..word #" << no<<":"<<word <<",ignored."<<endl;
         continue;
        }
      else
      {
        //cout <<"..word #"<<no<<":"<<word<<",";
        if(iskey[word])
        {
          //cout<<"already existed. No.";
          ++keyword[iskey[word]].tot;
          //cout << keyword[iskey[word]].tot<<",title "; //
          keyword[iskey[word]].tno[keyword[iskey[word]].tot][0]=tott; //
          //cout << tott;
          //cout << " at word #" <<no << endl;
          keyword[iskey[word]].tno[keyword[iskey[word]].tot][1]=no; //
        }
        else
        {
          //cout <<"not exist.Make it key No.";
          totkey++;
          iskey[word]=totkey;
          //cout << totkey <<",word ";
          keyword[totkey].word=word;
          //cout << word <<",of which title No."; //
          ++keyword[totkey].tot;
          //cout << keyword[totkey].tot; //
          keyword[totkey].tno[keyword[totkey].tot][0]=tott;
          //cout <<",is title No." << tott <<", with word #";
          keyword[totkey].tno[keyword[totkey].tot][1]=no;
          //cout << no << endl;
        }
      }
    }
  }
  sort(keyword+1,keyword+totkey+1,cmp_key);
  for(int i=1;i<=totkey;i++)
  {
    //cout << "Keyword #" << i << " " << keyword[i].word << ":" << endl;
    for(int j=1;j<=keyword[i].tot;j++)
     print(title[keyword[i].tno[j][0]],keyword[i].tno[j][1]);
  }
  return 0;
}
/*
Sample Input

is
the
of
and
as
a
but
::
Descent of Man
The Ascent of Man
The Old Man and The Sea
A Portrait of The Artist As a Young Man
A Man is a Man but Bubblesort IS A DOG

Sample Output

a portrait of the ARTIST as a young man
the ASCENT of man
a man is a man but BUBBLESORT is a dog
DESCENT of man
a man is a man but bubblesort is a DOG
descent of MAN
the ascent of MAN
the old MAN and the sea
a portrait of the artist as a young MAN
a MAN is a man but bubblesort is a dog
a man is a MAN but bubblesort is a dog
the OLD man and the sea
a PORTRAIT of the artist as a young man
the old man and the SEA
a portrait of the artist as a YOUNG man
//
ARTIST
a portrait of the ARTIST as a young man
ASCENT
the ASCENT of man
BUBBLESORT
a man is a man but BUBBLESORT is a dog
DESCENT
DESCENT of man
DOG
a man is a man but bubblesort is a DOG
MAN
descent of MAN
the ascent of MAN
the old MAN and the sea
a portrait of the artist as a young MAN
a MAN is a man but bubblesort is a dog
a man is a MAN but bubblesort is a dog
OLD
the OLD man and the sea
PORTRAIT
a PORTRAIT of the artist as a young man
SEA
the old man and the SEA
YOUNG
a portrait of the artist as a YOUNG man
*/
