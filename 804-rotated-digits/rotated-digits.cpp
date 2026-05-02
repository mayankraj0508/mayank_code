class Solution {
public:
    bool check(int x){
        int prev = x;
        if(x==0){
            return false;
        }
        int  news = 0;
        int product = 1;
        while(x>0){
            int rem = x%10;
            if(rem==3 ||rem==4 || rem==7){
                return false;
            }
            else if(rem==0 || rem==1 ||rem==8){
              news = rem*product +news;
              product = product*10;
            }
            else if(rem==2 || rem==5){
                if(rem==2){
                    rem = 5;
                    news = rem*product +news;
                     product = product*10;
                }
                else{
                    rem=2;
                    news = rem*product +news;
                     product = product*10;
                }
            }
            else{
                   if(rem==6){
                    rem = 9;
                    news = rem*product +news;
                     product = product*10;
                }
                else{
                    rem=6;
                    news = rem*product +news;
                     product = product*10;
                }
                
            }
            x = x/10;

        }
       if(prev==news){
        return false;
       }
       
       return true;
    }
    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i<=n; i++){
            if(check(i)){
                count++;
            }

        }
        return count;
        
    }
};