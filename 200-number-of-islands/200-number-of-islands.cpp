class Solution {
    int height,width;
    vector<vector<char>> landMap;
    
    void removeIsland(int x,int y){
        if(x<0 || x>=height || y<0 || y>=width || landMap[x][y]=='0' )
            return;
        landMap[x][y] ='0';
        removeIsland(x,y+1);
        removeIsland(x,y-1);
        removeIsland(x+1,y);
        removeIsland(x-1,y);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands=0;
        landMap=grid;
        height=grid.size();
        width=grid[0].size();
        for(int index=0;index<height;index++){
            for(int innerIndex=0;innerIndex<width;innerIndex++)
            {
                if(landMap[index][innerIndex] == '1'){
                    numberOfIslands++;
                    removeIsland(index,innerIndex);
                }
            }
        }
        return numberOfIslands;
    }
};