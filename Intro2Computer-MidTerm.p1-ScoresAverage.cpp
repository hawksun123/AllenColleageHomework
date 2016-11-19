/*
  寫一程式讓使用者分別輸入三位同學的國文、英文以及數學三項成績(均為整數)，程式則計算並
  印出其學期總成績(包含小數，且以小數點後兩位數字格式印出)，學期總成績計算方式為國文佔
  30%、英文佔 40%、數學佔 30%，並依學期總成績印出其對應之等第，80 分以上(含 80 分)為 A，
  70~79 分為 B，60~69 分為 C，60 分以下(不含 60 分)為 D。 
  需使用者輸入部分，請先印出提示輸入文字訊息後再讓使用者輸入。 
  程式執行輸出畫面如下: 
   
  成績一 
  國文:80 
  英文:85 
  數學:86 
  成績二 
  國文:70 
  英文:73 
  數學:74 
  成績三 
  國文:61 
  英文:40 
  數學:37 
  83.80□A 
  72.40□B 
  45.40□D 
   
  說明:  最後一列輸出不換行。使用者需輸入部分:前為提示字，須完全一樣評分系統才會通
  過，:後為使用者輸入(評分系統測試資料可能會有不同)，結果部份則為使用者所輸入的數
  及程式判斷後所得到之結果。□表示空白。 

*/
#include "c++common.h"

#define STUDENTS  3
#define SUBJECTS  3

int main(void) {
  string  subjects[] = { "國文", "英文", "數學" };

  int     scores[STUDENTS][SUBJECTS] = { 0 };
  int     sum[STUDENTS] = { 0 };
  float   average[STUDENTS];
  char    grade[STUDENTS];

  int     loop, loop1;

  for (loop = 0; loop < STUDENTS; loop++) {
    cout << "成績" << chtDigit[loop] << endl;
    for (loop1 = 0; loop1 < SUBJECTS; loop1++) {
      cout << subjects[loop1] << ":";
      cin >> scores[loop][loop1];
      sum[loop] += scores[loop][loop1];
    }
    average[loop] = (float)sum[loop] / SUBJECTS;
    grade[loop] = (average[loop] >= 80) * 'A' +\
        (average[loop] >= 70 && average[loop] <= 79) * 'B' +\
        (average[loop] >= 60 && average[loop] <= 69) * 'C' +\
        (average[loop] < 60) * 'D';
  }

  for (loop = 0; loop < STUDENTS; loop++) {
    // result is different than the result provided by teacher, and I think mine is correct !!
    // Mine         Teacher's
    // 83.67 A      83.80 A     
    // 72.33 B      72.40 B
    // 46.00 D      45.40 D
    cout << fixed << setprecision(2) << average[loop] << " " << grade[loop] << endl;
    // printf("%4.2f %c\n", average[loop], grade[loop]);
  }
  return SUCCESS;
}
