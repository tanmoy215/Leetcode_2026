class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int msum = 0;
        for(int i=0;i<n;i++){
             if(nums[i]<6){
                continue;
             }else{
                int sum =0;
                 int count=0;
                for(int j=1;j<=sqrt(nums[i]);j++){
                     if(nums[i]%j==0){
                        if(j!=nums[i]/j){
                            sum=sum+j+nums[i]/j;
                            count+=2;
                        }else{
                            sum+=j;
                            count+=1;
                        }
                     }
                }
                if(count==4){
                    msum+=sum;
                }
             }
            
        }
        return msum;

    }
};