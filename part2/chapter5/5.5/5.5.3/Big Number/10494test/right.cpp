    #include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    using namespace std;
    long long  const M=1000000;
    char str[M];
    char newstr[M];
    long long  n;
    int main()
    {
        char ch;
        memset(str,0,sizeof(str));
        while(scanf("%s",str) == 1){
            memset(newstr,0,sizeof(newstr));
            n = 0;
            ch = getchar();
            while(ch == ' ')
              ch = getchar();
              cin >> n;
              getchar();
              long long  mod = 0;
              long long  num = 0;
              long long  len = strlen(str);
              if(ch == '%')
              {
                  for(long long i = 0;i < len; i++)
                  {
                      mod = mod*10 + str[i] - '0';
                      if(mod >= n)
                        mod = mod % n;
                  }
                  cout << mod << endl;
              }
              int flag = 0,k = 0;
              int fflag = 0;
              if(ch == '/')
              {
                  for(long long  i = 0; i < len ; i++)
                  {
                      num = num*10 + str[i] - '0';
                      if(num >= n)
                      {
                          fflag = 1;
                          break;
                      }
                  }
                  num = 0;

                   if(!fflag) cout << '0' ;
                   else

                  for(long long i = 0; i < len; i++)
                  {
                      num = num*10 + str[i] - '0';

                      if(num < n && flag)
                      {
                         // cout<<'0';

                          newstr[ k++ ] = '0';
                      }
                     if(num >= n)
                      {
                          flag = 1;

                         // cout << num/n;
                          newstr[ k++ ] = num/n + '0';
                          num %= n;
                      }


                  }
                  cout<< newstr <<endl;
                // cout << endl;
              }
              memset(str,0,sizeof(str));
            //  cout << endl;
        }
        return 0;
    }
