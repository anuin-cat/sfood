//ѧ�����ѽṹ�嶨��
#pragma once
typedef struct card {
	int num;			//ѧ��

	int dateDeal;		//��������
	int dateIn;			//��������

	int sumDeal;		//���׶�
	int	sumLeft;		//���׺����

	int typeDeal;		//��������: 1.POS����, 2.΢��֧��, 3.������֧��
	
	int numDeal;		//���״���
	char siteDeal[30];	//���׵ص�

	struct card* next;	//����	
}stu;