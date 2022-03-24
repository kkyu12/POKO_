#include <stdio.h>
#include <ctime>

	int type1,type2,count,typeCom,age,ageType,
		isExit,isDown,
		year,month,day;
	int totalPrice=0, price=0;
	int index=0;
	int order[100][6]={0};//종합,주야,나이,수량,가격,우대
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
	printf("%s","잘못 선택하셨습니다.\n\n");
}

void selectTicket() {
	do{ //이용권 종류 선택
		printf("이용권을  선택해주세요.\n");
		printf("1. 종합이용권 : 롯데월드+민속박물관\n");
		printf("2. 파크이용권 : 롯데월드\n");
		scanf("%d",&type1);
		if (!(type1==1 || type1==2))
			errorMessage();
	}while(!(type1==1 || type1==2));
}

void selectTime() {
	do{
		printf("권종을 선택하세요.\n");
		printf("1. 1Day\n"); printf("2. After4\n");
		scanf("%d",&type2);
		if (!(type2==1 || type2==2))
			errorMessage();
	}while(!(type2==1 || type2==2));
}

void inputBirth() {
	printf("생년월일을 입력하세요. (8자리)\n");
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
		ageType=1;	//1.노인 
	if (age>=MIN_ADULT && age<=MAX_ADULT)
		ageType=2;	//2.성인 
	if (age>=MIN_TEEN && age<=MAX_TEEN)
		ageType=3;	//3.청소년 
	if (age>=MIN_CHILD && age<=MAX_CHILD)
		ageType=4;	//4.어린이 
	if (age<MIN_CHILD)
		ageType=5;	//5.유아 
}

void inputCount() {
	do{
		printf("몇개를 주문하시겠습니까? (최대 10개)\n");
		scanf("%d",&count); 
		if (count>MAX_COUNT || count<MIN_COUNT)
			errorMessage();
	}while(count>MAX_COUNT || count<MIN_COUNT);
}

void inputFavor() {
	do{
		printf("우대사항을 선택하세요.\n");
		printf("1. 없음 (나이 우대는 자동처리)\n");
		printf("2. 장애인\n");
		printf("3. 국가유공자\n");
		printf("4. 휴가장병\n");
		printf("5. 임산부\n");
		printf("6. 다둥이\n");
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
			printf("장애인증 등 공식증빙 지참 고객+동반1인\n\n");
			price=price*(1-DISABLE_DC_RATE);
			break;
		case 3:
			printf("국가유공자증 등 공식증빙 지참 고객+동반1인\n\n");
			price=price*(1-NATIONAL_DC_RATE);
			break;
		case 4:
			if (type1==1){
				printf("휴가장병(의경,의무소방관,군무원 포함) 공식증빙 지참 고객+동반1인\n\n");
				price=price*(1-SOLDIER_DC_RATE); 
				break;
				}
			else {
				printf("휴가장병 우대는 종합이용권만 이용 가능 합니다.\n\n");
				break;
				}
		case 5:
			if (type1==1){
				printf("모자수첩 등 공식증빙 지참 임산부 본인\n\n");
				price=price*(1-PREGNANT_DC_RATE);
				break;
				}
			else {
				printf("임산부 우대는 종합이용권만 이용 가능 합니다.\n\n");
				break;
				}
		case 6:
			if (type1==1){
				printf("다둥이 행복카드 회원 가족 본인(카드에 명기된 가족에 한함)\n\n");
				price=price*(1-MULTICHILD_DC_RATE);
				break;
				}
			else {
				printf("다둥이 행복카드 우대는 종합이용권만 이용 가능 합니다.\n\n");
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
	printf("가격은 %d 원 입니다.\n\n",price);
	price=0;
	printf("총 가격은 %d 원 입니다. 감사합니다.\n\n",totalPrice);
}

void continueMessage() {
	printf("계속 진행(1.새로운 주문,2:프로그램 종료): ");
	scanf("%d",&isExit);
} 

void printOrder() {
	printf("종합       주야  연령타입  수량      가격 우대\n");
	for (int i=0;i<index;i++){
		switch (order[i][0]){
			case 1:
				printf("종합이용권 ");
				break;
			case 2:
				printf("파크이용권 ");
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
		printf("%3d장 ",order[i][3]);
		printf("%7d원 ",order[i][4]);
		
		switch (order[i][5]){
			case 1:
				printf("우대사항없음\n");
				break;
			case 2:
				printf("장애인 우대\n");
				break;
			case 3:
				printf("국가유공자 우대\n");
				break;
			case 4:
				printf("휴가장병 우대\n");
				break;
			case 5:
				printf("임산부 우대\n");
				break;
			case 6:
				printf("다둥이 행복카드 우대\n");
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
	printf("프로그램을 종료하시겠습니까? (1.예 2.아니오)");
	scanf("%d",&isDown);
}

int main()
{
	do
	{
		totalPrice=0;
		do
		{
			selectTicket();		//이용권 종류 선택
			selectTime();		//이용 시간 선택 
			inputBirth();		//생년월일 입력
			ageCal();			//나이계산 
			inputAgeType();		//나이에 따른 등급 계산 
			inputCount();		//수량입력 
			inputFavor();		//우대사항 입력 
			calPrice();			//권종별 가격 계산 
			calFavor();			//우대 조건 계산 
			calTotalPrice();	//한장당 가격과 총 가격 계산 
			inputOrder();		//order배열에 값 넣기 
			printPrice();		//가격 출력 
			continueMessage();	//주문을 계속할지 
			index++;
		}while(isExit==1);
		printOrder();			//주문 출력 
		makeReport();			//매출파일에 내용추가 
		index=0;
		shutDownMessage();		//프로그램 종료 메세지 출력 
	}while(isDown==2);
	return 0;
}
