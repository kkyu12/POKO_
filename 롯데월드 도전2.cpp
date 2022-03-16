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
	
	printf("이용권을  선택해주세요.\n");
	printf("1. 종합이용권 : 롯데월드+민속박물관\n");
	printf("2. 파크이용권 : 롯데월드\n");
	scanf("%d",&type1);
	
	printf("권종을 선택하세요.\n");
	printf("1. 1Day\n"); printf("2. After4\n");
	scanf("%d",&type2);
	
	printf("생년월일을 입력하세요.\n");
	scanf("%4d%2d%2d",&year,&month,&day);
	//나이계산 
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
	
	printf("우대사항을 선택하세요.\n");
	printf("1. 없음 (나이 우대는 자동처리)\n");
	printf("2. 장애인\n");
	printf("3. 국가유공자\n");
	printf("4. 휴가장병\n");
	printf("5. 임산부\n");
	printf("6. 다둥이\n");
	scanf("%d",&typeCom);
	//타입별 가격 입력 
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
	
	printf("%d %d %d년 %d월 %d일 %d우대 %d세\n",type1,type2,year,month,day,typeCom,age);
	
	printf("권종 가격은 %d 원 입니다.\n",price);

	printf("총 가격은 %d 원 입니다.\n감사합니다.\n",totalPrice);
	printf("계속 진행(1.새로운 주문,2:프로그램 종료): ");
	scanf("%d",isExit);
	}
	return 0;
}
