/*
  ���]�b�Y�ө����ʪ��A�g�@�{�����ϥΪ̿�J�T�����I�ڪ����B�ι�ڥ浹���������B(������
  ��)�A�ÿ�X����^�̤֪��r���ƻP�����ơA�p�G�浹���������B�֩����I���B�A�h�L�X "���B��
  ��" �r��C�P�ɨ̭��B�j�p�L�X��^�������ơA�Y���ϥΨ쪺�����h�����L�X�C�|�Ҩӻ��A�ڭ�
  �R�F 33 ���]�����I�ڪ����B�^���F��A�ӥ浹���������� 1000 ���]��ڥ浹���������B�^�A����
  ����^�@�i 500 ���A�|�i 100 ���A�@�� 50 ���w���A�@�� 10 ���w���A�@�� 5 ���w���ΤG�� 1 ���w
  ���]���]���ȥu�� 1000�B500�B100�B50�B10�B5 �P 1 ���A�B�������䭱�B���j���r���ο����^�C
  �ݨϥΪ̿�J�����A�Х��L�X���ܿ�J��r�T����A���ϥΪ̿�J�C
  �{�������X�e���p�U:
  �ȤH�@
  ���I���B:1000
  ��ڥ�I:100
  �ȤH�G
  ���I���B:33
  ��ڥ�I:1000
  �ȤH�T
  ���I���B:796
  ��ڥ�I:1000
  ���G�@
  ���B����
  ���G�G
  500 �� 1
  100 �� 4
  50 �� 1
  10 �� 1
  5 �� 1
  1 �� 2
  ���G�T
  100 �� 2
  1 �� 4
 
  ����: �̫�@�C��X������C�ϥΪ̻ݿ�J����:�e�����ܦr�A�������@�˵����t�Τ~�|�q
  �L�A:�ᬰ�ϥΪ̿�J(�����t�δ��ո�ƥi��|�����P)�A���G�����h���ϥΪ̩ҿ�J����
  �ε{���p��P�_��ұo�줧���G�C����ܪťաC
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
    cout << "�ȤH" << chtDigit[loop] << endl << "���I���B:";
    cin >> moneyShouldPay[loop];
    cout << "��ڥ�I:";
    cin >> paidMoney[loop];
    change[loop] = paidMoney[loop] - moneyShouldPay[loop];
  }

  for (loop = 0; loop < CLIENTS ; loop++) {
    cout << "���G" << chtDigit[loop] << endl;
      if (change[loop] < 0) {
        cout << "���B����" << endl;
        continue;
      }
      int remainMoney = change[loop];
      for (loop1 = 0; loop1 < sizeof(moneyUnit)/ sizeof(moneyUnit[0]) ; loop1++) {
        if (remainMoney / moneyUnit[loop1] != 0) {
          cout << moneyUnit[loop1] << " �� " << remainMoney / moneyUnit[loop1] << endl;
        }
        remainMoney %= moneyUnit[loop1];
      }
  }
  return SUCCESS;
}
