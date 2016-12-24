/*

請寫一程式，可以找出 n 個整數中第 i 個大的整數。(n 和 i 均小於等於 20) 
Note: Use C standard liberary qsort() to do the sort.
程式首先分別讓使用者輸入 i 跟 n，接著讓使用者輸入 n 個整數(個數會根據前面使用者輸入的 n
有所變動)。 程式則根據輸入的數中找到第 i 個大的數，並輸出結果。 測試資料總共會有兩組資料作測試。
 
需使用者輸入部分，請先印出提示輸入文字訊息後再讓使用者輸入。程式執行輸出畫面如下: 
 
測試一 
請輸入 i:4 
請輸入 n:6 
請輸入第 1 個整數:12 
請輸入第 2 個整數:27 
請輸入第 3 個整數:56 
請輸入第 4 個整數:34 
請輸入第 5 個整數:90 
請輸入第 6 個整數:78 
測試二 
請輸入 i:5 
請輸入 n:9 
請輸入第 1 個整數:27 
請輸入第 2 個整數:328 
請輸入第 3 個整數:96 
請輸入第 4 個整數:157 
請輸入第 5 個整數:51 
請輸入第 6 個整數:515 
請輸入第 7 個整數:7 請輸入第 8 個整數:83 
請輸入第 9 個整數:230 
結果一:34
結果二:96

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
    printf("測試%s:\n", chtDigit[loop]);
    do {
      printf("請輸入i:");
      scanf("%d", &i[loop]);
    } while (i[loop] < 1 || i[loop] > MAX_DIGIT);
    do {
      printf("請輸入n:");
      scanf("%d", &n[loop]);
    } while (n[loop] < i[loop] || n[loop] > MAX_DIGIT);
    for (loop2 = 0; loop2 < n[loop]; loop2++) {
      printf("請輸入第%d個整數:", loop2 + 1);
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
    printf("結果%s:", chtDigit[loop]);
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

