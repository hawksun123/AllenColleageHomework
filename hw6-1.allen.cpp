#include <stdio.h>

#define NUMBERS 2
int main(void) {
	int i[NUMBERS], n[NUMBERS];
	char cNum[NUMBERS][3] = {"一", "二"};
	int loop, loop2, loop3;
	int N[NUMBERS][20];
	int tmp;
	for (loop = 0; loop < NUMBERS; loop++) {
		printf("測試%s\n", cNum[loop]);
		do {
			printf("請輸入i:");
			scanf("%d", &i[loop]);
		} while (i[loop] < 1 || i[loop] > 20);
		do {
			printf("請輸入n:");
			scanf("%d", &n[loop]);
		} while (n[loop] < i[loop] || n[loop] > 20);
		for (loop2 = 0; loop2 < n[loop]; loop2++) {
			printf("請輸入第%d個整數:", loop2+1);
			scanf("%d", &N[loop][loop2]);
		}
	}
	for (loop = 0; loop < NUMBERS; loop++) {
		printf("結果%s:", cNum[loop]);
		loop3 = 0;
		
		if (n[loop] > 1) {
			while (loop3 < n[loop] - 1) {
				loop2 = 0;
				while (loop2 < n[loop]-1) {
					if (N[loop][loop2] < N[loop][loop2+1]) {
						tmp = N[loop][loop2];
						N[loop][loop2] = N[loop][loop2+1];
						N[loop][loop2+1] = tmp;
					}
					loop2++;
				}
				loop3++;
			}
		}
		
		printf("%d", N[loop][i[loop]-1]);

		if (loop != NUMBERS-1) {
			printf("\n");
		}
	}
	return 0;
}
