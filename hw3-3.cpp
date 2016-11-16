/* 
 
  �Τ@�o���I��: 
  �Τ@�o���O�@�ӤK��Ʀr(���)������覡�A���T�ӯS�O�����ΤT���Y�������A�����h�O�ھڤU
  ���W�h���I:
  �M�S�O�����X�����ۦP         ���� 2000000 �� 
  �M�Y�����X�����ۦP           ����  200000 �� 
  �M�Y�����X�̫� 7 ��Ʀr�ۦP�A����   40000 �� 
  �M�Y�����X�̫� 6 ��Ʀr�ۦP�A����   10000 �� 
  �M�Y�����X�̫� 5 ��Ʀr�ۦP�A����    4000 �� 
  �M�Y�����X�̫� 4 ��Ʀr�ۦP�A����    1000 �� 
  �M�Y�����X�̫� 3 ��Ʀr�ۦP�A����     200 ��
 
  �{�������X�e���|�Ҧp�U: 
 
  �S�O�����X 
  �п�J�Ĥ@�Ӹ��X:56188690 
  �п�J�ĤG�Ӹ��X:14764245 
  �п�J�ĤT�Ӹ��X:41275633 
  �Y�����X 
  �п�J�Ĥ@�Ӹ��X:68285428 
  �п�J�ĤG�Ӹ��X:12031965 
  �п�J�ĤT�Ӹ��X:92658431 
  �ϥΪ̵o�����X 
  �п�J�Ĥ@�Ӹ��X:41275633 
  �п�J�ĤG�Ӹ��X:92631965 
  �п�J�ĤT�Ӹ��X:51868431 
  ���� 2005000 �� 
 
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

  printf("�S�O�����X\n");
  InputPriceReceiptNo(specialPrice, SPECIAL_PRICE_COUNT);

  printf("�Y�����X\n");
  InputPriceReceiptNo(firstPrice, FIRST_PRICE_COUNT);

  printf("�ϥΪ̵o�����X\n");
  InputPriceReceiptNo(userNo, USER_NO_COUNT);
  
  for (loop1 = 0; loop1 < USER_NO_COUNT; loop1++) {
    // �S�O�������p��
    for (loop2 = 0; loop2 < SPECIAL_PRICE_COUNT; loop2++) {
        if (0 == strcmp(userNo[loop1], specialPrice[loop2])){ // win
          total += price[0];
  #if DEBUG
          printf("�S�O������%d��\n", total);
  #endif
        }
    } // loop2

    // �Y�������p��
    for (loop2 = 0; loop2 < FIRST_PRICE_COUNT; loop2++) {
      for (loop3 = 0; loop3 < DIGITS_COMPARE_TIMES; loop3++) {
        if (0 == strcmp((userNo[loop1] + loop3), (firstPrice[loop2] + loop3))){ // win
            total += price[loop3 + 1];
#if DEBUG
            printf("userNo[%d][%d] = %s, firstPrice[%d][%d] = %s\n", \
                   loop1, loop3, userNo[loop1] + loop3, loop2, loop3, firstPrice[loop2] + loop3);
            printf("�Y������%d��\n", total);
#endif
            break; // exit the loop3, means to compare the next number
          }
      } // loop3
    } // loop2
  } // loop1
  
  printf("\n����%d��", total);
  
  return SUCCESS;
}

void InputPriceReceiptNo(char array[][9] , int count)
{
  int   loop;
  char  chtDigits[][3] = {"�@", "�G", "�T","�|","��","��","�C","�K","�E"};

  for (loop = 0; loop < count; loop++) {
    printf("�п�J��%s�Ӹ��X:", chtDigits[loop]);
    scanf("%s", array[loop]);
  }
}

