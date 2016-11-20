/*
  �ҿ� "Armstrong ��" �O���@�� k ��ƾ�ơA��U��Ʀr�� k �����`�M����Ӽƥ����C�Ҧp�G153
  �O�@�� 3 ��ơA�]�� 333 153 1 5 3 =++ �A�]�� 153 �O Armstrong �ơC
  �S�p 1634 �O�@�� 4 ��ơA�]�� 4444 1634 1 6 3 4 =+++ �A�]�� 153 �O Armstrong �ơC
  �g�@�{���A���ϥΪ̥i��J�T�Ӿ�� N (N �p�� 2147483647)�A�{���h�P�_�ϥΪ̿�J���ƬO�_
  �� Armstrong �ơA�æL�X���G�C�䤤�Y�O Armstrong �ơA�ݨ̧ǦL�X��U��Ʀr�� k ����ȡC
  �ݨϥΪ̿�J�����A�Х��L�X���ܿ�J��r�T����A���ϥΪ̿�J�C
  �{�������X�e���p�U:
  �п�J�Ĥ@�Ӿ��:153
  �п�J�ĤG�Ӿ��:42596
  �п�J�ĤT�Ӿ��:743596
  ���G�@:Armstrong �ơ�1��125��27
  ���G�G:���O Armstrong ��
  ���G�T:���O Armstrong ��
  ����: �̫�@�C��X������C����ܪťաC
*/
#include <stdio.h>
#include <math.h>

#define NUMBERS 3

int main(void)
{
	int numbers[NUMBERS];
  int tmpNum;
	char chinesenum[NUMBERS][3] = {"�@", "�G", "�T"};
	int loop;
	for (loop = 0; loop < NUMBERS; loop++) {
		do {
			printf("�п�J��%s�Ӿ��:", chinesenum[loop]);
			scanf("%d", &numbers[loop]);
		} while (numbers[loop] >= 2147483647);
	}
	
	for (loop = 0; loop < NUMBERS; loop++) { 
		printf("���G%s:", chinesenum[loop]); 
		//�D�X��� 
		int times = 0;
    tmpNum = numbers[loop];
		while (tmpNum > 0) {
			tmpNum /= 10;
			times++;
		}
		
		//�D���誺�`�X
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
			printf("Armstrong��");
			
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
			printf("���OArmstrong��");
		}
		
		if (loop != NUMBERS-1) {
			printf("\n");
		}
	} 
	
	return 0;
}
