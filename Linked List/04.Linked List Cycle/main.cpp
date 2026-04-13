struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) { // Check if fast pointer can move forward
            fast = fast->next->next; // Move fast pointer by 2 steps
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;        
    }
};