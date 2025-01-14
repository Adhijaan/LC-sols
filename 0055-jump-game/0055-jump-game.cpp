class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0; // Tracks the farthest index we can reach

        for (int i = 0; i < n; ++i) {
            // If we can't reach this index, return false
            if (i > farthest) return false;

            // Update the farthest index we can reach
            farthest = max(farthest, i + nums[i]);

            // If we can reach or exceed the last index, return true
            if (farthest >= n - 1) return true;
        }
        return false;
    }
};
