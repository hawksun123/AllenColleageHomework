/*

�мg�@�{���A�i�H��X n �Ӿ�Ƥ��� i �Ӥj����ơC(n �M i ���p�󵥩� 20) 
Note: Use C standard liberary qsort() to do the sort.
�{���������O���ϥΪ̿�J i �� n�A�������ϥΪ̿�J n �Ӿ��(�ӼƷ|�ھګe���ϥΪ̿�J�� n
�����ܰ�)�C �{���h�ھڿ�J���Ƥ����� i �Ӥj���ơA�ÿ�X���G�C ���ո���`�@�|����ո�Ƨ@���աC
 
�ݨϥΪ̿�J�����A�Х��L�X���ܿ�J��r�T����A���ϥΪ̿�J�C�{�������X�e���p�U: 
 
���դ@ 
�п�J i:4 
�п�J n:6 
�п�J�� 1 �Ӿ��:12 
�п�J�� 2 �Ӿ��:27 
�п�J�� 3 �Ӿ��:56 
�п�J�� 4 �Ӿ��:34 
�п�J�� 5 �Ӿ��:90 
�п�J�� 6 �Ӿ��:78 
���դG 
�п�J i:5 
�п�J n:9 
�п�J�� 1 �Ӿ��:27 
�п�J�� 2 �Ӿ��:328 
�п�J�� 3 �Ӿ��:96 
�п�J�� 4 �Ӿ��:157 
�п�J�� 5 �Ӿ��:51 
�п�J�� 6 �Ӿ��:515 
�п�J�� 7 �Ӿ��:7 �п�J�� 8 �Ӿ��:83 
�п�J�� 9 �Ӿ��:230 
���G�@:34
���G�G:96

*/
#include "c_common.h"

#define NUM_OF_TEST 	2
#define MAX_DIGIT 20
#define HSDEBUG			1

// function declaration
int cmpFunc (const void * a, const void * b);
#if HSDEBUG
void printArray(int N[]);
#endif

int main(void) {
  int i[NUM_OF_TEST], n[NUM_OF_TEST];
  int N[NUM_OF_TEST][MAX_DIGIT] = { 0 };

  int loop, loop2;
  for (loop = 0; loop < NUM_OF_TEST; loop++) {
    printf("����%s:\n", chtDigit[loop]);
    do {
      printf("�п�Ji:");
      scanf("%d", &i[loop]);
    } while (i[loop] < 1 || i[loop] > MAX_DIGIT);
    do {
      printf("�п�Jn:");
      scanf("%d", &n[loop]);
    } while (n[loop] < i[loop] || n[loop] > MAX_DIGIT);
    for (loop2 = 0; loop2 < n[loop]; loop2++) {
      printf("�п�J��%d�Ӿ��:", loop2 + 1);
      scanf("%d", &N[loop][loop2]);
    }
#if HSDEBUG
  printf("Before sorting: ");
  printArray(N[loop]);
#endif
    qsort(N[loop], n[loop], sizeof(int), cmpFunc);
#if HSDEBUG
  printf("After sorting: ");
  printArray(N[loop]);
#endif
  }

  for (loop = 0; loop < NUM_OF_TEST; loop++) {
    printf("���G%s:", chtDigit[loop]);
    printf("%d", N[loop][i[loop] - 1]);
    if (loop != NUM_OF_TEST - 1) {
      printf("\n");
    }
  }
  return SUCCESS;
}

void printArray(int N[]) {
  int	loop;
  for (loop = 0; loop < MAX_DIGIT; loop++) {
    printf("%d ", N[loop]);
  }
  printf("\n");
}

/*
  Tell qsort() to do the decending sort
*/
int cmpFunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

