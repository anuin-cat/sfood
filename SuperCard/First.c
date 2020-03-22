#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include"预处理定义.c"
stu* search(stu*,int,int);	//按学号搜索
stu* createline(int);		//创建
stu* insert(stu*, stu);		//插入
stu* store(stu*, int);		//链表储存：0.废弃 1.目前
stu* out(stu*, int);		//顺序输出
stu* fcreateline(int);		//文件加载 0.废除 1.目前
stu* delete(stu*,int,int);	//删除 学号+次数
stu* inserts(stu*,stu[],int);//多组插入
stu* sort(stu* head, int n);//排序 0学号 1日期 2金额 3次数 后加0为从小到达，加1从大到小
stu in();					//数据输入函数


stu* searchnum(stu*, int);				//学号搜索
stu* searchDateDeal(stu*, int, int);	//日期搜索
stu* searchSumDeal(stu* ,int);			//交易额搜索
stu* searchTypeDeal(stu*, int);			//类型搜索


void mainInterface(void);		//主界面生成
void searchInterface(void);		//查询
void sortInterface(void);		//排序
void statisticsInterface(void);	//统计
void putInInterface(void);		//录入
void delecteInterface(void);	//删除		
void succeed(void);				//操作成功

int code;

int main(void) {
	//system("color A8");
	// 密码+学号 接受
	codeFunction();
	

	mainInterface();

	char n;
	n = getch();
	if (n == '6')
		return;
	//主界面判断
	while (1) {
		switch (n)
		{
			//查询
		case '1':searchFunction(); break;
			//排序
		case '2':sortFunction(); break;
			//统计
		case '3':statisticsFunction(); break;
			//录入
		case '4':putInFunction(); break;
			//删除
		case '5':delecteFunction(); break;
			//退出
		case '6':break;
		default:
			break;
		}
		system("cls");
		mainInterface();
		n = getch();
		if (n == '6')
			break;
	}
	return;
}


	//搜索功能
int searchFunction() {
	system("cls");
	searchInterface();
	//文件读取
	stu* head;
	head = fcreateline(1);
	

	//获取指令
	char n;
	n = getch();
	system("cls");
	if (n == '5')
		return 0;
	while (1) {
		//执行 
		switch (n)
		{
			//按固定时段查询
		case '1': {
			int date;
			head = fcreateline(1);
			//权限管理
			if (code != 8868)
				head = searchnum(head, code);
			//输入
			printf("请输入需要查询的日期（八位数字）\n");
			scanf("%d", &date);
			head = searchDateDeal(head, date, date);
			out(head, 6);
			break;
		}
				//按日期区间查询
		case '2': {
			int date1, date2;
			head = fcreateline(1);
			//权限管理
			if (code != 8868)
				head = searchnum(head, code);

			printf("请输入需要查询的日期（两个八位数字，中间用空格隔开）\n");
			scanf("%d%d", &date1, &date2);
			head = searchDateDeal(head, date1, date2);
			out(head, 6);
			break;
		}
				//按交易金额查询
		case '3': {
			int num;
			head = fcreateline(1);
			//权限管理
			if (code != 8868)
				head = searchnum(head, code);

			printf("请输入需要查询的交易金额\n");
			scanf("%d", &num);
			head = searchSumDeal(head, num);
			out(head, 6);
			break;
		}
				//删除数据查询（管理员权限）
		case '4': {
			char a[5] = "8868";
			char b[5] = {'\0','\0' ,'\0' ,'\0' ,'\0' };
			head = fcreateline(0);
			//密码输入
			printf("请输入管理员密码\n");
			scanf("%s", &b);
			//密码判断+执行
			if (!strcmp(a, b)) {
				sort(head, 00);
				out(head, 6);
				break;
			}
			else {
				printf("密码错误，您没有权限访问\n");
				break;
			}
		}
				//退出
		case '5':break;
		default :break;
		}
		printf("按任意键返回.....");
		n = getch();
		system("cls");
		searchInterface();
		n = getch();
		system("cls");
		if (n == '5')
			break;
	}
	return 0;
}
	//排序功能
int sortFunction() {
	system("cls");
	sortInterface();
	//文件读取
	stu* head;
	head = fcreateline(1);
	//权限管理
	if (code != 8868)
		head = searchnum(head, code);
	//获取指令
	char n;
	n = getch();
	system("cls");
	if (n == '0')
		return 0;
	while (1) {
		switch (n)
		{
			//交易日期
		case '1':sort(head, 10), out(head, 6); break;
		case '4':sort(head, 11), out(head, 6); break;
			//交易金额
		case '2':sort(head, 20), out(head, 6); break;
		case '5':sort(head, 21), out(head, 6); break;
			//交易次数
		case '3':sort(head, 30), out(head, 6); break;
		case '6':sort(head, 31), out(head, 6); break;

		case '0':break;

		default:
			break;
		}
		if (n == '0')
			break;
		printf("按任意键返回...");

		n = getch();
		system("cls");

		sortInterface();

		n = getch();
		system("cls");
	}
	return 0;
}
	//统计功能
int statisticsFunction() {
	system("cls");
	statisticsInterface();
	
	//指令获取
	char n;
	n = getch();
	system("cls");
	int date1, date2;

	while (1) {
		if (n == '1') {
			//数据加载
			stu* head;
			head = fcreateline(1);

			if (head == NULL) {
				printf("数据读取失败:124\n");
				break;
			}
			//权限管理
			if (code != 8868)
				head = searchnum(head, code);
			//数据获取
			printf("请输入起始时间与结束时间（八位数字）\n");
			scanf("%d %d", &date1, &date2);
			//金额统计
			int sum = 0;
			head = searchDateDeal(head, date1, date2);
			while (head != NULL) {
				sum += head->sumDeal;
				head = head->next;
			}
			system("cls");
			printf("消费总金额：%d", sum);
			printf("按任意键返回");
			n = getch();
			system("cls");
			statisticsInterface();
			n = getch();
		}
		else
			return 0;
	}
	return 0;
}
	//录入功能
int putInFunction() {
	system("cls");
	putInInterface();
	//指令获取
	char n;
	n = getch();
	system("cls");
	if (n != '1' && n != '2')
		return 0;
	//链表加载
	stu* head;
	head = fcreateline(1);

	while (1) {
		switch (n)
		{
		case '1':head = insert(head, in()),succeed(),store(head, 1); break;

		default:
			break;
		}
		printf("按任意键返回");
		n = getch();
		system("cls");

		putInInterface();

		n = getch();
		system("cls");
		if (n != '1' && n != '2')
			return 0;
	}
}
	//删除功能
int delecteFunction() {
	system("cls");
	delecteInterface();
	//指令获取
	char n;
	n = getch();
	system("cls");
	//指令执行
	stu* head;
	while (1) {
		if (n == '1') {
			printf("请输入 学号 和 交易次数 （空格隔开）\n");
			//获取数据
			int num, numDeal;
			scanf("%d%d", &num, &numDeal);
			//删除并储存
			head = fcreateline(1);
			head = delete(head, num, numDeal);
			store(head, 1);
			//按键检测
			printf("按任意键返回\n");
			n = getch();
			system("cls");

			delecteInterface();

			n = getch();
			system("cls");
		}
		else
			break;
	}
	return 0;
}
	

	//密码+学号接受
int codeFunction() {
	
	//上空地
	for (int i = 0; i < 13; i++)
		printf("\n");

	//目录
	printf("\t\t\t\t   用户：输入学号\n\n\t\t\t\t   管理员：输入密码\n\n\t   ");

	//下分界符
	printf("\t\t\t   ");
	scanf("%d", &code);
	printf("\n");
	if (code == 8868) {
		printf("\t\t\t\t   欢迎管理员   按任意键进入...");
	}
	else
		printf("\t\t\t\t   欢迎用户%d   按任意键进入...",code);
	getch();
	system("cls");
	return 0;
}
	//操作成功
void succeed() {
	printf("\n操作成功\n");
}