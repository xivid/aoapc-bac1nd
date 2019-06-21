#include<iostream>
#include<cmath>
#include<iomanip>
//超级大水题，我浪费了大量时间想它和排序、检索有什么关系，想有什么比较好的算法，结果什么也没想出来
using namespace std;
double x[5010],y[5010],z[5010];//题目好像没说坐标必须是int
int n;
int ans[10]={0};
int main()
{
    n=0;
    double a,b,c,dx,dy,dz;
    int dist=-1,min=-1;
    for(;;)
    {
      cin>>a>>b>>c;
      if(!(a==0&&b==0&&c==0)) {x[++n]=a; y[n]=b; z[n]=c;}
      else break;
    }
    for(int i=1;i<=n;i++){
     min=-1;
     for(int j=1;j<=n;j++)
      if(i!=j)
      {
        dx=x[i]-x[j]; dy=y[i]-y[j]; dz=z[i]-z[j];
        dist=(int)sqrt(dx*dx+dy*dy+dz*dz);
        if(dist<min||min==-1) min=dist;
      }
        ans[min]++;
    }
    for(int i=0;i<10;i++) cout << setw(4) << ans[i];
    cout << endl;
    return 0;
}
