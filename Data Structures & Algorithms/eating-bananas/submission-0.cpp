class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(), piles.end());
        int ans=right;
        while(left<=right){
            int k=(left+right)/2;
            long long ksum=0;
            for(int it: piles){
                if(it%k==0) ksum+=(it/k);
                else ksum+=(it/k)+1;
            }
            if(ksum<=h){
                ans=k;
                right=k-1;
            }else left=k+1;
        }
        return ans;
    }
};
