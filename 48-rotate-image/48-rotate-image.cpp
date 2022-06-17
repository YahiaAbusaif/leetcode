class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int center=matrix.size()/2, end=matrix.size()-1;
        for(int i=0;i<=end;i++)
        {
            for(int j =0;j<center;j++)
            {
                swap(matrix[i][j],matrix[i][end-j]);
            }
        }

        int tempend;
        
        for(int i=0;i<=end;i++)
        {
            tempend =end-i ;
            for(int j=0;j<tempend;j++)
            {
                swap(matrix[i][j],matrix[end-j][end-i]);
            }
        }
    }
};