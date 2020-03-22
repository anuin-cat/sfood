#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include"Ԥ������.c"
stu* search(stu*,int,int);	//��ѧ������
stu* createline(int);		//����
stu* insert(stu*, stu);		//����
stu* store(stu*, int);		//�����棺0.���� 1.Ŀǰ
stu* out(stu*, int);		//˳�����
stu* fcreateline(int);		//�ļ����� 0.�ϳ� 1.Ŀǰ
stu* delete(stu*,int,int);	//ɾ�� ѧ��+����
stu* inserts(stu*,stu[],int);//�������
stu* sort(stu* head, int n);//���� 0ѧ�� 1���� 2��� 3���� ���0Ϊ��С�����1�Ӵ�С
stu in();					//�������뺯��


stu* searchnum(stu*, int);				//ѧ������
stu* searchDateDeal(stu*, int, int);	//��������
stu* searchSumDeal(stu* ,int);			//���׶�����
stu* searchTypeDeal(stu*, int);			//��������


void mainInterface(void);		//����������
void searchInterface(void);		//��ѯ
void sortInterface(void);		//����
void statisticsInterface(void);	//ͳ��
void putInInterface(void);		//¼��
void delecteInterface(void);	//ɾ��		
void succeed(void);				//�����ɹ�

int code;

int main(void) {
	//system("color A8");
	// ����+ѧ�� ����
	codeFunction();
	

	mainInterface();

	char n;
	n = getch();
	if (n == '6')
		return;
	//�������ж�
	while (1) {
		switch (n)
		{
			//��ѯ
		case '1':searchFunction(); break;
			//����
		case '2':sortFunction(); break;
			//ͳ��
		case '3':statisticsFunction(); break;
			//¼��
		case '4':putInFunction(); break;
			//ɾ��
		case '5':delecteFunction(); break;
			//�˳�
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


	//��������
int searchFunction() {
	system("cls");
	searchInterface();
	//�ļ���ȡ
	stu* head;
	head = fcreateline(1);
	

	//��ȡָ��
	char n;
	n = getch();
	system("cls");
	if (n == '5')
		return 0;
	while (1) {
		//ִ�� 
		switch (n)
		{
			//���̶�ʱ�β�ѯ
		case '1': {
			int date;
			head = fcreateline(1);
			//Ȩ�޹���
			if (code != 8868)
				head = searchnum(head, code);
			//����
			printf("��������Ҫ��ѯ�����ڣ���λ���֣�\n");
			scanf("%d", &date);
			head = searchDateDeal(head, date, date);
			out(head, 6);
			break;
		}
				//�����������ѯ
		case '2': {
			int date1, date2;
			head = fcreateline(1);
			//Ȩ�޹���
			if (code != 8868)
				head = searchnum(head, code);

			printf("��������Ҫ��ѯ�����ڣ�������λ���֣��м��ÿո������\n");
			scanf("%d%d", &date1, &date2);
			head = searchDateDeal(head, date1, date2);
			out(head, 6);
			break;
		}
				//�����׽���ѯ
		case '3': {
			int num;
			head = fcreateline(1);
			//Ȩ�޹���
			if (code != 8868)
				head = searchnum(head, code);

			printf("��������Ҫ��ѯ�Ľ��׽��\n");
			scanf("%d", &num);
			head = searchSumDeal(head, num);
			out(head, 6);
			break;
		}
				//ɾ�����ݲ�ѯ������ԱȨ�ޣ�
		case '4': {
			char a[5] = "8868";
			char b[5] = {'\0','\0' ,'\0' ,'\0' ,'\0' };
			head = fcreateline(0);
			//��������
			printf("���������Ա����\n");
			scanf("%s", &b);
			//�����ж�+ִ��
			if (!strcmp(a, b)) {
				sort(head, 00);
				out(head, 6);
				break;
			}
			else {
				printf("���������û��Ȩ�޷���\n");
				break;
			}
		}
				//�˳�
		case '5':break;
		default :break;
		}
		printf("�����������.....");
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
	//������
int sortFunction() {
	system("cls");
	sortInterface();
	//�ļ���ȡ
	stu* head;
	head = fcreateline(1);
	//Ȩ�޹���
	if (code != 8868)
		head = searchnum(head, code);
	//��ȡָ��
	char n;
	n = getch();
	system("cls");
	if (n == '0')
		return 0;
	while (1) {
		switch (n)
		{
			//��������
		case '1':sort(head, 10), out(head, 6); break;
		case '4':sort(head, 11), out(head, 6); break;
			//���׽��
		case '2':sort(head, 20), out(head, 6); break;
		case '5':sort(head, 21), out(head, 6); break;
			//���״���
		case '3':sort(head, 30), out(head, 6); break;
		case '6':sort(head, 31), out(head, 6); break;

		case '0':break;

		default:
			break;
		}
		if (n == '0')
			break;
		printf("�����������...");

		n = getch();
		system("cls");

		sortInterface();

		n = getch();
		system("cls");
	}
	return 0;
}
	//ͳ�ƹ���
int statisticsFunction() {
	system("cls");
	statisticsInterface();
	
	//ָ���ȡ
	char n;
	n = getch();
	system("cls");
	int date1, date2;

	while (1) {
		if (n == '1') {
			//���ݼ���
			stu* head;
			head = fcreateline(1);

			if (head == NULL) {
				printf("���ݶ�ȡʧ��:124\n");
				break;
			}
			//Ȩ�޹���
			if (code != 8868)
				head = searchnum(head, code);
			//���ݻ�ȡ
			printf("��������ʼʱ�������ʱ�䣨��λ���֣�\n");
			scanf("%d %d", &date1, &date2);
			//���ͳ��
			int sum = 0;
			head = searchDateDeal(head, date1, date2);
			while (head != NULL) {
				sum += head->sumDeal;
				head = head->next;
			}
			system("cls");
			printf("�����ܽ�%d", sum);
			printf("�����������");
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
	//¼�빦��
int putInFunction() {
	system("cls");
	putInInterface();
	//ָ���ȡ
	char n;
	n = getch();
	system("cls");
	if (n != '1' && n != '2')
		return 0;
	//�������
	stu* head;
	head = fcreateline(1);

	while (1) {
		switch (n)
		{
		case '1':head = insert(head, in()),succeed(),store(head, 1); break;

		default:
			break;
		}
		printf("�����������");
		n = getch();
		system("cls");

		putInInterface();

		n = getch();
		system("cls");
		if (n != '1' && n != '2')
			return 0;
	}
}
	//ɾ������
int delecteFunction() {
	system("cls");
	delecteInterface();
	//ָ���ȡ
	char n;
	n = getch();
	system("cls");
	//ָ��ִ��
	stu* head;
	while (1) {
		if (n == '1') {
			printf("������ ѧ�� �� ���״��� ���ո������\n");
			//��ȡ����
			int num, numDeal;
			scanf("%d%d", &num, &numDeal);
			//ɾ��������
			head = fcreateline(1);
			head = delete(head, num, numDeal);
			store(head, 1);
			//�������
			printf("�����������\n");
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
	

	//����+ѧ�Ž���
int codeFunction() {
	
	//�Ͽյ�
	for (int i = 0; i < 13; i++)
		printf("\n");

	//Ŀ¼
	printf("\t\t\t\t   �û�������ѧ��\n\n\t\t\t\t   ����Ա����������\n\n\t   ");

	//�·ֽ��
	printf("\t\t\t   ");
	scanf("%d", &code);
	printf("\n");
	if (code == 8868) {
		printf("\t\t\t\t   ��ӭ����Ա   �����������...");
	}
	else
		printf("\t\t\t\t   ��ӭ�û�%d   �����������...",code);
	getch();
	system("cls");
	return 0;
}
	//�����ɹ�
void succeed() {
	printf("\n�����ɹ�\n");
}