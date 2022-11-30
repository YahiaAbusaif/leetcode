class Solution {
    int n,m;
    
    bool canAccess(int x,int y){
        return x>=0 && y>=0 && x<n && y<m;
    }
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        n= matrix.size(),m=matrix[0].size();
        vector<vector<int>> sum(n,vector<int>(m,0));
        for(int index=0;index<n;index++) {
            for(int iter=0;iter<m;iter++) {
                sum[index][iter]= (matrix[index][iter] -'0');
                if(canAccess(index-1,iter-1)) sum[index][iter]-= sum[index-1][iter-1];
                if(canAccess(index-1,iter)) sum[index][iter]+= sum[index-1][iter];
                if(canAccess(index,iter-1)) sum[index][iter]+= sum[index][iter-1];
            }
        }
        
        int ans=0;
        for(int index=0;index<n;index++) {
            for(int iter=0;iter<m;iter++) {
                while(index+ans<n && iter+ans<m) {
                    int res=sum[index+ans][iter+ans];
                    if(canAccess(index-1,iter-1)) res+= sum[index-1][iter-1];
                    if(canAccess(index+ans,iter-1)) res-= sum[index+ans][iter-1];
                    if(canAccess(index-1,iter+ans)) res-= sum[index-1][iter+ans];
                    if(res == (ans+1)*(ans+1)){
                        ans++;
                    }
                    else break;
                }
            }
        }
        return ans*ans;
        
    }
};