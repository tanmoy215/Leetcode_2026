#include<bits/stdc++.h>
using namespace std;
int main(){
     vector<int> nums = {1,3,6,10,15};
     sort(nums.begin(),nums.end());
      int n = nums.size();
      int i=0;
      int j=1;
      int minVal = INT_MAX;
       while(j<n){
         minVal = min(minVal, nums[j]-nums[i]);
         i++;
         j++;
       }
       vector<vector<int>> ans;
        i=0;
        j=1;
        while(j<n){
            if((nums[j]-nums[i])==minVal){
                ans.push_back({nums[i], nums[j]});
            }
            i++;
            j++;
        }
        
        //print
        for(auto row : ans){
            for(auto col : row){
                cout<<col<<" ";
            }
             cout<<endl;
        }
    return 0;
}