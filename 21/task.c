#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* 单链表结点：带头结点 */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

/* 创建带头结点的空链表 */
LinkList link_create(void) {
    LinkList head = (LinkList)malloc(sizeof(LNode));
    if (head != NULL) head->next = NULL;
    return head;
}

/*
 * 在第 1 个位置插入 a、b、c 三个元素（头插法）。
 * 思路：head -> n1 -> n2 -> n3 -> 原第一个结点
 * 只改指针，不搬数据，时间复杂度 O(1)。
 */
bool link_insert_three_at(LinkList head, int i, int a, int b, int c) {
    if (head == NULL) return false;

     /* 找第 i-1 个结点 ，i=1 时就是头结点 */
    LNode *prev = head;
    for (int k = 0; k < i - 1 && prev != NULL; k++) {
        prev = prev->next;
    }
    if (prev == NULL) return false;  // i 越界

    /* 一次申请 3 个结点 */
    LNode *n1 = (LNode *)malloc(sizeof(LNode));
    LNode *n2 = (LNode *)malloc(sizeof(LNode));
    LNode *n3 = (LNode *)malloc(sizeof(LNode));
    if (n1 == NULL || n2 == NULL || n3 == NULL) {
        free(n1);
        free(n2);
        free(n3);
        return false;
    }

    n1->data = a;
    n2->data = b;
    n3->data = c;

    /* 关键：3 个结点先自己串起来，再整体挂到头结点后面 */
    n3->next = prev->next;   // n3 接原来的第一个结点
    n2->next = n3;
    n1->next = n2;
    prev->next = n1;         // 头结点指向新的第一个结点
    return true;
}

/* 打印链表 */
void link_print(LinkList head) {
    printf("[");
    for (LNode *p = head->next; p != NULL; p = p->next) {
        printf("%d", p->data);
        if (p->next != NULL) printf(", ");
    }
    printf("]\n");
}

/* 销毁链表：先释放数据结点，再释放头结点 */
void link_destroy(LinkList head) {
    if (head == NULL) return;
    LNode *p = head->next;
    while (p != NULL) {
        LNode *q = p->next;
        free(p);
        p = q;
    }
    free(head);
}

/* 演示 */
int main(void) {
    LinkList head = link_create();
    if (head == NULL) return 1;

    link_insert_three_at(head, 1, 1, 2, 3);
    printf("第 1 次头插 1,2,3:");
    link_print(head);

    link_insert_three_at(head, 2, 4, 5, 6);
    printf("第 2 次头插 4,5,6:");
    link_print(head);

    link_destroy(head);
    return 0;
}