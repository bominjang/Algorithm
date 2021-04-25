//
//  main.c
//  midterm
//
//  Created by 장보민 on 2021/04/17.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    char data;
    struct ListNode* link;
}ListNode;

typedef struct
{
    ListNode* head;
}LinkedListType;

void init(LinkedListType* L)
{
    L->head = NULL;
}

int isEmpty(LinkedListType* L)
{
    return L->head == NULL;
}

void addFirst(LinkedListType* L, int item)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = item;
    node->link = L->head;
    L->head = node;
}

void buildList(LinkedListType* L, char c)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = c;
    node->link = NULL;
    
    ListNode* before = L->head;
    while(before->link != NULL)
    {
        before = before->link;
    }
    before->link = node;
    
}

void printList(LinkedListType* L)
{
    for(ListNode* p = L->head; p!=NULL;p=p->link)
    {
        printf("[%c] -> ", p->data);
    }
    printf("NULL\n");
}

void printSelect(LinkedListType* L,LinkedListType* S)
{
    ListNode* l = L->head;
    ListNode* s = S->head;
    int pos;
    while(s != NULL)
    {
        pos = (int)s->data - 48;
        l = L->head;
        for(int i=1;i<pos;i++)
        {
            l = l->link;
        }
        printf("%c ", l->data);
        s = s->link;
    }

}

void main() {
    LinkedListType A, B;
    init(&A), init(&B);
    addFirst(&A, 'O');
    buildList(&A, 'R');
    buildList(&A, 'A');
    buildList(&A, 'N');
    buildList(&A, 'G');
    buildList(&A, 'E');
    
    addFirst(&B, '1');
    buildList(&B, '4');
    buildList(&B, '5');
    
    printList(&A);
    printList(&B);
    
    printSelect(&A, &B);
    printf("\n");
}
