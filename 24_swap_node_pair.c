#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode *temp;
    struct ListNode *nex = head;
    struct ListNode *result = head->next;
    struct ListNode *prvs = NULL;

    while (nex != NULL && nex->next != NULL)
    {
        if (prvs != NULL)
            prvs->next = nex->next;
        prvs = nex;
        temp = nex->next->next;
        nex->next->next = nex;
        nex = temp;
    }
    prvs->next = nex;

    return result;
}