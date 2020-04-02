#include<stdio.h>
#include<stdlib.h>
#include "../allLinkedList/allLinedList.h"


void mainView();
void view();
void duView();
int main() {
	//Ԥ��������ָ��
	LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));
	(*L) = NULL;
	

	/***************************
	*			�߼�
	****************************/
	char mainChoice;
	char choice;
	while (1) {
		mainView();

		mainChoice = getch();
		if (mainChoice == '3')
			break;

		system("cls");

		//main�������ж�
		switch (mainChoice)
		{
		case '1': {
			while (1) {
				view();

				choice = getch();
				if (choice == '4')
					break;

				system("cls");

				//�������ж�
				switch (choice) {
					//����+¼��
				case '1': aFunction(L); break;
					//��ת+����
				case '2': tFunction(L); break;
					//ɾ��+�ݻ�
				case '3': dFunction(L); break;
				default:
					break;
				}

				system("cls");
			}
			DestroyList(L);
			break;
		}
		case '2': {
			while (1) {
				duView();

				choice = getch();
				if (choice == '4')
					break;

				system("cls");

				//�������ж�
				switch (choice) {
					//����+¼��
				case '1': aDuFunction(L); break;
					//��ת+����
				case '2': tDuFunction(L); break;
					//ɾ��+�ݻ�
				case '3': dDuFunction(L); break;
				}

				system("cls");
			}
			DestroyList_DuL(L);
			break;
		}
		default:
			break;
		}
		
		system("cls");
	}



}

void mainView() {
	/***************************
	*			������
	****************************/
	//�Ͽյ�
	for (int i = 0; i < 12; i++)
		printf("\n");

	//�Ϸֽ�� 
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n\n");

	//Ŀ¼
	printf("\t\t\t\t  1--�����������     2--˫���������    3--�˳�\n\n");


	//�·ֽ��
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}

void view() {
	/***************************
	*			����
	****************************/
	//�Ͽյ�
	for (int i = 0; i < 12; i++)
		printf("\n");

	//�Ϸֽ�� 
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n\n");

	//Ŀ¼
	printf("\t\t\t\t  1--����+¼��     2--��ת+����     3--ɾ��+�ݻ� \n");
	printf("\t\t\t\t  4--�˳� \n\n");


	//�·ֽ��
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}

void duView() {
	/***************************
	*			����
	****************************/
	//�Ͽյ�
	for (int i = 0; i < 12; i++)
		printf("\n");

	//�Ϸֽ�� 
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n\n");

	//Ŀ¼
	printf("\t\t\t\t  1--����+¼��     2--����     3--ɾ��+�ݻ� \n");
	printf("\t\t\t\t  4--�˳� \n\n");


	//�·ֽ��
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}
