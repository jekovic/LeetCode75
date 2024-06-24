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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL)
            return NULL;

        int cnt = 0;
        ListNode* cur = head;
        while(cur->next != nullptr){
            cnt++;
            cur = cur->next;
        }
        
        int i=0;
        ListNode* last = NULL;
        ListNode* current = head;
        while(i < ((cnt+1)/2)) {
            last = current;
            current = current->next;
            i++;
        }

        last->next = current->next;
        current->next = NULL;
        delete current;

        return head;
    }
};