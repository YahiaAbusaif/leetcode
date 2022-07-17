class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int end = height.size()-1;
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());
        
        maxLeft[0]=height[0];
        for(int index = 1 ; index < height.size() ; index++)
        {
            maxLeft[index] = max(maxLeft[index-1],height[index]);
        }

        maxRight[end] = height[end];
        for(int index=end-1 ; index >= 0;index--)
        {
            maxRight[index]=max(maxRight[index+1],height[index]);
        }

        for(int index=1 ; index < end;index++)
        {
            ans+=max(0,(min(maxRight[index+1],maxLeft[index-1])-height[index]));
                
        }
        return ans;
    }
};