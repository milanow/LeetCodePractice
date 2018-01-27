/* 690. Employee Importance
 * The whole structure is like a tree but has multiple (maybe more than two)
 * children (like a Trie?). The algorithm is recursively checking one employee's
 * importance adds its children's importance.
 */

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        return helper(employees, id);
    }
    
    int helper(vector<Employee*>& eps, int id){
        int val = 0;
        for(auto e: eps){
            if(e->id == id){
                val += e->importance;
                for(auto i: e->subordinates){
                    val += helper(eps, i);
                }
            }
        }
        return val;
    }
};