/*
Implement an algorithm to find the kth to last element of a singly linked list.
We can assume we are not provided the length of the list.
*/

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
 public ListNode kthToLast(ListNode head, int k) 
 {
    if(head == nullptr)
          return nullptr; 
    ListNode* ptr1 = head;
    ListNode* ptr2 = head;
    int i = 0;
    while(i<k&&ptr1)
    {
      ptr1 = ptr1->next;
      ++i;
    }
    if(i<k) return nullptr;
    while(ptr1!=nullptr)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr2;
 }
 
