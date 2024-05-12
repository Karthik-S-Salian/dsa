#include<stdlib.h>

  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head==NULL)
        return head;

    struct ListNode* current = head->next;
    struct ListNode* last_unique = head;
    
    while(current!=NULL){
        if(current->val != last_unique->val){
            last_unique->next = current;
            last_unique = current;
        }
        current = current->next;
    }
    last_unique->next = NULL;
    return head;
}