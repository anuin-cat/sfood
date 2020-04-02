#include<stdio.h>
#include<stdlib.h>
#include"duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L) {
    if ((*L) != NULL) {
        return ERROR;
    }
    else
    {
        (*L) = (DuLinkedList)malloc(sizeof(DuLNode));
        if ((*L) == NULL) {
            return ERROR;
        }
        else
        {
            (*L)->next = NULL;
            (*L)->prior = NULL;
            return SUCCESS;
        }
    }
};

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L) {
    
    if (L == NULL || (*L) == NULL) {
        printf("已经为空，无法摧毁！！！\n");
        return;
    }
    else
    {
        DuLinkedList p, head = *L;
        p = head->next;
        while (head != NULL) {
            free(head);
            if (p != NULL) {
                head = p;
                p = p->next;
            }
            else
            {
                head = p;
            }
        }
        *L = NULL;
        printf("摧毁成功！！！\n");
    }
};

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
    if (p == NULL || q == NULL || p->prior == NULL) {
        return ERROR;
    }
    else
    {
        q->prior = p->prior;
        p->prior->next = q;
        p->prior = q;
        q->next = p;
        return SUCCESS;
    }
};

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
    if (p == NULL || q == NULL ) {
        return ERROR;
    }
    else if(p->next == NULL)
    {
        p->next = q;
        q->prior = p;
        q->next = NULL;
        return SUCCESS;
    }
    else
    {
        q->next = p->next;
        q->prior = p;
        p->next->prior = q;
        p->next = q;
        
        return SUCCESS;
    }
};

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e) {
    //特殊情况判断
    if (p == NULL || p->next == NULL) {
        e = NULL;
        return ERROR;
    }
    else
    {
        DuLinkedList q = p->next->next;
        *e = p->next->data;

        if (q == NULL) {
            free(p->next);
            p->next = q;
        }
        else
        {
            free(p->next);
            p->next = q;
            q->prior = p;

        }
        return SUCCESS;
    }
};

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(DuLinkedList e)) {
    if (L == NULL || L->next == NULL) {
        printf("链表中无数据节点！！！\n");
        return;
    }
    else
    {
        printf("遍历链表：");
        DuLinkedList T = L->next;
        while (T != NULL) {
            visit(T);
            T = T->next;
        }
        printf("\n");
    }
};


/******************
*   visit子函数
******************/

void duPri(DuLinkedList L) {
    printf("%d  ", L->data);
}


