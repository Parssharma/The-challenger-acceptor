class Solution {
public:
    string removeOuterParentheses(string s) {
     int depth = 0;
     string ans="";
     for(char x:s){
      
       if(x=='('){
        if(depth>0){
            ans+=x;
        }
        depth+=1;
       }else{
        depth-=1;
        if(depth>0){
            ans+=x;
        }
       }
     }
    return ans;

    }
};