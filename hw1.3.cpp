#include <stdio.h>

int main() {

   /* my first program in C */
   float  mynum1 = 123.456789012345;
   double mynum2 = 123.456789012345;

   printf("%7.2f\n", mynum1);
   printf("%7.2lf\n", mynum2);

   printf("%+012.6f\n", mynum1);
   printf("%+012.6f\n", mynum2);

   printf("%16.12f\n", mynum1);
   printf("%16.12f", mynum2);

   return 0;
}
