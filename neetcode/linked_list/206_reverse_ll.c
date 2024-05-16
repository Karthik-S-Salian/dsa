#include<stdlib.h>

  struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prvs = NULL;
    struct ListNode* temp;
    struct ListNode* crr=head;

    while(crr!=NULL){
        temp = crr->next;
        crr->next=prvs;
        prvs = crr;
        crr = temp;
    }

    return prvs;
}