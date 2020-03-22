//学生消费结构体定义
#pragma once
typedef struct card {
	int num;			//学号

	int dateDeal;		//消费日期
	int dateIn;			//入账日期

	int sumDeal;		//交易额
	int	sumLeft;		//交易后余额

	int typeDeal;		//交易类型: 1.POS消费, 2.微信支付, 3.云闪付支付
	
	int numDeal;		//交易次数
	char siteDeal[30];	//交易地点

	struct card* next;	//链接	
}stu;