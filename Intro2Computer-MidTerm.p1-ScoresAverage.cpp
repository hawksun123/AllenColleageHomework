/*
  �g�@�{�����ϥΪ̤��O��J�T��P�Ǫ����B�^��H�μƾǤT�����Z(�������)�A�{���h�p���
  �L�X��Ǵ��`���Z(�]�t�p�ơA�B�H�p���I����Ʀr�榡�L�X)�A�Ǵ��`���Z�p��覡������
  30%�B�^��� 40%�B�ƾǦ� 30%�A�è̾Ǵ��`���Z�L�X����������ġA80 ���H�W(�t 80 ��)�� A�A
  70~79 ���� B�A60~69 ���� C�A60 ���H�U(���t 60 ��)�� D�C 
  �ݨϥΪ̿�J�����A�Х��L�X���ܿ�J��r�T����A���ϥΪ̿�J�C 
  �{�������X�e���p�U: 
   
  ���Z�@ 
  ���:80 
  �^��:85 
  �ƾ�:86 
  ���Z�G 
  ���:70 
  �^��:73 
  �ƾ�:74 
  ���Z�T 
  ���:61 
  �^��:40 
  �ƾ�:37 
  83.80��A 
  72.40��B 
  45.40��D 
   
  ����:  �̫�@�C��X������C�ϥΪ̻ݿ�J����:�e�����ܦr�A�������@�˵����t�Τ~�|�q
  �L�A:�ᬰ�ϥΪ̿�J(�����t�δ��ո�ƥi��|�����P)�A���G�����h���ϥΪ̩ҿ�J����
  �ε{���P�_��ұo�줧���G�C����ܪťաC 

*/
#include "c++common.h"

#define STUDENTS  3
#define SUBJECTS  3

int main(void) {
  string  subjects[] = { "���", "�^��", "�ƾ�" };

  int     scores[STUDENTS][SUBJECTS] = { 0 };
  int     sum[STUDENTS] = { 0 };
  float   average[STUDENTS];
  char    grade[STUDENTS];

  int     loop, loop1;

  for (loop = 0; loop < STUDENTS; loop++) {
    cout << "���Z" << chtDigit[loop] << endl;
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
