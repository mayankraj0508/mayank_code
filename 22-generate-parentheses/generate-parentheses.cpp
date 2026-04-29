class Solution {
public:
   vector<string>finls;
    void f(string ans , int n,int open, int close){
          if(close>open || open>n || close>n){
            return ;

        }
        if(close==n && open ==n){
              finls.push_back(ans);
              return ;
   
        }
        if(open==close){
            f(ans+'(',n,open+1,close);
        }
        else if(open>close){
            if(open==n){
                f(ans+')',n,open,close+1);
            }
            else{
                f(ans+'(',n,open+1,close);
                f(ans+')',n,open,close+1);
            }
        }
      

    }
    vector<string> generateParenthesis(int n) {
        f("",n,0,0);
        return finls;
        
        
    }
};