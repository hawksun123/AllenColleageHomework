#include <stdio.h>

int main(void)
{
	int a, b, c, d, e, f, g, h ,i, j, k, l;
	
	printf("三角形一\n請輸入第一個邊長:");
	scanf("%d", &a);
	printf("請輸入第二個邊長:");
	scanf("%d", &b);
	printf("請輸入第三個邊長:");
	scanf("%d", &c);
	
	printf("三角形二\n請輸入第一個邊長:");
	scanf("%d", &d);	
	printf("請輸入第二個邊長:");
	scanf("%d", &e);
	printf("請輸入第三個邊長:");
	scanf("%d", &f);
	
	printf("三角形三\n請輸入第一個邊長:");
	scanf("%d", &g);
	printf("請輸入第二個邊長:");
	scanf("%d", &h);
	printf("請輸入第三個邊長:");
	scanf("%d", &i);
	
	printf("三角形四\n請輸入第一個邊長:");
	scanf("%d", &j);
	printf("請輸入第二個邊長:");
	scanf("%d", &k);
	printf("請輸入第三個邊長:");
	scanf("%d", &l);
	/*三角形一的判斷*/
	if (a+b<c || b+c<a || c+a<b)
	  printf("不是三角形\n");
	else if (a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b)
		   printf("直角三角形\n");
		else if (a*a+b*b<c*c || b*b+c*c<a*a || c*c+a*a<b*b)
			   printf("鈍角三角形\n");
			else if ((a*a+b*b>c*c && b*b+c*c>a*a) || (b*b+c*c>a*a && c*c+a*a>b*b) || (c*c+a*a>b*b && a*a+b*b>c*c))
				   printf("銳角三角形\n");				   
	/*三角形二的判斷*/
	a=d;
	b=e;
	c=f;
	if (a+b<c || b+c<a || c+a<b)
	  printf("不是三角形\n");
	else if (a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b)
		   printf("直角三角形\n");
		else if (a*a+b*b<c*c || b*b+c*c<a*a || c*c+a*a<b*b)
			   printf("鈍角三角形\n");
			else if ((a*a+b*b>c*c && b*b+c*c>a*a) || (b*b+c*c>a*a && c*c+a*a>b*b) || (c*c+a*a>b*b && a*a+b*b>c*c))
				   printf("銳角三角形\n");
	/*三角形三的判斷*/
	a=g;
	b=h;
	c=i;
	if (a+b<c || b+c<a || c+a<b)
	  printf("不是三角形\n");
	else if (a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b)
		   printf("直角三角形\n");
		else if (a*a+b*b<c*c || b*b+c*c<a*a || c*c+a*a<b*b)
			   printf("鈍角三角形\n");
			else if ((a*a+b*b>c*c && b*b+c*c>a*a) || (b*b+c*c>a*a && c*c+a*a>b*b) || (c*c+a*a>b*b && a*a+b*b>c*c))
				   printf("銳角三角形\n");
	/*三角形四的判斷*/
	a=j;
	b=k;
	c=l;
	if (a+b<c || b+c<a || c+a<b)
	  printf("不是三角形");
	else if (a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b)
		   printf("直角三角形");
		else if (a*a+b*b<c*c || b*b+c*c<a*a || c*c+a*a<b*b)
			   printf("鈍角三角形");
			else if ((a*a+b*b>c*c && b*b+c*c>a*a) || (b*b+c*c>a*a && c*c+a*a>b*b) || (c*c+a*a>b*b && a*a+b*b>c*c))
				   printf("銳角三角形");
	
	return 0;
}
