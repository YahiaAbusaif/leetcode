class Solution {
    vector< vector<int> > res;
    vector<int> arr;
    
    void solve(vector<int> curr ,int taken){
        if(curr.size() == arr.size()){
            res.push_back(curr);
            return;
        }
        
        for(int index=0;index<arr.size();index++){
            if((1<<index) & taken) 
                continue;
            curr.push_back(arr[index]);
            solve(curr,taken|(1<<index));
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        arr=nums;
        vector<int> temp;
        solve(temp,0);
        return res;

        
    }
};