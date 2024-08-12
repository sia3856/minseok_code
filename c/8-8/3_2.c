/*double형 사용*/

#include<stdio.h>

int main(void)
{
    double a, b, c, d, e, f;
    a = 30.0 / 40.0 *5.0;
    b = 30.0 / (4.0 * 5.0);
    c = 30 / 4 * 5;
    d = 30 * 5 / 4;
    e = 30 / 4.0 * 5;
    f = 30 / 4 * 5.0;

    printf("a : %lf\n",a);
    printf("b : %lf\n",b);
    printf("c : %lf\n",c);
    printf("d : %lf\n",d);
    printf("e : %lf\n",e);
    printf("f : %lf\n",f);
   
   return 0;

}

/*a : 3.750000
  b : 1.500000
  c : 35.000000
  d : 37.000000
  e : 37.500000
  f : 35.000000*/