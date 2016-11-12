/*
假設在某商店中購物，寫一程式讓使用者輸入三個應付款的金額及實際交給店員的金額(均為整
數)，並輸出應找回最少的鈔票數與錢幣數，如果交給店員的金額少於應付金額，則印出 "金額不
夠" 字串。同時依面額大小印出找回之錢幣數，若未使用到的錢幣則不必印出。舉例來說，我們
買了 33 元（所應付款的金額）的東西，而交給店員的錢為 1000 元（實際交給店員的金額），店員
應找回一張 500 元，四張 100 元，一個 50 元硬幣，一個 10 元硬幣，一個 5 元硬幣及二個 1 元硬
幣（假設幣值只有 1000、500、100、50、10、5 與 1 元，且必須先找面額較大的鈔票或錢幣）。
需使用者輸入部分，請先印出提示輸入文字訊息後再讓使用者輸入。
程式執行輸出畫面如下:
客人一
應付金額:1000
實際交付:100
客人二
應付金額:33
實際交付:1000
客人三
應付金額:796
實際交付:1000
結果一
金額不足
結果二
500 元 1
100 元 4
50 元 1
10 元 1
5 元 1
1 元 2
結果三
100 元 2
1 元 4
說明: 最後一列輸出不換行。使用者需輸入部分黑色文字為提示字，須完全一樣評分系統才會通
過，紅色數字為使用者輸入(評分系統測試資料可能會有不同)，結果部份則為使用者所輸入的數
及程式計算判斷後所得到之結果。□表示空白。
*/
#include <stdio.h>

int main(void)
{
	int MoneyShouldPay[3];
	int PraticalMoney[3];
	int Charge[3];
	char Clients[][3] = {"一", "二", "三"};
	
	int loop;
	
	for (loop = 0; loop < 3; loop++) {
		printf("客人%s\n應付金額:", Clients[loop]);
		scanf("%d", &MoneyShouldPay[loop]);
		printf("實際金額:");
		scanf("%d", &PraticalMoney[loop]);
		Charge[loop] = PraticalMoney[loop]-MoneyShouldPay[loop];
	}

	int loop2;
	int bill[] = {1000, 500, 100, 50, 10, 5, 1};
	
	for (loop = 0; loop < 3; loop++) {
		printf("結果%s\n", Clients[loop]);
		if (Charge[loop] < 0) {
			printf("金額不足\n");
		}
		else {
			for (loop2 = 0; loop2 < 7; loop2++) {
				if (Charge[loop]/bill[loop2] != 0) {
					printf("%d元%d\n", bill[loop2], Charge[loop]/bill[loop2]);
				}			
				Charge[loop] = Charge[loop]%bill[loop2];
			}
		}
		
		
	}

	return 0;
}
