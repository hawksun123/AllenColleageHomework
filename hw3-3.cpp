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
 
  程式執行輸出畫面舉例如下: 
 
  特別獎號碼 
  請輸入第一個號碼:56188690 
  請輸入第二個號碼:14764245 
  請輸入第三個號碼:41275633 
  頭獎號碼 
  請輸入第一個號碼:68285428 
  請輸入第二個號碼:12031965 
  請輸入第三個號碼:92658431 
  使用者發票號碼 
  請輸入第一個號碼:41275633 
  請輸入第二個號碼:92631965 
  請輸入第三個號碼:51868431 
  獎金 2005000 元 
 
  Copyright (c) 2016 by Hawk Sun
 
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

#define DEBUG 0
#define SPECIAL_PRICE_COUNT 3
#define FIRST_PRICE_COUNT 3
#define USER_NO_COUNT 3
#define RECEIPT_LEN 8
#define SUCCESS 8
#define DIGITS_COMPARE_TIMES RECEIPT_LEN - 3 + 1

void InputPriceReceiptNo(char array[][9] , int count);

int main(void)
{
  char  specialPrice[SPECIAL_PRICE_COUNT][9];
  char  firstPrice[FIRST_PRICE_COUNT][9];
  char  userNo[USER_NO_COUNT][9];

  int   price[] = {2000000, 200000, 40000, 10000, 4000, 1000, 200};
  int   loop1, loop2, loop3;
  int   total = 0;

  printf("特別獎號碼\n");
  InputPriceReceiptNo(specialPrice, SPECIAL_PRICE_COUNT);

  printf("頭獎號碼\n");
  InputPriceReceiptNo(firstPrice, FIRST_PRICE_COUNT);

  printf("使用者發票號碼\n");
  InputPriceReceiptNo(userNo, USER_NO_COUNT);
  
  for (loop1 = 0; loop1 < USER_NO_COUNT; loop1++) {
    // 特別獎獎金計算
    for (loop2 = 0; loop2 < SPECIAL_PRICE_COUNT; loop2++) {
        if (0 == strcmp(userNo[loop1], specialPrice[loop2])){ // win
          total += price[0];
  #if DEBUG
          printf("特別獎獎金%d元\n", total);
  #endif
        }
    } // loop2

    // 頭獎獎金計算
    for (loop2 = 0; loop2 < FIRST_PRICE_COUNT; loop2++) {
      for (loop3 = 0; loop3 < DIGITS_COMPARE_TIMES; loop3++) {
        if (0 == strcmp((userNo[loop1] + loop3), (firstPrice[loop2] + loop3))){ // win
            total += price[loop3 + 1];
#if DEBUG
            printf("userNo[%d][%d] = %s, firstPrice[%d][%d] = %s\n", \
                   loop1, loop3, userNo[loop1] + loop3, loop2, loop3, firstPrice[loop2] + loop3);
            printf("頭獎獎金%d元\n", total);
#endif
            break; // exit the loop3, means to compare the next number
          }
      } // loop3
    } // loop2
  } // loop1
  
  printf("\n獎金%d元", total);
  
  return SUCCESS;
}

void InputPriceReceiptNo(char array[][9] , int count)
{
  int   loop;
  char  chtDigits[][3] = {"一", "二", "三","四","五","六","七","八","九"};

  for (loop = 0; loop < count; loop++) {
    printf("請輸入第%s個號碼:", chtDigits[loop]);
    scanf("%s", array[loop]);
  }
}

