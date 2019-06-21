#include<cstdio>
#include<cstdlib>
#include<cstring>
int bit[2100];
//映射为树的节点，结果uva上WA，POJ上AC
int main()
{
    memset(bit,0,sizeof(bit));
    char buf[15];
    int flag=0,set=1;
    while(scanf("%s",buf)!=EOF)
    {
        if(buf[0]=='9')
        {
            if(flag) printf("Set %d is not immediately decodable\n",set);
            else printf("Set %d is immediately decodable\n",set);
            memset(bit,0,sizeof(bit)); flag=0; set++;
        }
        else{
            int l=strlen(buf),p=1;
            for(int i=0;i<l;i++)
            {
                if(buf[i]=='0') p*=2;
                else if(buf[i]=='1') p=p*2+1;
                if(bit[p]) flag=1;
            }
            bit[p]=1;
        }
    }
    return 0;
}
/*
 Sample Input

01
10
0010
0000
9
01
10
010
0000
9

Sample Output

Set 1 is immediately decodable
Set 2 is not immediately decodable

*/
