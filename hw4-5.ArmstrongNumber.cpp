/*
  �ҿ� "Armstrong ��" �O���@�� k ��ƾ�ơA��U��Ʀr�� k �����`�M����Ӽƥ����C�Ҧp�G153
  �O�@�� 3 ��ơA�]�� 153 = 1^3 + 5^3 + 3^3�A�]�� 153 �O Armstrong �ơC
  �S�p 1634 �O�@�� 4 ��ơA�]�� 1634 = 1^4 + 6^4 + 3^4 + 4^4�A�]�� 153 �O Armstrong �ơC
  �g�@�{���A���ϥΪ̥i��J�T�Ӿ�� N (N �p�� 2147483647)�A�{���h�P�_�ϥΪ̿�J���ƬO�_
  �� Armstrong �ơA�æL�X���G�C�䤤�Y�O Armstrong �ơA�ݨ̧ǦL�X��U��Ʀr�� k ����ȡC
  �ݨϥΪ̿�J�����A�Х��L�X���ܿ�J��r�T����A���ϥΪ̿�J�C
  �{�������X�e���p�U:
  �п�J�Ĥ@�Ӿ��:153
  �п�J�ĤG�Ӿ��:42596
  �п�J�ĤT�Ӿ��:743596
  ���G�@:Armstrong �ơ�1��125��27
  ���G�G:���O Armstrong ��
  ���G�T:���O Armstrong ��
  ����: �̫�@�C��X������C
 
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
    cout << "Armstrong ��";
    for (loop = 0; loop < strNumber.size(); loop++) {
      cout << " " << power[loop];
    }
  } else {
    cout << "���O Armstrong ��";
  }
  return armstrongFlag;
}

Armstrong armstrong[NUMBERS];

int main(void) {
  unsigned long long tmpInt;
  int   loop;

  for (loop = 0; loop < NUMBERS; loop++) {
    do {
      cout << "�п�J��" << chtDigit[loop] << "�Ӿ��:";
      cin >> tmpInt;
    } while (tmpInt >= MAX_INT32_VAL || tmpInt < 0);
    armstrong[loop].strNumber = to_string(tmpInt); // convert impInt to string
  }

  for (loop = 0; loop < NUMBERS; loop++) {
    cout << "���G" << chtDigit[loop] << ":";
    armstrong[loop].IsArmstrong();
    if (loop != NUMBERS - 1) {
      cout << endl;
    }
  }
  return SUCCESS;
}

