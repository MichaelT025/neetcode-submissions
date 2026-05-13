class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size=piles.size();
        int left=1;
        int right=0;
        for(int i=0; i<size; i++) right=max(right, piles[i]);
        int ans=right;
        while(left<=right){
            int k=(left+right)/2;
            long long ksum=0;
            for(int i=0;i<size;i++){
                ksum+=(piles[i]+k-1)/k;
            }
            if(ksum<=h){
                ans=k;
                right=k-1;
            }else left=k+1;
        }
        return ans;
    }
};
