class Solution {
public:
    int M = 1e9+7;
     string states[12] = {"RYG", "RGY", "RYR", "RGR",
     "YRG", "YGR", "YGY", "YRY","GRY", "GYR","GRG","GYG"};
      int solve(int n, int prev){
          if(n==0) return 1;
          int result = 0;
           string last = states[prev];
            for(int curr=0;curr<12;curr++){
                if(curr==prev) continue;
                string curpattern = states[curr];
                bool conflict = false;
                for(int col =0;col<3;col++){
                    if(curpattern[col]==last[col]){
                        conflict = true;
                        break;
                    }
                }
                if(!conflict){
                    result = (result + solve(n-1,curr)) % M;
                }
            }
      }
    int numOfWays(int n) {
        int result = 0;
        for(int i=0;i<12;i++){
         //now remaining n-1 rows painting
          result = (result + solve(n-1, i))%M;

          }
           return result;
    }
};