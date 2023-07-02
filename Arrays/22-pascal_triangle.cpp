// pascal's triangle - I on leetcode

class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;                  // for col = 0
        vector<int> ansRow;
        ansRow.push_back(ans);
        for(int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / (col);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        // no. of rows from 1 to n
        for(int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};