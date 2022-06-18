class Solution {
    bool compare(const vector<int> &a, const vector<int> & b){
        return a[1]<b[1];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a, const vector<int> & b)
             {return a[0]<b[0];});
        vector<vector<int>> res;
        int start= intervals[0][0],end=intervals[0][1];
        for(int i =1 ;i<intervals.size();i++)
        {
            if(intervals[i][0]<=end)
            {
                end=max(end,intervals[i][1]);
            }
            else
            {
                vector<int> ans(2);
                ans[0]=start,ans[1]=end;
                res.push_back(ans);
                start= intervals[i][0],end=intervals[i][1];
            }
        }
        vector<int> ans(2);
        ans[0]=start,ans[1]=end;
        res.push_back(ans);
        return res;
    }
};