//copy 别人的
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 20 + 10
#define MAX 70 + 10
char keyWords[MAXN][MAX];
char excuses[MAXN][MAX];
int matchedNumber[MAXN];
int max(int a, int b)
{if(a > b) return a;
 else return b;
}
int nubmerOfKeyWords;
int numberOfExcuses;
int bruteForce()
{
  int i, j, k;
  int maxResult = 0;
  int d = 0;
  char word[MAX];
  for(i = 0; i < numberOfExcuses; i++)
  {
    for(j = 0; j < strlen(excuses[i]); j++)
    {
        if(isalpha(excuses[i][j]))
        {
            word[d++] = tolower(excuses[i][j]);
        }
        else
        {
            word[d] = '\0';
            d = 0;
            for(k = 0; k < nubmerOfKeyWords; k++)
            {
              if(strcmp(keyWords[k], word) == 0)
              matchedNumber[i]++;
            }
        }
    }
    maxResult = max(matchedNumber[i], maxResult);
  }
  return maxResult;
}
int main()
{
    int i, j;
    char c;
    int cases = 0;
    while(scanf("%d%d", &nubmerOfKeyWords, &numberOfExcuses) != EOF)
    {
        memset(matchedNumber, 0, sizeof(matchedNumber));
        cases++;
        c = getchar();
        for(i = 0; i < nubmerOfKeyWords; i++) gets(keyWords[i]);
        for(i = 0; i < numberOfExcuses; i++) gets(excuses[i]);
        int maxResult = bruteForce();
        printf("Excuse Set #%d\n", cases);
        for(i = 0; i < numberOfExcuses; i++)
            if(matchedNumber[i] == maxResult)
            {
                printf("%s\n", excuses[i]);
            }
        printf("\n");
    }
    return 0;
}

