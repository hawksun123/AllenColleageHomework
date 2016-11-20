/*
  所謂 "Armstrong 數" 是指一個 k 位數整數，其各位數字之 k 次方總和等於該數本身。例如：153
  是一個 3 位數，因為 333 153 1 5 3 =++ ，因此 153 是 Armstrong 數。
  又如 1634 是一個 4 位數，因為 4444 1634 1 6 3 4 =+++ ，因此 153 是 Armstrong 數。
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
  說明: 最後一列輸出不換行。□表示空白。
*/
#include <stdio.h>
#include <math.h>

#define NUMBERS 3

int main(void)
{
	int numbers[NUMBERS];
  int tmpNum;
	char chinesenum[NUMBERS][3] = {"一", "二", "三"};
	int loop;
	for (loop = 0; loop < NUMBERS; loop++) {
		do {
			printf("請輸入第%s個整數:", chinesenum[loop]);
			scanf("%d", &numbers[loop]);
		} while (numbers[loop] >= 2147483647);
	}
	
	for (loop = 0; loop < NUMBERS; loop++) { 
		printf("結果%s:", chinesenum[loop]); 
		//求幾位數 
		int times = 0;
    tmpNum = numbers[loop];
		while (tmpNum > 0) {
			tmpNum /= 10;
			times++;
		}
		
		//求次方的總合
		int total = 0;
		int number;

    tmpNum =  numbers[loop];
		while (tmpNum > 0) {
			number = tmpNum%10;
			total += pow(number, times);
			tmpNum /= 10;
		}
		// Is it a Armstrong number ?
		if (total == numbers[loop]) {
			printf("Armstrong數");
			
			int loop2;
			int pownum[times];
			for (loop2 = 0; loop2 < times; loop2++) {
				number = numbers[loop]%10;
				pownum[loop2] = pow(number, times);
				numbers[loop] /= 10;
			}
			
			tmpNum = times;
			while (tmpNum-- >= 0) {
				printf(" %d", pownum[tmpNum]);
			}
		}
		else {
			printf("不是Armstrong數");
		}
		
		if (loop != NUMBERS-1) {
			printf("\n");
		}
	} 
	
	return 0;
}
