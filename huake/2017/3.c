#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int num;
    struct LNode *next;
} LNode, *LinkList;

int main(void)
{
    LinkList head1, head2;
    LNode *p,*q;
    int i, up, sum;
    char c;
    while ((c = getchar()) != '\n')
    {
        p = (LNode*) malloc(sizeof(LNode));
        p->num = c - '0';
        p->next = head1->next;
        head1->next = p;
    }
    while ((c = getchar()) != '\n')
    {
        p = (LNode*) malloc(sizeof(LNode));
        p->num = c - '0';
        p->next = head2->next;
        head2->next = p;
    }
    for (p = head1->next, q = head2->next, up = 0; p->next != NULL && q->next != NULL; p = p->next, q = q->next)
    {
        sum = p->num + q->num + up;
        up = sum / 10;
        sum %= 10;
        p->num = sum;
    }
    if (p->next != NULL)
    {
        while(p->next != NULL)
        {
            sum = p->num + up;
            up = sum / 10;
            sum %= 10;
            p->num = sum;
            p = p->next;
        }
    }
    else if (q->next != NULL)
    {
        while(q->next != NULL)
        {
            p->next = (LNode*) malloc(sizeof(LNode));
            p = p->next;
            sum = q->num + up;
            up = sum / 10;
            sum %= 10;
            p->num = sum;
            q = q->next;
        }
    }
    if (up == 1)
    {
        q = (LNode*) malloc(sizeof(LNode));
        p->next = q;
        q->next = NULL;
        q->num = 1;
    }
    p->next = NULL;
    for (p = head2; p->next != NULL; )
    {
        q = p->next;
        p->next = q->next;
        free(q);
    }
    for (p = q = head1->next, head1->next = NULL; q != NULL; )
    {
        q = q->next;
        p->next = head1->next;
        head1->next = p;
        p = q;
    }

    return 0;
}
