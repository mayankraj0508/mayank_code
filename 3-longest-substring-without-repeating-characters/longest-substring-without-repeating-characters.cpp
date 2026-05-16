class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> m;

        int i = 0;
        int j = 0;

        int ans = 0;

        while(j < s.size()) {

            m[s[j]]++;

            // duplicate mila
            if(m[s[j]] > 1) {

                // duplicate aane se pehle wali valid length
                ans = max(ans, j - i);

                // duplicate hatao
                while(s[i] != s[j]) {

                    m[s[i]]--;

                    if(m[s[i]] == 0) {
                        m.erase(s[i]);
                    }

                    i++;
                }

                // old duplicate remove
                m[s[i]]--;
                i++;
            }

            j++;
        }

        // ho sakta h last tak kabhi duplicate aaya hi na ho
        ans = max(ans, j - i);

        return ans;
    }
};