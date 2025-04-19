class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for (int x = 0; x < n; ++x){
            mp[nums[x]] = x;
        }
        for (int x = 0; x < n; ++x){
            const auto & iter = mp.find(target - nums[x]);
            if (iter != mp.end() && iter->second != x){
                return {x,iter->second};
            }
        }
        return {-1,-1};
    }
};