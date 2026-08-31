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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;

        int i = 1;
        int prevCri = 0;
        int firstCri = 0;

        int minDist = INT_MAX;

        while(curr->next != NULL){
            if((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val)){
                if(prevCri == 0){
                    prevCri = i;
                    firstCri = i;
                }
                else{
                    minDist = min(minDist, i - prevCri);
                    prevCri = i;
                }
            }

            i++;
            prev = curr;
            curr = curr->next;
        }

        if(minDist == INT_MAX) return {-1, -1};

        return {minDist, prevCri - firstCri};
    }
};