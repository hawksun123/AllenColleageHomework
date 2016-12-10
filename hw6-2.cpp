/*

�мg�@�{���A�i�H��X��� n ��G�i��Ʀr��ܦ����X�{�s�� 1 ���̤j�ӼơC(���] n �p�󵥩�
255�A�G�i���ܦ�ƥ� 8 �Ӧ�ƪ��) 
�Ҧp 7 ���G�i���ܦ��� 00000111�A�]���s�� 1 ���̤j�ӼƬ� 3�C 
25 ���G�i���ܦ��� 00011001�A�]���s�� 1 ���̤j�ӼƬ� 2�C 
�{���������ϥΪ̿�J�@��� n�A�ھڿ�J���ƭp���G�i��Ʀr��ܦ����X�{�s�� 1 ���̤j��
�ơA�ÿ�X���G�C ���ո���`�@�|����ո�Ƨ@���աC
 
�ݨϥΪ̿�J�����A�Х��L�X���ܿ�J��r�T����A���ϥΪ̿�J�C 
�{�������X�e���p�U: 
 
���դ@ 
�п�J���:7 
���դG 
�п�J���:25 
���G�@:3 
���G�G:2 

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
		printf("����%s:\n", chtDigit[loop]);
		do {
			printf("�п�J���:");
			scanf("%d", &n[loop]);
		} while (n[loop] < 1 || n[loop] > MAX_NUM);
		toBinaryArray(n[loop], binaryArray[loop]);
	}

	for (loop = 0; loop < NUM_OF_TEST; loop++) {
		printf("���G%s:", chtDigit[loop]);
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

