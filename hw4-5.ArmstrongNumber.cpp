/*
  所謂 "Armstrong 數" 是指一個 k 位數整數，其各位數字之 k 次方總和等於該數本身。例如：153
  是一個 3 位數，因為 153 = 1^3 + 5^3 + 3^3，因此 153 是 Armstrong 數。
  又如 1634 是一個 4 位數，因為 1634 = 1^4 + 6^4 + 3^4 + 4^4，因此 153 是 Armstrong 數。
  寫一程式，讓使用者可輸入三個整數 N (N 小於 2147483647)，程式則判斷使用者輸入的數是否
  為 Armstrong 數，並印出結果。其中若是 Armstrong 數，需依序印出其各位數字的 k 次方值。
  需使用者輸入部分，請先印出提示輸入文字訊息後再讓使用者輸入。
  程式執行輸出畫面如下:
  請輸入第一個整數:153
  請輸入第二個整數:42596
  請輸入第三個整數:743596
  結果一:Armstrong 數□1□125□27
  結果二:不是 Armstrong 數
  結果三:不是 Armstrong 數
  說明: 最後一列輸出不換行。
 
  ***** stoi() is c++11 standard, so use "g++ -std=c++11" to compile ! *****
*/
#include "c++common.h"
#include <math.h>

#define DEBUG 0
#define NUMBERS 3
#define MAX_INT32_VAL 2147483647
#define MAX_DIGIT_LEN 10    // length of 2147483647

class Armstrong {
public:
  string  strNumber;
  bool    IsArmstrong();
};

bool Armstrong::IsArmstrong() {
  int power[MAX_DIGIT_LEN];
  int total = 0;
  int loop; 
  bool armstrongFlag;

  for (loop = 0; loop < strNumber.size(); loop++) {
    power[loop] = pow((strNumber[loop] - '0'), strNumber.size());
#if DEBUG
    if (!loop) {
      cout << endl;
    }
    cout << "power[" << loop << "] = " <<  power[loop] << endl;
#endif
    total += power[loop];
  }
#if DEBUG
  cout << "total = " <<  total << endl;
#endif

  armstrongFlag = (total == stoi(strNumber, nullptr, 10)); // nullptr: start from 1st char, 10: 10 base, 
  if (armstrongFlag) {
    cout << "Armstrong 數";
    for (loop = 0; loop < strNumber.size(); loop++) {
      cout << " " << power[loop];
    }
  } else {
    cout << "不是 Armstrong 數";
  }
  return armstrongFlag;
}

Armstrong armstrong[NUMBERS];

int main(void) {
  unsigned long long tmpInt;
  int   loop;

  for (loop = 0; loop < NUMBERS; loop++) {
    do {
      cout << "請輸入第" << chtDigit[loop] << "個整數:";
      cin >> tmpInt;
    } while (tmpInt >= MAX_INT32_VAL || tmpInt < 0);
    armstrong[loop].strNumber = to_string(tmpInt); // convert impInt to string
  }

  for (loop = 0; loop < NUMBERS; loop++) {
    cout << "結果" << chtDigit[loop] << ":";
    armstrong[loop].IsArmstrong();
    if (loop != NUMBERS - 1) {
      cout << endl;
    }
  }
  return SUCCESS;
}

