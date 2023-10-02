// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

#include<vector>

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        if(numRows == 1){
            return {{1}};
        }
        for(int i=0;i<numRows;i++){
            vector<int> row;
            for(int j=0;j<=i;j++){
                if(((j-1)>=0) && ((j+1)<=i)){
                    int temp = answer[i-1][j-1] + answer[i-1][j];
                    row.push_back(temp);
                    
                }
                else{
                    row.push_back(1);
                }
            }
            answer.push_back(row);
        }
        return answer;
    }
};