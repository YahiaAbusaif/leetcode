class Solution {
    int findBoxNum(int r,int c)
    {
        return r/3+int(c/3)*3;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int cntRow [10][10];
        int cntCol[10][10];
        int cntBox [10][10];
        memset(cntRow,0,sizeof(cntRow));
        memset(cntCol,0,sizeof(cntCol));
        memset(cntBox,0,sizeof(cntBox));

        int val;
        for(int i=0;i<9;i++)
        {
            for(int j=0 ; j<9;j++)
            {
                if(board[i][j] =='.')
                    continue;
                val= board[i][j]-'0';
                cntRow[val][i]++;
                cntCol[val][j]++;
                cntBox[val][findBoxNum(i,j)]++;
            }
        }
        for(int i=1;i<=9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(cntRow[i][j]>1 || cntCol[i][j]>1 || cntBox[i][j]>1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};