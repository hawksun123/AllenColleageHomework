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
����: �̫�@�C��X������C�ϥΪ̻ݿ�J�����¦��r�����ܦr�A�������@�˵����t�Τ~�|�q
�L�A����Ʀr���ϥΪ̿�J(�����t�δ��ո�ƥi��|�����P)�A���G�����h���ϥΪ̩ҿ�J����
�ε{���p��P�_��ұo�줧���G�C����ܪťաC
*/
#include <stdio.h>

int main(void)
{
	int MoneyShouldPay[3];
	int PraticalMoney[3];
	int Charge[3];
	char Clients[][3] = {"�@", "�G", "�T"};
	
	int loop;
	
	for (loop = 0; loop < 3; loop++) {
		printf("�ȤH%s\n���I���B:", Clients[loop]);
		scanf("%d", &MoneyShouldPay[loop]);
		printf("��ڪ��B:");
		scanf("%d", &PraticalMoney[loop]);
		Charge[loop] = PraticalMoney[loop]-MoneyShouldPay[loop];
	}

	int loop2;
	int bill[] = {1000, 500, 100, 50, 10, 5, 1};
	
	for (loop = 0; loop < 3; loop++) {
		printf("���G%s\n", Clients[loop]);
		if (Charge[loop] < 0) {
			printf("���B����\n");
		}
		else {
			for (loop2 = 0; loop2 < 7; loop2++) {
				if (Charge[loop]/bill[loop2] != 0) {
					printf("%d��%d\n", bill[loop2], Charge[loop]/bill[loop2]);
				}			
				Charge[loop] = Charge[loop]%bill[loop2];
			}
		}
		
		
	}

	return 0;
}
