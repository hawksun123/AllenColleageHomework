#include <stdio.h>
#include <math.h>

int main(void)
{
  int a[2];
  double c[2];

  int loop;

  for (loop = 0; loop < 2; loop++) {
    printf("請輸入通話分鐘數 %d:", loop + 1);
    scanf("%d", &a[loop]);
    a[loop] = abs(a[loop]);


    if (a[loop] <= 600){
      c[loop] = 0.5 * a[loop];
    } else if (a[loop] <= 1200) {
             c[loop] = 600 * 0.5 + (a[loop]-600) * 0.45;
           } else {
             c[loop] = 600 * 0.5 + 600*0.45 + (a[loop]- 1200)*0.4;
           }
           
    if (c[loop] > 200 && c[loop] <= 450)
      c[loop] *= 0.9;
    else if (c[loop] > 450 && c[loop] <= 750)
         c[loop]*= 0.8;
      else if (c[loop] > 750)
           c[loop]*= 0.7;

    printf("通話費 %d:%d\n", loop+1, (int) c[loop]);


  }

  
  return 0;
}
