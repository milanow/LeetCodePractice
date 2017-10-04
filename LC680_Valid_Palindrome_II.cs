/* 680. Valid Palindrome II
 * Frist, shrink the string by comparing left char and right char, when finds out one different char, break
 * Secondly, try eliminating the left or right char of the left substring to see if one of them is Palinfrome
 */

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while(l < r){
            if(s[l] == s[r]) { ++l; --r;}
            else break;
        }
        
        if(l < r){
            return isPalindrome(s.substr(l, r-l)) || isPalindrome(s.substr(l+1, r-l));
        }else{
            return true;
        }
    }
    
    bool isPalindrome(string s){
        int l = 0, r = s.length()-1;
        while(l < r){
            if(s[l] == s[r]) {++l; --r;}
            else return false;
        }
        return true;
    }
};