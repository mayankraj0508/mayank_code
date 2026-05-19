class Solution {
public:
    
    vector<int>v;

    Solution(ListNode* head) {
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int n = v.size();

        int idx = rand() % n;

        return v[idx];
    }
};