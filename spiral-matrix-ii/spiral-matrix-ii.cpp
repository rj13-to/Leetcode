class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        
        // calculate how many levels deep the spiral is and keep count of walking the spiral
        int level = ceil(n / 2), count = 1;
        
        // start from outside level moving inside
        for (int l = 0; l <= level; ++l) {
            // populate top row from left to right
            for (int a = l; a < n - l; ++a) result[l][a] = count++;
            
            // populate right column from top to bottom
            for (int b = l + 1; b < n - l; ++b) result[b][n - l - 1] = count++;
            
            // populate bottom row from right to left
            for (int c = l + 1; c < n - l; ++c) result[n - l - 1][n - c - 1] = count++;
            
            // populate left column from bottom to top
            for (int d = l + 1; d < n - l - 1; ++d) result[n - d - 1][l] = count++;
        }
        
        return result;
    }
};