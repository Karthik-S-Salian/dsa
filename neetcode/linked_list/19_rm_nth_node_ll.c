#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len = 1;
    struct ListNode* crr = head;
    while(crr->next!=NULL){
        len+=1;
        crr = crr->next;
    }
    n = len-n;
    if(n==0)
        return head->next;

    crr=head;
    while(n-->1)
        crr=crr->next;
    crr->next =crr->next->next;
    return head;

}