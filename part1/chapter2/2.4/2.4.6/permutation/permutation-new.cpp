    // 习题2-10 样例（permutation）

    #include <stdio.h>
    int main(void)
    {
        int x, y, z, a[10] = {0};
        for(x = 100; x < 333; x++)
        {
            y = 2*x;
            z = 3*x;
            //令a[出现的数字] = 1
            a[x/100] = a[x/10%10] = a[x%10] = 1;
            a[y/100] = a[y/10%10] = a[y%10] = 1;
            a[z/100] = a[z/10%10] = a[z%10] = 1;
            int i, s = 0;
            for(i = 1; i < 10; i++)
                s += a[i];
            if(s == 9)
                printf("%d\t%d\t%d\n", x, y, z);
            for(i = 1; i < 10; i++)  //重新赋值为0
                a[i] = 0;
        }
        return 0;
    }
