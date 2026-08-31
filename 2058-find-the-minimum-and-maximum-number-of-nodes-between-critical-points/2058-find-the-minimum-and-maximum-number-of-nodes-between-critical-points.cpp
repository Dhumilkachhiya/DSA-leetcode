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
        vector<int> ans = {-1, -1};
        int lastindex = -1;
        int firstindex = -1;
        int index = 1;
        int miin = INT_MAX;
        ListNode* prev = head;
        head = head->next;
        while (head->next != NULL) {

            if (head->val < head->next->val && head->val < prev->val ||
                head->val > head->next->val && head->val > prev->val) {
                if (firstindex == -1) {
                    firstindex = index;
                }
                if (lastindex != -1) {
                    miin = min(miin, index - lastindex);
                }

                lastindex = index;
            }

            index++;
            prev = head;
            head = head->next;
        }
        if(miin!=INT_MAX){
            ans[0]=miin;
            ans[1] = lastindex - firstindex;
        }
        return ans;
    }
};