#include<stdlib.h>

  struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* result;
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    if(list1->val>list2->val){
        result = list2;
        list2 = list2->next;
    }
    else{
        result = list1;
        list1 = list1->next;
    }



    struct ListNode* head = result;
    while(list1!=NULL && list2!=NULL){
        if(list1->val>list2->val){
            result->next = list2;
            result = list2;
            list2 = list2->next;
        }
        else{
            result->next = list1;
            result = list1;
            list1 = list1->next;
        }
    }

    result->next = list1?list1:list2;

    return head;
}