/*

請寫一程式，可以找出整數 n 其二進位數字表示式中出現連續 1 的最大個數。(假設 n 小於等於
255，二進位表示位數用 8 個位數表示) 
例如 7 的二進位表示式為 00000111，因此連續 1 的最大個數為 3。 
25 的二進位表示式為 00011001，因此連續 1 的最大個數為 2。 
程式首先讓使用者輸入一整數 n，根據輸入的數計算其二進位數字表示式中出現連續 1 的最大個
數，並輸出結果。 測試資料總共會有兩組資料作測試。
 
需使用者輸入部分，請先印出提示輸入文字訊息後再讓使用者輸入。 
程式執行輸出畫面如下: 
 
測試一 
請輸入整數:7 
測試二 
請輸入整數:25 
結果一:3 
結果二:2 

*/
#include "c_common.h"

#define NUM_OF_TEST 		2
#define MAX_NUM				255
#define BINARY_WIDTH		8
#define DEBUG						1

// function declaration
int 	MaxContinousOneInBinary(int binaryArray[]);
void	toBinaryArray(int n, int binaryArray[]);

int main(void) {
	int n[NUM_OF_TEST];
	int loop;
	int	binaryArray[NUM_OF_TEST][BINARY_WIDTH] = { 0 };

	for (loop = 0; loop < NUM_OF_TEST; loop++) {
		printf("測試%s:\n", chtDigit[loop]);
		do {
			printf("請輸入整數:");
			scanf("%d", &n[loop]);
		} while (n[loop] < 1 || n[loop] > MAX_NUM);
		toBinaryArray(n[loop], binaryArray[loop]);
	}

	for (loop = 0; loop < NUM_OF_TEST; loop++) {
		printf("結果%s:", chtDigit[loop]);
		printf("%d", MaxContinousOneInBinary(binaryArray[loop]));
		if (loop != NUM_OF_TEST - 1) {
			printf("\n");
		}
	}
	return SUCCESS;
}
/*

	Count the max number of continous one in a number in its binary format

*/
int MaxContinousOneInBinary(int binaryArray[]) {
	int	numOfContinousOne = 0;
	int	maxNumOfContinousOne = 0;
	int	loop;

	for (loop = 0; loop < BINARY_WIDTH; loop++) {
		if (binaryArray[loop]) {
			numOfContinousOne++;
		} else {
			if (maxNumOfContinousOne < numOfContinousOne) {
				maxNumOfContinousOne = numOfContinousOne;
				numOfContinousOne = 0;
			}
		}
	}
	if (0 == maxNumOfContinousOne) {
		maxNumOfContinousOne = numOfContinousOne;
	}
	return	maxNumOfContinousOne;
}

/*
	Convert the input number n to a binary array binaryArray[]
*/
void toBinaryArray(int n, int binaryArray[]) {
	int	loop;
	int remainder;
	int	counter = 0;

#if DEBUG
	printf("n = %d\n", n);
#endif
	while (n > 0) {
		remainder = n % 2;
		binaryArray[BINARY_WIDTH - ++counter] = remainder;
		n>>=1;
	}

#if DEBUG
	for	(loop = 0; loop < BINARY_WIDTH; loop++) {
		printf("%d", binaryArray[loop]);
	}
	printf("b\n");
#endif
}

