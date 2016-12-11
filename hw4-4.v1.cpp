/*
  �@�ӼƦp�G��n���󥦪��]�Ƥ��M�A�o�ӼƴN�٬� "������"�]perfect number�^�C�Ҧp 6=1��2��3�A
  �] 1�B2 �P 3 ���O 6 ���]�ơA�]�� 6 �O�����ơC
  �g�@�{���A���ϥΪ̥i��J�T�Ӿ�� N (N �p�� 2147483647)�A�{���h�P�_�ϥΪ̿�J���ƬO�_
  �������ơA�æL�X���G�C�䤤�Y�O�����ơA�ݥѤp��j�L�X��]�ơC
  �ݨϥΪ̿�J�����A�Х��L�X���ܿ�J��r�T����A���ϥΪ̿�J�C
  �{�������X�e���p�U:
  �п�J�Ĥ@�Ӿ��:496
  �п�J�ĤG�Ӿ��:42596
  �п�J�ĤT�Ӿ��:743596
  ���G�@:�����ơ�1��2��4��8��16��31��62��124��248
  ���G�G:���O������
  ���G�T:���O������
  ����: �̫�@�C��X������C�ϥΪ̻ݿ�J����:�e���ܦr�A�������@�˵����t�Τ~�|�q
  �L�A:��ϥΪ̿�J(�����t�δ��ո�ƥi��|�����P)�A���G�����h���ϥΪ̩ҿ�J����
  �ε{���p��P�_��ұo�줧���G�C����ܪťաC
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
      cout << "�п�J��" << chtDigit[loop] << "�Ӿ��:";
      cin >> tmpInt;
    } while (tmpInt >= MAX_INT32_VAL);
    numbers[loop] = tmpInt;
  }

  for (loop = 0; loop < NUMBERS; loop++) {
    cout << "���G" << chtDigit[loop] << ":";

    if (numbers[loop] <= 1) {
      cout << "���O������";
    } else {
      int loop2;
			int total = 0;
      for (loop2 = 1; loop2 < numbers[loop]; loop2++) {
        if (numbers[loop] % loop2 == 0) { // is it a factor of numbers[loop] ?
          total += loop2;
        }
      }
      if (total == numbers[loop]) {
        cout << "������";
        for (loop2 = 1; loop2 < numbers[loop]; loop2++) {
          if (numbers[loop] % loop2 == 0) {
            cout << " " << loop2;
          }
        }
      } else {
        cout << "���O������";
      }
    }
    if (loop != NUMBERS - 1) {
      cout << endl;
    }
  }

  return SUCCESS;
}

