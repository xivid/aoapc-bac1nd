#include<iostream>
using namespace std; 
int main()
{
    bool left=true;
    char c;
    while((c=cin.get())!=EOF){
     /*   
     if(c=='"')  // " 和 \" 都可以 
      if(left) {cout << "``"; left=false;} //~键 
      else {cout <<"''"; left=true;} // '键 
      */
     if(c=='"') {cout<< (left? "``" : "''"); left=!left;}  
       // ?:不加括号会发生优先级错误而将左引号输出为1，右引号输出为0 
     else cout << c;
    }    
    return 0;
}    
