#include <stdio.h>

int main()
{
	int type1,type2,typeCom,age,isExit;
	int year,month,day;
	int totalPrice=0;
	int price=0;
	const int baby=15000;
	const int all_1Day_Adult=59000,all_1Day_Teen=52000,all_1Day_Child=47000;
	const int all_Aft4_Adult=48000,all_Aft4_Teen=42000,all_Aft4_Child=36000;
	const int park_1Day_Adult=56000,park_1Day_Teen=50000,park_1Day_Child=46000;
	const int park_Aft4_Adult=45000,park_Aft4_Teen=40000,park_Aft4_Child=35000;
	
	for(;;){
	if (isExit==2)
		break;
	
	printf("�̿����  �������ּ���.\n");
	printf("1. �����̿�� : �Ե�����+�μӹڹ���\n");
	printf("2. ��ũ�̿�� : �Ե�����\n");
	scanf("%d",&type1);
	
	printf("������ �����ϼ���.\n");
	printf("1. 1Day\n"); printf("2. After4\n");
	scanf("%d",&type2);
	
	printf("��������� �Է��ϼ���.\n");
	scanf("%4d%2d%2d",&year,&month,&day);
	//���̰�� 
	if (month>=4)
		age=2022-year-1;
	else if (month==3){
		if (day>=16)
			age=2022-year-1;
		else
			age=2022-year;
	}
	else
	age=2022-year;
	
	printf("�������� �����ϼ���.\n");
	printf("1. ���� (���� ���� �ڵ�ó��)\n");
	printf("2. �����\n");
	printf("3. ����������\n");
	printf("4. �ް��庴\n");
	printf("5. �ӻ��\n");
	printf("6. �ٵ���\n");
	scanf("%d",&typeCom);
	//Ÿ�Ժ� ���� �Է� 
	if(type1==1){
		if(type2==1){
			if (age>=19 && age<=64)
			price=price+all_1Day_Adult;
			if (age>=13 && age<=18)
			price=price+all_1Day_Teen;
			if ((age>=3 && age<=12) || age>=65)
			price=price+all_1Day_Child;
			if (age<=2)
			price=price+baby;
		}
		else if (type2==2){
			if (age>=19 && age<=64)
			price=price+all_Aft4_Adult;
			if (age>=13 && age<=18)
			price=price+all_Aft4_Teen;
			if ((age>=3 && age<=12) || age>=65)
			price=price+all_Aft4_Child;
			if (age<=2)
			price=price+baby;
		}
	}
	if(type1==2){
		if(type2==1){
			if (age>=19 && age<=64)
			price=price+park_1Day_Adult;
			if (age>=13 && age<=18)
			price=price+park_1Day_Teen;
			if ((age>=3 && age<=12) || age>=65)
			price=price+park_1Day_Child;
			if (age<=2)
			price=price+baby;
		}
		else if (type2==2){
			if (age>=19 && age<=64)
			price=price+park_Aft4_Adult;
			if (age>=13 && age<=18)
			price=price+park_Aft4_Teen;
			if ((age>=3 && age<=12) || age>=65)
			price=price+park_Aft4_Child;
			if (age<=2)
			price=price+baby;
		}
	}
	
	switch(typeCom){
		case 2:
			price=price*0.5;
			break;
		case 3:
			price=price*0.5;
			break;
		case 4:
			price=price*0.51;
			break;
		case 5:
			price=price*0.5;
			break;
		case 6:
			price=price*0.3;
			break;
	}

	totalPrice=totalPrice+price;
	
	printf("%d %d %d�� %d�� %d�� %d��� %d��\n",type1,type2,year,month,day,typeCom,age);
	
	printf("���� ������ %d �� �Դϴ�.\n",price);

	printf("�� ������ %d �� �Դϴ�.\n�����մϴ�.\n",totalPrice);
	printf("��� ����(1.���ο� �ֹ�,2:���α׷� ����): ");
	scanf("%d",isExit);
	}
	return 0;
}
