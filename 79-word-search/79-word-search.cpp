class Solution {
    string target;
    vector<vector<char>> graph;
    bool visit[10][10];
    
    bool solve(int idx, int x, int y)
    {
        if(x<0 || y<0 || x>=graph.size() || y>= graph[0].size() || graph[x][y]!=target[idx] ||visit[x][y])
            return false;
        if( idx == target.size()-1 )
        {
            return true;
        }
        idx++;
        visit[x][y]=1;
        bool sol=solve(idx,x+1,y) || solve(idx,x-1,y) || solve(idx,x,y-1) || solve(idx,x,y+1);
        visit[x][y]=0;
        return  sol;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        graph = board;
        target = word;
        for(int i=0; i<board.size() ;i++)
        {
            for(int j=0; j< board[0].size() ;j++)
            {
                if(solve(0,i,j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};