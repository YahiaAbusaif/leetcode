class Solution {
    vector<vector<int>> graph;
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> req(numCourses, 0);
        vector<vector<int>> appear(numCourses, vector<int>(0));
        
        for(int i=0;i<prerequisites.size();i++){
            req[prerequisites[i][0]]++;
            appear[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> zero;
        
        for(int i=0;i<numCourses;i++){
            if(req[i]==0)
                zero.push_back(i);
        }
        
    
        for(int i=0;i<zero.size();i++){
            int index= zero[i];
            for(int j=0;j<appear[index].size();j++){
                if(--req[appear[index][j]] == 0 )
                    zero.push_back(appear[index][j]);
            }
        }
        
        return zero.size()==numCourses;
    }
};