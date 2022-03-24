#include <stdio.h>
#include <ctime>

	int type1,type2,count,typeCom,age,ageType,
		isExit,isDown,
		year,month,day;
	int totalPrice=0, price=0;
	int index=0;
	int order[100][6]={0};//����,�־�,����,����,����,���
	const int MIN_CHILD=3,MAX_CHILD=12, MIN_TEEN=13,MAX_TEEN=18, MIN_ADULT=19,MAX_ADULT=64;
	const int BABY=15000,
		  	  ALL_1DAY_ADULT=59000,ALL_1DAY_TEEN=52000,ALL_1DAY_CHILD=47000,
			  ALL_AFT4_ADULT=48000,ALL_AFT4_TEEN=42000,ALL_AFT4_CHILD=36000,
			  PARK_1DAY_ADULT=56000,PARK_1DAY_TEEN=50000,PARK_1DAY_CHILD=46000,
			  PARK_AFT4_ADULT=45000,PARK_AFT4_TEEN=40000,PARK_AFT4_CHILD=35000;
	const float DISABLE_DC_RATE=0.5, NATIONAL_DC_RATE=0.5,SOLDIER_DC_RATE=0.49,
				PREGNANT_DC_RATE=0.5, MULTICHILD_DC_RATE=0.3;
	const int MAX_COUNT=10, MIN_COUNT=1;
	
void errorMessage() {
	printf("%s","�߸� �����ϼ̽��ϴ�.\n\n");
}

void selectTicket() {
	do{ //�̿�� ���� ����
		printf("�̿����  �������ּ���.\n");
		printf("1. �����̿�� : �Ե�����+�μӹڹ���\n");
		printf("2. ��ũ�̿�� : �Ե�����\n");
		scanf("%d",&type1);
		if (!(type1==1 || type1==2))
			errorMessage();
	}while(!(type1==1 || type1==2));
}

void selectTime() {
	do{
		printf("������ �����ϼ���.\n");
		printf("1. 1Day\n"); printf("2. After4\n");
		scanf("%d",&type2);
		if (!(type2==1 || type2==2))
			errorMessage();
	}while(!(type2==1 || type2==2));
}

void inputBirth() {
	printf("��������� �Է��ϼ���. (8�ڸ�)\n");
	scanf("%4d%2d%2d",&year,&month,&day);
}

void ageCal() {
	time_t timer; struct tm* t; timer = time(NULL); t=localtime(&timer);
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
}

void inputAgeType() {
	if (age>MAX_ADULT)
		ageType=1;	//1.���� 
	if (age>=MIN_ADULT && age<=MAX_ADULT)
		ageType=2;	//2.���� 
	if (age>=MIN_TEEN && age<=MAX_TEEN)
		ageType=3;	//3.û�ҳ� 
	if (age>=MIN_CHILD && age<=MAX_CHILD)
		ageType=4;	//4.��� 
	if (age<MIN_CHILD)
		ageType=5;	//5.���� 
}

void inputCount() {
	do{
		printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
		scanf("%d",&count); 
		if (count>MAX_COUNT || count<MIN_COUNT)
			errorMessage();
	}while(count>MAX_COUNT || count<MIN_COUNT);
}

void inputFavor() {
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
			errorMessage();
	}while(!(typeCom>=1 && typeCom<=6));
}

void calPrice() {
	if(type1==1){
			if(type2==1){
				if (age>=MIN_ADULT && age<=MAX_ADULT)
					price=price+ALL_1DAY_ADULT;
				if (age>=MIN_TEEN && age<=MAX_TEEN)
					price=price+ALL_1DAY_TEEN;
				if ((age>=MIN_CHILD && age<=MAX_CHILD) || age>MAX_ADULT)
					price=price+ALL_1DAY_CHILD;
				if (age<MIN_CHILD)
					price=price+BABY;
			}
			else if (type2==2){
				if (age>=MIN_ADULT && age<=MAX_ADULT)
					price=price+ALL_AFT4_ADULT;
				if (age>=MIN_TEEN && age<=MAX_TEEN)
					price=price+ALL_AFT4_TEEN;
				if ((age>=MIN_CHILD && age<=MAX_CHILD) || age>MAX_ADULT)
					price=price+ALL_AFT4_CHILD;
				if (age<MIN_CHILD)
					price=price+BABY;
			}
		}
		if(type1==2){
			if(type2==1){
				if (age>=MIN_ADULT && age<=MAX_ADULT)
					price=price+PARK_1DAY_ADULT;
				if (age>=MIN_TEEN && age<=MAX_TEEN)
					price=price+PARK_1DAY_TEEN;
				if ((age>=MIN_CHILD && age<=MAX_CHILD) || age>MAX_ADULT)
					price=price+PARK_1DAY_CHILD;
				if (age<MIN_CHILD)
					price=price+BABY;
			}
			else if (type2==2){
				if (age>=MIN_ADULT && age<=MAX_ADULT)
					price=price+PARK_AFT4_ADULT;
				if (age>=MIN_TEEN && age<=MAX_TEEN)
					price=price+PARK_AFT4_TEEN;
				if ((age>=MIN_CHILD && age<=MAX_CHILD) || age>MAX_ADULT)
					price=price+PARK_AFT4_CHILD;
				if (age<MIN_CHILD)
					price=price+BABY;
			}
		}
}

void calFavor() {
	switch (typeCom){
		case 2:
			printf("������� �� �������� ���� ��+����1��\n\n");
			price=price*(1-DISABLE_DC_RATE);
			break;
		case 3:
			printf("������������ �� �������� ���� ��+����1��\n\n");
			price=price*(1-NATIONAL_DC_RATE);
			break;
		case 4:
			if (type1==1){
				printf("�ް��庴(�ǰ�,�ǹ��ҹ��,������ ����) �������� ���� ��+����1��\n\n");
				price=price*(1-SOLDIER_DC_RATE); 
				break;
				}
			else {
				printf("�ް��庴 ���� �����̿�Ǹ� �̿� ���� �մϴ�.\n\n");
				break;
				}
		case 5:
			if (type1==1){
				printf("���ڼ�ø �� �������� ���� �ӻ�� ����\n\n");
				price=price*(1-PREGNANT_DC_RATE);
				break;
				}
			else {
				printf("�ӻ�� ���� �����̿�Ǹ� �̿� ���� �մϴ�.\n\n");
				break;
				}
		case 6:
			if (type1==1){
				printf("�ٵ��� �ູī�� ȸ�� ���� ����(ī�忡 ���� ������ ����)\n\n");
				price=price*(1-MULTICHILD_DC_RATE);
				break;
				}
			else {
				printf("�ٵ��� �ູī�� ���� �����̿�Ǹ� �̿� ���� �մϴ�.\n\n");
				break;
				}
	}
}

void inputOrder() {
	order[index][0]=type1;
	order[index][1]=type2;
	order[index][2]=ageType;
	order[index][3]=count;
	order[index][4]=price;
	order[index][5]=typeCom;
}

void calTotalPrice() {
	price=price*count;
	if (price%10 != 0)
		price=price-(price%10);
	totalPrice=totalPrice+price;
}

void printPrice() {
	printf("������ %d �� �Դϴ�.\n\n",price);
	price=0;
	printf("�� ������ %d �� �Դϴ�. �����մϴ�.\n\n",totalPrice);
}

void continueMessage() {
	printf("��� ����(1.���ο� �ֹ�,2:���α׷� ����): ");
	scanf("%d",&isExit);
} 

void printOrder() {
	printf("����       �־�  ����Ÿ��  ����      ���� ���\n");
	for (int i=0;i<index;i++){
		switch (order[i][0]){
			case 1:
				printf("�����̿�� ");
				break;
			case 2:
				printf("��ũ�̿�� ");
				break;
		}
		
		switch (order[i][1]){
			case 1:
				printf("%-7s","1DAY");
				break;
			case 2:
				printf("%-7s","After4");
				break;
		}
		
		printf("%3d  ",order[i][2]);
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
}

void makeReport(){
	time_t timer; struct tm* t; timer = time(NULL); t=localtime(&timer);
	FILE *filePointer = fopen("report.csv", "a");
	for (int i=0;i<index;i++){
		fprintf(filePointer,"%d,%d,%d,%d,%d,%d,%d,%d,%d\n",t->tm_year+1900,t->tm_mon+1,t->tm_mday,
												order[i][0],order[i][1],order[i][2],
												order[i][3],order[i][4],order[i][5]);
	}
	fclose(filePointer);
}

void shutDownMessage() {
	printf("���α׷��� �����Ͻðڽ��ϱ�? (1.�� 2.�ƴϿ�)");
	scanf("%d",&isDown);
}

int main()
{
	do
	{
		totalPrice=0;
		do
		{
			selectTicket();		//�̿�� ���� ����
			selectTime();		//�̿� �ð� ���� 
			inputBirth();		//������� �Է�
			ageCal();			//���̰�� 
			inputAgeType();		//���̿� ���� ��� ��� 
			inputCount();		//�����Է� 
			inputFavor();		//������ �Է� 
			calPrice();			//������ ���� ��� 
			calFavor();			//��� ���� ��� 
			calTotalPrice();	//����� ���ݰ� �� ���� ��� 
			inputOrder();		//order�迭�� �� �ֱ� 
			printPrice();		//���� ��� 
			continueMessage();	//�ֹ��� ������� 
			index++;
		}while(isExit==1);
		printOrder();			//�ֹ� ��� 
		makeReport();			//�������Ͽ� �����߰� 
		index=0;
		shutDownMessage();		//���α׷� ���� �޼��� ��� 
	}while(isDown==2);
	return 0;
}
