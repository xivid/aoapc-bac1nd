    #include <iostream>
    #include <cmath>
    #include <stdio.h>
    using namespace std;

    int main(){
        // 进行整数之间的乘法，参数为指数
        int index = 0;
        // 先用char型数组来接收输入的底数
        char arg[6] = {};
        while(cin >> arg >> index){
            // 用来接收输入的数
        int num[5] = {};
        int num1 = 0;
        // 用于接收小数点的位置
        int p = 0;
        //用於接收末尾的個數
        int q = 0;
        // 用来保存最后的结果
        int result[155] = {};
        // 将接收来的数转成int型,j为num的下标
        int j = 4;
        for(int i = 0; i < 6; i++){
            if(arg[i] != '.'){
                num[j] = arg[i] - '0';
                num1 += num[j] * pow(10.0,j);
                result[j] = arg[i] - '0';
                j--;
            }else {
                p = i + 1;
            }

            if(arg[i] == '0'){
                q++;
            }else{
                q = 0;
            }
        }
        // 双重循环
        int t = 4;
        for(int i = 0; i < index - 1; i++){
                int temp = 0;
                for(int k = 0; k <= t;k++){
                    result[k] = result[k] * num1;
                    }
                                //进位循环
                    for(int j = 0;j < t + 5;j++){
                        temp = result[j];
                        result[j] = temp % 10;
                        result[j + 1] = result[j + 1] + temp / 10;

                }
                t += 5;
        }

        // 输出结果
        bool isZero = true;
        bool isZero2 = false;
        for(int i = 0; i < 155;i++){

            if(154 - i == q * index - 1){
                isZero2 = true;
            }

            if(154 - i == ((6 - p) * index) - 1){
                if(q * index - 1 == ((6 - p) * index) - 1){

                }else{
                    cout << '.';
                }
            }
            if((result[154 - i]) != 0 ||(154 - i == (6 - p) * index - 1)){
                isZero = false;
            }

            int s = q * index;

            if(!isZero && !isZero2){
                    cout << result[154 - i];
            }
        }
                cout << endl;
        }

        return 0;
    }
