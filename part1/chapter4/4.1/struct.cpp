#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct Point
{
  int x,y;
  void getxy()
  {
   cin >> x >> y;
  }
  double hypot()
  {
   return sqrt(x*x+y+y);
  }
  double dist(Point t)
  {
   return sqrt((x-t.x)*(x-t.x)+(y-t.y)*(y-t.y));
  }
 };

double dist(Point x,Point y)
{
 return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
int main()
{
 Point m,n;
 cout << "Locate m:";
 m.getxy();
 cout << m.hypot() << endl;
 cout << "Locate n:";
 n.getxy();
 cout << n.hypot() << endl;
 cout << "m->n distance: "
       << m.dist(n) << endl;
 cout << "m<-n distance: "
       << n.dist(m) << endl;
 cout << "m<->n distance: "
       << dist(m,n) <<endl;
 return 0;
}
