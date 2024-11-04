class Solution {
public:
    // 300. Longest Increasing Subsequence
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // Check if each element can increase the
        // length of LIS and add it to ans. i.e largest element so far.
        // If not replace the element in ans that it is greater than.
        for(int i = 0; i < n; ++i){
            auto lb =  lower_bound(ans.begin(),ans.end(),nums[i]);
            if(lb == ans.end()) ans.emplace_back(nums[i]);
            else *lb = nums[i];
        }
        return static_cast<int>(ans.size());
    }
};