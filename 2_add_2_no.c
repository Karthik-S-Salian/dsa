#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int sum = l1->val + l2->val;
    struct ListNode *result = l1;
    struct ListNode *current = result;
    struct ListNode *extra = l2;
    struct ListNode *block;
    current->val = sum % 10;
    sum = sum / 10;
    l2 = l2->next;
    l1 = l1->next;
    while (l1 != NULL || l2 != NULL)
    {
        if (l1 != NULL)
        {
            sum += l1->val;
            block = l1;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            block = l2;
            l2 = l2->next;
        }

        block->val = sum % 10;
        current->next = block;
        current = block;
        sum = sum / 10;
    }
    if (sum != 0)
    {
        current->next = extra;
        extra->val = sum;
        extra->next = NULL;
    }
    else
    {
        current->next = NULL;
    }

    return result;
}