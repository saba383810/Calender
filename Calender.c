#include<stdio.h>
#include<stdlib.h>

int Check_Leapyear(int);

int main (){

	int year,month,cnt,week_cnt;
	int month_date[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int total = 1;
	printf("カレンダーを出力します。\n");
	do{
		printf("年(1以上)を入力してください。>>");
		scanf("%d",&year);
	}while(year<1);

	do{
		printf("月(1~12)を入力してください。>>");
		scanf("%d",&month);
	}while(month>12 || month<1);

	// 閏年計算
	for(cnt = 1;cnt <= year-1;cnt++){
		total = total + 365 + Check_Leapyear(cnt);
	}
	if(Check_Leapyear(year)) month_date[1]++;
	for(cnt = 0;cnt < month-1;cnt++){
		total = total + month_date[cnt];
	}
	// カレンダー
	printf("\n\n\t%d年\n%2d月\n",year,month);
	printf("  日 月 火 水 木 金 土\n");
	for(cnt = 1,week_cnt = 0;cnt <= total%7;cnt++,week_cnt++) printf("   ");
	
	for(cnt = 1;cnt <= month_date[month-1];cnt++,week_cnt++){
		if(week_cnt % 7 == 0) printf("\n");
		
		printf("%3d",cnt);
	}
	return 0;
}

// 閏年なら”1”を返す関数
int Check_Leapyear(int year){
	if(year%400==0||(year%4==0 && year%100 != 0)){
		return 1;
	}else{
		return 0;
	}
}
