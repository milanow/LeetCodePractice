/* 678. Valid Parenthesis String
 * two stacks to record the number of left parenthesis and star,
 * when meeting a ')', pop from '(' stack first, if non '(', pop '*', if both empty return false
 * after checking the string, check two stacks, if at any moment, '*' is enough for holding '('
 */ 
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftp;
        stack<int> star;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                leftp.push(i);
            }else if(s[i] == '*'){
                star.push(i);
            }else{
                if(leftp.empty() && star.empty()) return false;
                
                if(leftp.empty()) star.pop();
                else leftp.pop();
            }
        }
        
        while(!leftp.empty() && !star.empty()){
            if(leftp.top() > star.top()) return false;
            leftp.pop();
            star.pop();
        }
        return leftp.empty();
    }
};