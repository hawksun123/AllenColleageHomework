/*
  假設在某商店中購物，寫一程式讓使用者輸入三個應付款的金額及實際交給店員的金額(均為整
  數)，並輸出應找回最少的鈔票數與錢幣數，如果交給店員的金額少於應付金額，則印出 "金額不
  夠" 字串。同時依面額大小印出找回之錢幣數，若未使用到的錢幣則不必印出。舉例來說，我們
  買了 33 元（所應付款的金額）的東西，而交給店員的錢為 1000 元（實際交給店員的金額），店員
  應找回一張 500 元，四張 100 元，一個 50 元硬幣，一個 10 元硬幣，一個 5 元硬幣及二個 1 元硬
  幣（假設幣值只有 1000、500、100、50、10、5 與 1 元，且必須先找面額較大的鈔票或錢幣）。
  需使用者輸入部分，請先印出提示輸入文字訊息後再讓使用者輸入。
  程式執行輸出畫面如下:
  客人一
  應付金額:1000
  實際交付:100
  客人二
  應付金額:33
  實際交付:1000
  客人三
  應付金額:796
  實際交付:1000
  結果一
  金額不足
  結果二
  500 元 1
  100 元 4
  50 元 1
  10 元 1
  5 元 1
  1 元 2
  結果三
  100 元 2
  1 元 4
 
  說明: 最後一列輸出不換行。使用者需輸入部分:前為提示字，須完全一樣評分系統才會通
  過，:後為使用者輸入(評分系統測試資料可能會有不同)，結果部份則為使用者所輸入的數
  及程式計算判斷後所得到之結果。□表示空白。
*/

#include "c++common.h"

#define CLIENTS  3

int main(void)
{
  int   moneyShouldPay[CLIENTS];
  int   paidMoney[CLIENTS];
  int   change[CLIENTS];
  int   moneyUnit[] = {500, 100, 50, 10, 5, 1};
 
  int   loop, loop1;
 
  for (loop = 0; loop < CLIENTS ; loop++) {
    cout << "客人" << chtDigit[loop] << endl << "應付金額:";
    cin >> moneyShouldPay[loop];
    cout << "實際交付:";
    cin >> paidMoney[loop];
    change[loop] = paidMoney[loop] - moneyShouldPay[loop];
  }

  for (loop = 0; loop < CLIENTS ; loop++) {
    cout << "結果" << chtDigit[loop] << endl;
      if (change[loop] < 0) {
        cout << "金額不足" << endl;
        continue;
      }
      int remainMoney = change[loop];
      for (loop1 = 0; loop1 < sizeof(moneyUnit)/ sizeof(moneyUnit[0]) ; loop1++) {
        if (remainMoney / moneyUnit[loop1] != 0) {
          cout << moneyUnit[loop1] << " 元 " << remainMoney / moneyUnit[loop1] << endl;
        }
        remainMoney %= moneyUnit[loop1];
      }
  }
  return SUCCESS;
}
