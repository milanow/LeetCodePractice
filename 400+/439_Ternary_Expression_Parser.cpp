/* 439. Ternary Expression Parser
 * Since the tenary expression is always valid, there fore there will be a ':' as
 * long as there is a '?'. The character before '?' must be 'T' or 'F';
 * (1)If 'T', we can give up all sub-expression after the same level of ':'
 * (2)If 'F', we can five up all sub-expression between this '?' and same level of ':'
 * 
 * Therefore, we pass into the index of each none '?' or ':' character, checking what
 * is the character after it
 * (3)If '?', then return the value of either (1) or (2)
 * (4)If ':', then we can directly return current index of value (we want this value because if not, 
 *    the character after the index won't be ':')
 */

class Solution {
public:
    string parseTernary(string expression, int begin = 0) {
        if(begin >= expression.size()) return "";
        if(begin == expression.size() - 1 || expression[begin+1] == ':') return expression.substr(begin, 1);
        if(expression[begin] == 'T') return parseTernary(expression, begin+2);
        int lvl = 1, i = begin + 2;
        for(; i < expression.size() && lvl; i++){
            if(expression[i] == '?') lvl++;
            else if(expression[i] == ':') lvl--;
        }
        return parseTernary(expression, i);
    }
};