/* 
 
  統一發票兌獎: 
  統一發票是一個八位數字(整數)的對獎方式，有三個特別獎號及三個頭獎獎號，獎金則是根據下
  面規則給付:
  和特別獎號碼完全相同         獎金 2000000 元 
  和頭獎號碼完全相同           獎金  200000 元 
  和頭獎號碼最後 7 位數字相同，獎金   40000 元 
  和頭獎號碼最後 6 位數字相同，獎金   10000 元 
  和頭獎號碼最後 5 位數字相同，獎金    4000 元 
  和頭獎號碼最後 4 位數字相同，獎金    1000 元 
  和頭獎號碼最後 3 位數字相同，獎金     200 元
 
  Copyright (c) 2016 by Hawk Sun
 
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define DEBUG 0
#define SPECIAL_NO_COUNT 3
#define FIRST_NO_COUNT 3
#define USER_NO_COUNT 3
#define RECEIPT_LEN 8
#define SUCCESS 8
#define DIGITS_COMPARE_TIMES RECEIPT_LEN - 3 + 1

int main(void)
{
  char  specialNo[SPECIAL_NO_COUNT][9];
  char  firstNo[FIRST_NO_COUNT][9];
  char  userNo[USER_NO_COUNT][9];

  int   price[] = {200000, 40000, 10000, 4000, 1000, 200};
  int   loop1, loop2, loop3;
  int   total = 0;
  int   equalFlag; // comparison result of firstNo[] & userNo[]
  int   index;

  printf("特別獎號碼\n請輸入第一個號碼:");
  scanf("%s", specialNo[0]);
  printf("請輸入第二個號碼:");
  scanf("%s", specialNo[1]);
  printf("請輸入第三個號碼:");
  scanf("%s", specialNo[2]);

  printf("頭獎號碼\n請輸入第一個號碼:");
  scanf("%s", firstNo[0]);
  printf("請輸入第二個號碼:");
  scanf("%s", firstNo[1]);
  printf("請輸入第三個號碼:");
  scanf("%s", firstNo[2]);

  printf("使用者發票號碼\n");
 

  // 特別獎獎金計算
  
  for (loop1 = 0; loop1 < USER_NO_COUNT; loop1++) {
    printf("請輸入第 %d 個號碼:", loop1 + 1);
    scanf("%s", userNo[loop1]);

    for (loop2 = 0; loop2 < SPECIAL_NO_COUNT; loop2++) {
      if (0 == strcmp(userNo[loop1], specialNo[loop2])){
        total += 2000000;
#if DEBUG
        printf("特別獎獎金%d元\n", total);
#endif

      }
    }
  }
  
  // 頭獎獎金計算

  for (loop1 = 0; loop1 < USER_NO_COUNT; loop1++) {
    for (loop2 = 0; loop2 < FIRST_NO_COUNT; loop2++) {
      for (loop3 = 0; loop3 < DIGITS_COMPARE_TIMES; loop3++) {
          equalFlag = false;

#if DEBUG
          printf("userNo[%d][%d] = %s, firstNo[%d][%d] = %s\n", \
                 loop1, loop3, userNo[loop1] + loop3, loop2, loop3, firstNo[loop2] + loop3);
#endif

          equalFlag = 0 == strcmp((userNo[loop1] + loop3), (firstNo[loop2] + loop3));
          if (equalFlag) {
            total += price[loop3];
#if DEBUG
            printf("頭獎獎金%d元\n", total);
#endif
            break; // exit the loop3, means to compare the next number
          }
          
        }
    }
  }
  
  printf("\n獎金%d元", total);
  
  return SUCCESS;
}


