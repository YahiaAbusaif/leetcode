class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> location;
        for(int index=0; index< strs.size();index++){
            string temp = strs[index];
            sort(temp.begin(), temp.end());
            if (location.find(temp) == location.end()){
                location[temp] = ans.size();
                ans.push_back(vector<string>());
                ans[location[temp]].push_back(strs[index]);
            }else{
                ans[location[temp]].push_back(strs[index]);
            }
        }
        return ans;
        
    }
};