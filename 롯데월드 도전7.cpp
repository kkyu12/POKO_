#include <stdio.h>
#include <ctime>

int main()
{
	int type1,type2,count,typeCom,age,
		isExit,isDown,
		year,month,day;
	int totalPrice=0; int price=0;
	int index=0;
	int order[100][6]={0};//����,�־�,����,����,����,��� 
	
	const int BABY=15000,
		  	  ALL_1DAY_ADULT=59000,ALL_1DAY_TEEN=52000,ALL_1DAY_CHILD=47000,
			  ALL_AFT4_ADULT=48000,ALL_AFT4_TEEN=42000,ALL_AFT4_CHILD=36000,
			  PARK_1DAY_ADULT=56000,PARK_1DAY_TEEN=50000,PARK_1DAY_CHILD=46000,
			  PARK_AFT4_ADULT=45000,PARK_AFT4_TEEN=40000,PARK_AFT4_CHILD=35000;
	
	//����ð� �������� 
	time_t timer; struct tm* t; timer = time(NULL); t=localtime(&timer);
	do
	{
		totalPrice=0;
	do
	{
		//�̿�� ���� ���� 
		do{
			printf("�̿����  �������ּ���.\n");
			printf("1. �����̿�� : �Ե�����+�μӹڹ���\n");
			printf("2. ��ũ�̿�� : �Ե�����\n");
			scanf("%d",&type1);
			if (!(type1==1 || type1==2))
				printf("�߸� �����ϼ̽��ϴ�.\n");
		}while(!(type1==1 || type1==2)); 
		
		//�̿� �ð� ���� 
		do{
			printf("������ �����ϼ���.\n");
			printf("1. 1Day\n"); printf("2. After4\n");
			scanf("%d",&type2);
			if (!(type2==1 || type2==2))
				printf("�߸� �����ϼ̽��ϴ�.\n");
		}while(!(type2==1 || type2==2));
	
		//�����Է�+��� 
		printf("��������� �Է��ϼ���. (8�ڸ�)\n");
		scanf("%4d%2d%2d",&year,&month,&day);
		
		if (month>=t->tm_mon+2)
			age=(t->tm_year+1900)-year-1;
		else if (month==t->tm_mon+1){
			if (day>t->tm_mday)
				age=(t->tm_year+1900)-year-1;
			else
				age=(t->tm_year+1900)-year;
		}
		else
		age=(t->tm_year+1900)-year;
		
		//�����Է� 
		do{
			printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
			scanf("%d",&count); 
			if (count>10 || count<0)
				printf("�߸� �Է��ϼ̽��ϴ�.\n");
		}while(count>10 || count<0);
				
		//������ ���� 
		do{
			printf("�������� �����ϼ���.\n");
			printf("1. ���� (���� ���� �ڵ�ó��)\n");
			printf("2. �����\n");
			printf("3. ����������\n");
			printf("4. �ް��庴\n");
			printf("5. �ӻ��\n");
			printf("6. �ٵ���\n");
			scanf("%d",&typeCom);
			if (!(typeCom==1 || typeCom==2 || typeCom==3 || typeCom==4 || typeCom==5 || typeCom==6))
				printf("�߸� �Է��ϼ̽��ϴ�.\n");
		}while(!(typeCom>=1 && typeCom<=6));
		
		//Ÿ�Ժ� ���� �Է� 
		if(type1==1){
			if(type2==1){
				if (age>=19 && age<=64)
				price=price+ALL_1DAY_ADULT;
				if (age>=13 && age<=18)
				price=price+ALL_1DAY_TEEN;
				if ((age>=3 && age<=12) || age>=65)
				price=price+ALL_1DAY_CHILD;
				if (age<=2)
				price=price+BABY;
			}
			else if (type2==2){
				if (age>=19 && age<=64)
				price=price+ALL_AFT4_ADULT;
				if (age>=13 && age<=18)
				price=price+ALL_AFT4_TEEN;
				if ((age>=3 && age<=12) || age>=65)
				price=price+ALL_AFT4_CHILD;
				if (age<=2)
				price=price+BABY;
			}
		}
		if(type1==2){
			if(type2==1){
				if (age>=19 && age<=64)
				price=price+PARK_1DAY_ADULT;
				if (age>=13 && age<=18)
				price=price+PARK_1DAY_TEEN;
				if ((age>=3 && age<=12) || age>=65)
				price=price+PARK_1DAY_CHILD;
				if (age<=2)
				price=price+BABY;
			}
			else if (type2==2){
				if (age>=19 && age<=64)
				price=price+PARK_AFT4_ADULT;
				if (age>=13 && age<=18)
				price=price+PARK_AFT4_TEEN;
				if ((age>=3 && age<=12) || age>=65)
				price=price+PARK_AFT4_CHILD;
				if (age<=2)
				price=price+BABY;
			}
		}
		//��� ���� ��� 
		if (typeCom==2){
			printf("������� �� �������� ���� ��+����1��\n");
			price=price*0.5;
		}
		else if (typeCom==3){
			printf("������������ �� �������� ���� ��+����1��\n");
			price=price*0.5;
		}
		else if (typeCom==4){
			if (type1==1){
				printf("�ް��庴(�ǰ�,�ǹ��ҹ��,������ ����) �������� ���� ��+����1��\n");
				price=price*0.51; 
				}
			else {
				printf("�ް��庴 ���� �����̿�Ǹ� �̿� ���� �մϴ�.\n");
				break;
				}
		}
		else if (typeCom==5){
			if (type1==1){
				printf("���ڼ�ø �� �������� ���� �ӻ�� ����\n");
				price=price*0.5;
				}
			else {
				printf("�ӻ�� ���� �����̿�Ǹ� �̿� ���� �մϴ�.\n");
				break;
				}
		}
		else if (typeCom==6){
			if (type1==1){
				printf("�ٵ��� �ູī�� ȸ�� ���� ����(ī�忡 ���� ������ ����)\n");
				price=price*0.7;
				}
			else {
				printf("�ٵ��� �ູī�� ���� �����̿�Ǹ� �̿� ���� �մϴ�.\n");
				break;
				}
		}
		
		price=price*count;
		if (price%10 != 0)
			price=price-(price%10);
		 
		totalPrice=totalPrice+price;
		
		order[index][0]=type1;
		order[index][1]=type2;
		order[index][2]=age;
		order[index][3]=count;
		order[index][4]=price;
		order[index][5]=typeCom;
		
		printf("\n������ %d �� �Դϴ�.\n",price);
		price=0;
		printf("\n�� ������ %d �� �Դϴ�. �����մϴ�.\n\n",totalPrice);
		
		printf("��� ����(1.���ο� �ֹ�,2:���α׷� ����): ");
		scanf("%d",&isExit);
		index++;
		
	}while(isExit==1);
	
	printf("����       �־�    ����  ����      ���� ���\n");
	for (int i=0;i<index;i++){
		switch (order[i][0]){
			case 1:
				printf("�����̿�� ");
				break;
			case 2:
				printf("��ũ�̿�� ");
		}
		
		switch (order[i][1]){
			case 1:
				printf("%-7s","1DAY");
				break;
			case 2:
				printf("%-7s","After4");
				break;
		}
		
		printf("%3d�� ",order[i][2]);
		printf("%3d�� ",order[i][3]);
		printf("%7d�� ",order[i][4]);
		
		switch (order[i][5]){
			case 1:
				printf("�����׾���\n");
				break;
			case 2:
				printf("����� ���\n");
				break;
			case 3:
				printf("���������� ���\n");
				break;
			case 4:
				printf("�ް��庴 ���\n");
				break;
			case 5:
				printf("�ӻ�� ���\n");
				break;
			case 6:
				printf("�ٵ��� �ູī�� ���\n");
				break; 
				
		}
		
	}
	
	printf("���α׷��� �����Ͻðڽ��ϱ�? (1.�� 2.�ƴϿ�)");
	scanf("%d",&isDown);
	
	}while(isDown==2);
	return 0;
}
