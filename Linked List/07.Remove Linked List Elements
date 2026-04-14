/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res = new ListNode(0, head);
        ListNode* prevNode = res;
        
        while(prevNode != nullptr)
        {
            while(prevNode->next != nullptr && prevNode->next->val == val)
            {
                ListNode* delNode = prevNode->next;
                prevNode->next = delNode->next;
                delete delNode;
            }
            prevNode = prevNode->next;
        }
        
        ListNode* result = res->next;
        delete res;
        return result;
    }
};
