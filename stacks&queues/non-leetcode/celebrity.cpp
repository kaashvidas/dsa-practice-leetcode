/* 
  Problem: Celebrity
  Approach: 
  1. Maintain the top and down pointers and at each step, adjust them according to the condition.
  2. If the top and down pointers point to the same person, check for the corresponding row and column to confirm if its the celebrity.
  Time Complexity: O(2N)
  Space Complexity: O(1)
  
*/

class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int top=0;
        int down= M.size()-1;
        while (top<down){
            if (M[top][down]==1){
                top++;
            }
            else if (M[down][top]==1){
                down--;
            }
            else {
                top++;
                down--;
            }
        }
        if (top>down){
            return -1;
        }
        else {
            for (int i=0; i<M.size(); i++){
                if (M[top][i]==1){
                    return -1;
                }
                if (M[i][top]==0 && i!=top){
                    return -1;
                }
            }
            return top;
            
        }
        
    }
};
