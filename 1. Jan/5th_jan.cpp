class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& nums) {
        int row = nums.size();
        int col = nums[0].size();
        long long sum = 0;
        int ct = 0;
        int mn = INT_MAX;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(nums[i][j] < 0) ct++;
                sum += abs(nums[i][j]);
                mn = min(mn, abs(nums[i][j]));
            }
        }

        if(ct % 2 == 0) return sum;
        return sum - 2LL * mn;
    }
};
