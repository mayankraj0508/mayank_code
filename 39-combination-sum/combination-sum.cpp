class Solution {
public:
   vector<vector<int>>ans;
     void f(vector<int>&candidates, int target, int i,vector<int>&temp){
        if(i==candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            else{
                return ;
            }
        }
        if(target<0){
            return ;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }
        temp.push_back(candidates[i]);
        f(candidates,target-candidates[i],i,temp);
        
        if(temp.size()){
            temp.pop_back();
        }
        f(candidates,target,i+1,temp);
        
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
         vector<int>temp;
         f(candidates,target,0,temp);
        return ans;
        
    }
};