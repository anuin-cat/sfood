typedef char TElemType;      // �������������Ԫ������Ϊ�ַ�


typedef struct  BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode,*BiTree;   // ��������


typedef enum Status{
	SUCEESS,
	ERROR
}Status;

Status visit(BiTree T);
Status InitBiTree(BiTree* T);
//�������������ն�����T


Status DestroyBiTree(BiTree T);
//��ʼ������������T����
//����������ݻٶ�����T


Status CreateBiTree(BiTree T, char* definition);
//��ʼ������ definition�����������Ķ���
//�����������definition���������T


//���²��ֺ�������δָ����������
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e));
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//�������
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//�������
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e));	//�������
int Value(BiTree T);			//������Ķ�������ֵ


/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/