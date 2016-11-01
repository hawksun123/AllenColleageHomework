#include <stdio.h>

int main(void)
{
	int a, b;
	double c, d;
	do {
		printf("請輸入通話分鐘數一:");
		scanf("%d", &a);
	} while (a<0);
	
	do {
		printf("請輸入通話分鐘數二:");
		scanf("%d", &b);
	} while (b<0);
	
	
	if (a>=0 && a<=600)
	  c=0.5*a;
	else if (a>600 && a<=1200)
		   c=600*0.5+(a-600)*0.45;
		else if (a>1200)
			   c = 600*0.5+600*0.45+(a-1200)*0.4;
	if (c>200 && c<=450)
	  c*=0.9;
	else if (c>450 && c<=750)
		   c*=0.8;
		else if (c>750)
			   c*=0.7;

	if (b>=0 && b<=600)
	  d=0.5*b;
	else if (b>600 && b<=1200)
		   d=600*0.5+(b-600)*0.45;
		else if (b>1200)
			   d = 600*0.5+600*0.45+(b-1200)*0.4;
	if (d>200 && d<=450)
	  d*=0.9;
	else if (d>450 && d<=750)
		   d*=0.8;
		else if (d>750)
			   d*=0.7;
	
	printf("通話費一:%d\n", (int) c);
	printf("通話費二:%d", (int) d);
	
	return 0;
}
