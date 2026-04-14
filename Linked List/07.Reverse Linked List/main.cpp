/**
 * Definition for singly-linked list. */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        
        ListNode* blackNode = head;
        ListNode* nextNode = blackNode->next;
        
        while(nextNode)
        {
            blackNode->next = nextNode->next;
            nextNode->next = head;
            head = nextNode;
            nextNode = blackNode->next;
        }
        return head;
    }
};
