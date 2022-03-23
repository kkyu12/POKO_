#include <stdio.h>
#include <ctime>

int main()
{
	int type1,type2,count,typeCom,age,
		isExit,isDown,
		year,month,day;
	int totalPrice=0; int price=0;
	int index=0;
	int order[100][6]={0};//종합,주야,나이,수량,가격,우대 
	
	const int BABY=15000,
		  	  ALL_1DAY_ADULT=59000,ALL_1DAY_TEEN=52000,ALL_1DAY_CHILD=47000,
			  ALL_AFT4_ADULT=48000,ALL_AFT4_TEEN=42000,ALL_AFT4_CHILD=36000,
			  PARK_1DAY_ADULT=56000,PARK_1DAY_TEEN=50000,PARK_1DAY_CHILD=46000,
			  PARK_AFT4_ADULT=45000,PARK_AFT4_TEEN=40000,PARK_AFT4_CHILD=35000;
	
	//현재시간 가져오기 
	time_t timer; struct tm* t; timer = time(NULL); t=localtime(&timer);
	do
	{
		totalPrice=0;
	do
	{
		//이용권 종류 선택 
		do{
			printf("이용권을  선택해주세요.\n");
			printf("1. 종합이용권 : 롯데월드+민속박물관\n");
			printf("2. 파크이용권 : 롯데월드\n");
			scanf("%d",&type1);
			if (!(type1==1 || type1==2))
				printf("잘못 선택하셨습니다.\n");
		}while(!(type1==1 || type1==2)); 
		
		//이용 시간 선택 
		do{
			printf("권종을 선택하세요.\n");
			printf("1. 1Day\n"); printf("2. After4\n");
			scanf("%d",&type2);
			if (!(type2==1 || type2==2))
				printf("잘못 선택하셨습니다.\n");
		}while(!(type2==1 || type2==2));
	
		//나이입력+계산 
		printf("생년월일을 입력하세요. (8자리)\n");
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
		
		//수량입력 
		do{
			printf("몇개를 주문하시겠습니까? (최대 10개)\n");
			scanf("%d",&count); 
			if (count>10 || count<0)
				printf("잘못 입력하셨습니다.\n");
		}while(count>10 || count<0);
				
		//우대사항 선택 
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
				printf("잘못 입력하셨습니다.\n");
		}while(!(typeCom>=1 && typeCom<=6));
		
		//타입별 가격 입력 
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
		//우대 조건 계산 
		if (typeCom==2){
			printf("장애인증 등 공식증빙 지참 고객+동반1인\n");
			price=price*0.5;
		}
		else if (typeCom==3){
			printf("국가유공자증 등 공식증빙 지참 고객+동반1인\n");
			price=price*0.5;
		}
		else if (typeCom==4){
			if (type1==1){
				printf("휴가장병(의경,의무소방관,군무원 포함) 공식증빙 지참 고객+동반1인\n");
				price=price*0.51; 
				}
			else {
				printf("휴가장병 우대는 종합이용권만 이용 가능 합니다.\n");
				break;
				}
		}
		else if (typeCom==5){
			if (type1==1){
				printf("모자수첩 등 공식증빙 지참 임산부 본인\n");
				price=price*0.5;
				}
			else {
				printf("임산부 우대는 종합이용권만 이용 가능 합니다.\n");
				break;
				}
		}
		else if (typeCom==6){
			if (type1==1){
				printf("다둥이 행복카드 회원 가족 본인(카드에 명기된 가족에 한함)\n");
				price=price*0.7;
				}
			else {
				printf("다둥이 행복카드 우대는 종합이용권만 이용 가능 합니다.\n");
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
		
		printf("\n가격은 %d 원 입니다.\n",price);
		price=0;
		printf("\n총 가격은 %d 원 입니다. 감사합니다.\n\n",totalPrice);
		
		printf("계속 진행(1.새로운 주문,2:프로그램 종료): ");
		scanf("%d",&isExit);
		index++;
		
	}while(isExit==1);
	
	printf("종합       주야    나이  수량      가격 우대\n");
	for (int i=0;i<index;i++){
		switch (order[i][0]){
			case 1:
				printf("종합이용권 ");
				break;
			case 2:
				printf("파크이용권 ");
		}
		
		switch (order[i][1]){
			case 1:
				printf("%-7s","1DAY");
				break;
			case 2:
				printf("%-7s","After4");
				break;
		}
		
		printf("%3d세 ",order[i][2]);
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
	
	printf("프로그램을 종료하시겠습니까? (1.예 2.아니오)");
	scanf("%d",&isDown);
	
	}while(isDown==2);
	return 0;
}
