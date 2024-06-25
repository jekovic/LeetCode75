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
    int pairSum(ListNode* head) {
        int result = 0;
        vector<int> num;
        while(head != nullptr) {
            num.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = num.size() - 1;
        while(left < right){
            result = max(result, num[left] + num[right]);
            left++; right--;
        }
        return result;
    }
};