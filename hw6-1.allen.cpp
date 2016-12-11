#include <stdio.h>

#define NUMBERS 2
#define DEBUG			0
#define	MAX_DIGIT 20

#if DEBUG
void printArray(int N[]);
#endif

int main(void) {
	int i[NUMBERS], n[NUMBERS];
	char cNum[NUMBERS][3] = {"�@", "�G"};
	int loop, loop2, loop3;
	int N[NUMBERS][20] = {0};
	int tmp;
	for (loop = 0; loop < NUMBERS; loop++) {
		printf("����%s\n", cNum[loop]);
		do {
			printf("�п�Ji:");
			scanf("%d", &i[loop]);
		} while (i[loop] < 1 || i[loop] > MAX_DIGIT);
		do {
			printf("�п�Jn:");
			scanf("%d", &n[loop]);
		} while (n[loop] < i[loop] || n[loop] > MAX_DIGIT);
		for (loop2 = 0; loop2 < n[loop]; loop2++) {
			printf("�п�J��%d�Ӿ��:", loop2+1);
			scanf("%d", &N[loop][loop2]);
		}
	}
	for (loop = 0; loop < NUMBERS; loop++) {
		printf("���G%s:", cNum[loop]);
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
		
		#if DEBUG
			printf("After sorting: ");
			printArray(N[loop]);
		#endif
				
		printf("%d", N[loop][i[loop]-1]);

		if (loop != NUMBERS-1) {
			printf("\n");
		}
	}
	return 0;
}

#if DEBUG
void printArray(int N[]) {
	int	loop;
	for (loop = 0; loop < MAX_DIGIT; loop++) {
		printf("%d ", N[loop]);
	}
	printf("\n");
}
#endif


