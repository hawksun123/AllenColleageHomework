#include <stdio.h>

int main(void)
{
  int a, b, c;
  
  /*�T���Τ@���P�_*/
  printf("�T���Τ@\n�п�J�Ĥ@�����:");
  scanf("%d", &a);
  printf("�п�J�ĤG�����:");
  scanf("%d", &b);
  printf("�п�J�ĤT�����:");
  scanf("%d", &c);

  if (a+b<c || b+c<a || c+a<b)
    printf("���O�T����\n");
  else if (a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b)
       printf("�����T����\n");
    else if (a*a+b*b<c*c || b*b+c*c<a*a || c*c+a*a<b*b)
         printf("�w���T����\n");
      else if ((a*a+b*b>c*c && b*b+c*c>a*a) || (b*b+c*c>a*a && c*c+a*a>b*b) || (c*c+a*a>b*b && a*a+b*b>c*c))
           printf("�U���T����\n");				   


  /*�T���ΤG���P�_*/

  printf("�T���ΤG\n�п�J�Ĥ@�����:");
  scanf("%d", &a);
  printf("�п�J�ĤG�����:");
  scanf("%d", &b);
  printf("�п�J�ĤT�����:");
  scanf("%d", &c);

  if (a+b<c || b+c<a || c+a<b)
    printf("���O�T����\n");
  else if (a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b)
       printf("�����T����\n");
    else if (a*a+b*b<c*c || b*b+c*c<a*a || c*c+a*a<b*b)
         printf("�w���T����\n");
      else if ((a*a+b*b>c*c && b*b+c*c>a*a) || (b*b+c*c>a*a && c*c+a*a>b*b) || (c*c+a*a>b*b && a*a+b*b>c*c))
           printf("�U���T����\n");

  /*�T���ΤT���P�_*/
  printf("�T���ΤT\n�п�J�Ĥ@�����:");
  scanf("%d", &a);
  printf("�п�J�ĤG�����:");
  scanf("%d", &b);
  printf("�п�J�ĤT�����:");
  scanf("%d", &c);

  if (a+b<c || b+c<a || c+a<b)
    printf("���O�T����\n");
  else if (a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b)
       printf("�����T����\n");
    else if (a*a+b*b<c*c || b*b+c*c<a*a || c*c+a*a<b*b)
         printf("�w���T����\n");
      else if ((a*a+b*b>c*c && b*b+c*c>a*a) || (b*b+c*c>a*a && c*c+a*a>b*b) || (c*c+a*a>b*b && a*a+b*b>c*c))
           printf("�U���T����\n");

  /*�T���Υ|���P�_*/
  printf("�T���Υ|\n�п�J�Ĥ@�����:");
  scanf("%d", &a);
  printf("�п�J�ĤG�����:");
  scanf("%d", &b);
  printf("�п�J�ĤT�����:");
  scanf("%d", &c);

  if (a+b<c || b+c<a || c+a<b)
    printf("���O�T����");
  else if (a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b)
       printf("�����T����");
    else if (a*a+b*b<c*c || b*b+c*c<a*a || c*c+a*a<b*b)
         printf("�w���T����");
      else if ((a*a+b*b>c*c && b*b+c*c>a*a) || (b*b+c*c>a*a && c*c+a*a>b*b) || (c*c+a*a>b*b && a*a+b*b>c*c))
           printf("�U���T����");
  
  return 0;
}
