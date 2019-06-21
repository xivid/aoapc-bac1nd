 #include <cstdio>

#include <cstdlib>

using namespace std;



bool ck(int x, int y, int z) {

    int t[9], s1 = 0, s2 = 1, i;

    t[0] = x / 100;

    t[1] = x / 10 % 10;

    t[2] = x % 10;

    t[3] = y / 100;

    t[4] = y / 10 % 10;

    t[5] = y % 10;

    t[6] = z / 100;

    t[7] = z / 10 % 10;

    t[8] = z % 10;

    for (i = 0; i < 9; i++) {

       s1 += t[i];

       s2 *= t[i];

    }

    if (s1 == 45 && s2 == 362880) return true;

    else return false;

}



int main() {

    int i;

    for (i = 111; i < 333; i++)

       if (ck(i, 2 * i, 3 * i))

           printf("%d %d %d\n", i, 2 * i, 3 * i);



    return 0;

}
