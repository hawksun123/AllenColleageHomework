/*
  一個數如果恰好等於它的因數之和，這個數就稱為 "完美數"（perfect number）。例如 6=1＋2＋3，
  因 1、2 與 3 都是 6 的因數，因而 6 是完美數。
  寫一程式，讓使用者可輸入三個整數 N (N 小於 2147483647)，程式則判斷使用者輸入的數是否
  為完美數，並印出結果。其中若是完美數，需由小到大印出其因數。
  需使用者輸入部分，請先印出提示輸入文字訊息後再讓使用者輸入。
  程式執行輸出畫面如下:
  請輸入第一個整數:496
  請輸入第二個整數:42596
  請輸入第三個整數:743596
  結果一:完美數□1□2□4□8□16□31□62□124□248
  結果二:不是完美數
  結果三:不是完美數
  說明: 最後一列輸出不換行。使用者需輸入部分:前提示字，須完全一樣評分系統才會通
  過，:後使用者輸入(評分系統測試資料可能會有不同)，結果部份則為使用者所輸入的數
  及程式計算判斷後所得到之結果。□表示空白。
*/
#include "c++common.h"

#define NUMBERS 3
#define MAX_INT32_VAL 2147483647

int main(void) {
  unsigned long long  tmpInt;
  int   numbers[NUMBERS];

  int   loop;
  for (loop = 0; loop < NUMBERS; loop++) {
    do {
      cout << "請輸入第" << chtDigit[loop] << "個整數:";
      cin >> tmpInt;
    } while (tmpInt >= MAX_INT32_VAL);
    numbers[loop] = tmpInt;
  }

  for (loop = 0; loop < NUMBERS; loop++) {
    cout << "結果" << chtDigit[loop] << ":";

    if (numbers[loop] <= 1) {
      cout << "不是完美數";
    } else {
      int loop2;
			int total = 0;
      for (loop2 = 1; loop2 < numbers[loop]; loop2++) {
        if (numbers[loop] % loop2 == 0) { // is it a factor of numbers[loop] ?
          total += loop2;
        }
      }
      if (total == numbers[loop]) {
        cout << "完美數";
        for (loop2 = 1; loop2 < numbers[loop]; loop2++) {
          if (numbers[loop] % loop2 == 0) {
            cout << " " << loop2;
          }
        }
      } else {
        cout << "不是完美數";
      }
    }
    if (loop != NUMBERS - 1) {
      cout << endl;
    }
  }

  return SUCCESS;
}

