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

struct ListNode *helper(struct ListNode *crr, struct ListNode *temp)
{
    if (temp == NULL)
        return crr;

    if (temp->next == NULL)
    {
        temp = crr->next;
        crr->next = NULL;
        return temp;
    }

    struct ListNode *next = helper(crr->next, temp->next->next);

    if (crr->next == next)
    {
        temp = next->next;
        next->next = NULL;
        return temp;
    }

    temp = crr->next;
    crr->next = next->next;
    next->next = temp;
    temp = crr->next;
    crr->next = next;
    return temp;
}

void reorderList(struct ListNode *head)
{
    helper(head, head);
}