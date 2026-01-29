class Solution {
public:
    void FloydWarshall(vector<vector<long long>>& nums, vector<char>& original, vector<char>& changed, vector<int>& cost){
          for(int i=0;i<original.size();i++){
             int s = original[i]-'a';
             int t = changed[i]-'a';
             nums[s][t] = min(nums[s][t], (long long)cost[i]);
          }
          //apply floyd Warshall
          for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                 for(int j=0;j<26;j++){
                    nums[i][j] = min(nums[i][j], nums[i][k]+nums[k][j]);
                 }
            }
          }

          return;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> nums(26, vector<long long>(26, INT_MAX));
        FloydWarshall(nums,original,changed,cost);
        long long ans = 0;
         for(int i=0;i<source.length();i++){
            if(source[i]==target[i]) continue;
            if(nums[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;
                ans+=nums[source[i]-'a'][target[i]-'a'];
         }
         return ans;
    }
};