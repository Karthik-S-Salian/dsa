#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (head == NULL)
        return NULL;

    int len = 1;
    struct ListNode *crr = head;
    while (crr->next != NULL)
    {
        len += 1;
        crr = crr->next;
    }

    crr->next = head;
    k = len - k % len;

    while (k-- > 1)
        head = head->next;

    crr = head->next;
    head->next = NULL;
    return crr;
}