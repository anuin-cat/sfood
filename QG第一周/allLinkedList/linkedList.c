#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList* L) {
    if ((*L) != NULL) {
        return ERROR;
    }
    else
    {
        (*L) = (LinkedList)malloc(sizeof(LNode));
        if ((*L) == NULL) {
            return ERROR;
        }
        else
        {
            (*L)->next = NULL;
            return SUCCESS;
        }
    }
    
};

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L) {

    
    if (L == NULL || (*L) == NULL ) {
        return;
    }
    else
    {
        LinkedList p, head = *L;
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
    }
    
};

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q) {
    if (p == NULL || q == NULL) {
        return ERROR;
    }
    else
    {
        q->next = p->next;
        p->next = q;
        return SUCCESS;
    }
};

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e) {
    //特殊情况判断
    if (p == NULL || p->next == NULL) {
        e = NULL;
        return ERROR;
    }
    else
    {
        LinkedList q = p->next->next;
        *e = p->next->data;
        free(p->next);
        p->next = q;
        return SUCCESS;
    }
    
};

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(LinkedList e)) {
    if (L == NULL||L->next==NULL) {
        printf("链表无数值结点！！！\n");
        return;
    }
    else
    {
        printf("遍历链表：");
        LinkedList T = L->next;
        while (T != NULL) {
            visit(T);
            T = T->next;
        }
        printf("\n");
    }
};

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    if (L == NULL) {
        return ERROR;
    }
    else
    {
        LinkedList p = L;
        for (int i = 0; i < e; i++) {
            p = p->next;
            if (p == NULL) {
                break;
            }
        }
        if (p==NULL)
        {
            return ERROR;
        }
        else {
            return SUCCESS;
        }
    }
    
};

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L) {
    if (L == NULL||(*L)==NULL||(*L)->next==NULL) {
        return ERROR;
    }

    LinkedList pre, now, back;
    pre = NULL;
    now = (*L)->next;

    while (now != NULL) {
        //移位
        back = now->next;
        //断链重连
        now->next = pre;
        //后移
        pre = now;
        now = back;
    }
    (*L)->next = pre;
    return SUCCESS;
};

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    if (L == NULL || L->next == NULL) {
        return ERROR;
    }
    else
    {
        LinkedList p=L, q=L;

        while (q != NULL && q->next != NULL) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                return SUCCESS;
            }
        }
        return ERROR;
    }
};

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */

LNode* ReverseEvenList(LinkedList* L) {
    if (*L == NULL || (*L)->next == NULL || (*L)->next->next == NULL) {
        return *L;
    }
    else
    {
        LinkedList pre = *L, now = (*L)->next,back;
        

        while (now!=NULL && now->next!=NULL) {
            back = now->next;

            now->next = back->next;
            back->next = now;
            pre->next = back;



            pre = now;
            now = now->next;
        }

        return *L;
    }

};

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList* L) {
    if (L == NULL || (*L) == NULL || (*L)->next == NULL) {
        return *L;
    }

    LinkedList slow,fast;

    slow = (*L)->next;
    fast = (*L)->next;

    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
};



/******************
*   visit子函数
******************/

void pri(LinkedList L) {
    printf("%d  ", L->data);
}