class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int i =0;
        int j =0;
        int ans =  1;
        if(s.size()==1){
            return 1;
        }
        if(s.size()==0){
            return 0;
        }
        bool flag = false;
        while( j<s.size()){
            m[s[j]]++;
            if(m[s[j]]>=2){
                flag = true;
                 ans = max(ans,j-i);
                while( i<s.size() && s[i]!=s[j]){
                    
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
                
                m[s[j]]--;
                i++;
          
            }
            j++;
          
            
        }
        ans = max(ans,j-i);
        return  ans;
        
    }
};