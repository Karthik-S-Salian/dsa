#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *traverse(struct ListNode *crr, struct ListNode *head)
{
    if (crr == NULL)
        return head;

    struct ListNode *front = traverse(crr->next, head);
    if (front == NULL)
        return NULL;
    if (front == crr)
    {
        front->next = NULL;
        return NULL;
    }

    struct ListNode *temp = front->next;
    front->next = crr;
    if (crr == temp)
    {
        crr->next = NULL;
        return NULL;
    }
    crr->next = temp;
    return temp;
}

void reorderList(struct ListNode *head)
{
    traverse(head, head);
}