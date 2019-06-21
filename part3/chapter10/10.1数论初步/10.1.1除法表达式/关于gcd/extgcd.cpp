#include<iostream>
using namespace std;
void gcd(int a, int b, int& d, int& x, int& y){
    if(!b) {d = a; x = 1; y = 0;}
    else {gcd(b, a%b, d, y, x); y-=x*(a/b);}
}    
int main(){
    int d, x, y, a, b;
    cin >> a >> b;
    gcd(a, b, d, x, y);
    cout << "x = " << x << ", y = " << y << endl;
    while(1);
    return 0;
}    
