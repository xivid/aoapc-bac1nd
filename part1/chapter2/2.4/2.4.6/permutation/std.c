

# include "stdio.h"

void main () {

    int a,b,c,d,e,f,g,h,i;

    for (a=1; a<=3; a=a+1)

       for (b=1; b<=9; b=b+1) {

           if (b!=a)

              for (c=1; c<=9; c=c+1) {

                  if (c!=a && c!=b)

                     for (d=a*2; d<=9; d=d+1) {

                         if (d!=a && d!=b && d!=c)

                            for (e=1; e<=9; e=e+1) {

                                if (e!=a && e!=b && e!=c && e!=d)

                                   for (f=1; f<=9; f=f+1) {

                                       if (f!=a && f!=b && f!=c && f!=d && f!=e)

                                          for (g=a*3; g<=9; g=g+1) {

                                              if (g!=a && g!=b && g!=c && g!=d && g!=e && g!=f)

                                                 for (h=1; h<=9; h=h+1) {

                                                     if (h!=a && h!=b && h!=c && h!=d && h!=e && h!=f && h!=g)

                                                        for (i=1; i<=9; i=i+1) {

                                                            if (

                                                               i!=a && i!=b && i!=c && i!=d && i!=e && i!=f && i!=g && i!=h &&

                                                               (a*100+b*10+c)*2==d*100+e*10+f &&

                                                               (a*100+b*10+c)*3==g*100+h*10+i

                                                               )

                                                               printf("%d%d%d, %d%d%d, %d%d%d\n",a,b,c,d,e,f,g,h,i);

                                                        }

                                                 }

                                          }

                                   }

                            }

                     }

              }

       }



    return;

}
