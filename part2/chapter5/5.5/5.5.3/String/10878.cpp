#include<cstdio>
#include<cstdlib>
int main()
{
    char pwd[15],decode=0;
    gets(pwd);
    for(;;){
        gets(pwd);
        if(pwd[1]=='_') break;
        decode=0;
        for(int i=1;i<=5;i++) if(pwd[i]=='o') decode+=1<<(8-i);
        for(int i=7;i<=9;i++) if(pwd[i]=='o') decode+=1<<(9-i);
        putchar(decode);
    }
    return 0;
}
/*
规律：空格为0，o为1，线、点忽略，代表的8位二进制数恰好为该字符的ASCII码。
A quick brown fox jumps over the lazy dog.
___________
| o   .  o|A
|  o  .   |
| ooo .  o|q
| ooo .o o|u
| oo o.  o|i
| oo  . oo|c
| oo o. oo|k
|  o  .   |
| oo  . o |b
| ooo . o |r
| oo o.ooo|o
| ooo .ooo|w
| oo o.oo |n
|  o  .   |
| oo  .oo |f
| oo o.ooo|o
| oooo.   |x
|  o  .   |
| oo o. o |j
| ooo .o o|u
| oo o.o o|m
| ooo .   |p
| ooo . oo|s
|  o  .   |
| oo o.ooo|o
| ooo .oo |v
| oo  .o o|e
| ooo . o |r
|  o  .   |
| ooo .o  |t
| oo o.   |h
| oo  .o o|e
|  o  .   |
| oo o.o  |l
| oo  .  o|a
| oooo. o |z
| oooo.  o|y
|  o  .   |
| oo  .o  |d
| oo o.ooo|o
| oo  .ooo|g
|  o o.oo |.
|    o. o |
___________
*/
