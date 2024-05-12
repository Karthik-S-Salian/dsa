#include<stdlib.h>

  struct ListNode {
     int val;
    struct ListNode *next;
};


int getlen(struct ListNode* head){
    int count = 0;
    while(head!=NULL){
        head = head->next;
        count++;
    }
    return count;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len = getlen(head);
    if(len-n==0)
        return head->next;
    struct ListNode * current = head;
    for(int i=1;i<len - n;i++)
        current=current->next;
    current->next = current->next->next;
    return head;
}


struct ListNode* removeNthFromEnd1(struct ListNode* head, int n) {
    int len = 0;
    struct ListNode * current = head;
    for(;current!=NULL;current=current->next,len++);
    if(len==n)
        return head->next;
    current=head;
    for(int i=1;i<len - n;i++)
        current=current->next;
    current->next = current->next->next;
    return head;
}