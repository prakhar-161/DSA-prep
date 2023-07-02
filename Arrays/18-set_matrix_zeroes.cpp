
// brute
// TC -> O(N*M) * O(N+M) + O(N*M)
// SC -> O(1) 

// better approach
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row[200] = {0}, col[200] = {0};
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
// TC -> O(2*N*M)
// SC -> O(N) + O(M)

// OPTIMAL SOLUTION
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 1, y = 1;

        // make x = 0 if there is 0 in the first row
        for(int j=0; j<n; j++) {
            if(matrix[0][j] == 0) x = 0;
        }
        // make y = 0 if there is 0 in the first col
        for(int i=0; i<m; i++) {
            if(matrix[i][0] == 0) y = 0;
        } 

        // traverse for the smaller matrix i.e. except the first row and first column
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // mark the corresponding rows and columns zero
        for(int j=1; j<n; j++) {
            if(matrix[0][j] == 0) {
                for(int i=1; i<m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i=1; j<m; i++) {
            if(matrix[i][0] == 0) {
                for(int j=1; j<m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // handling first row and first column
        if(y == 0) {
            for(int i=0; i<m; i++) {
                matrix[i][0] = 0;
            }
        }
        if(x == 0) {
            for(int j=0; j<n; j++) {
                matrix[0][j] = 0;
            }
        }


    }
};