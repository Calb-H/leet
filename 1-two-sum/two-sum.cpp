class Solution {
public:
/*
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = 0;
        size_t maxIndex = nums.size();
        vector<int> result(2, 0);
        for (i = 0; i < maxIndex; i++) {
            for (j = i+1; j < maxIndex; j++)
                if ((nums[i] + nums[j]) == target) {
                    // I believe this is more performant than a clean looking result = {i, j};
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
        }
        return result;
    }
    */

    vector<int> twoSum(vector<int>& nums, int target) {

        // implemented a very rudimentary hashmap instead of using unordered_map (for no good reason)
        int keyMax = nums.size() * 2;
        std::vector<std::vector<int>> valueToIndex(keyMax, std::vector<int>(0));

        int currIndex = 0;
        for (const auto num : nums) {
            // check if num has any candidate matches with an index already in the table
            int counterpart = target - num;
            std::vector<int>& candidates = valueToIndex[abs(counterpart % keyMax)];
            for (const auto prevIndex : candidates) {
                if (nums[prevIndex] == counterpart) {
                    return {currIndex, prevIndex};
                }
            }

            // map current value to current index
            std::vector<int>& indices = valueToIndex[abs(num % keyMax)];
            indices.push_back(currIndex);
            currIndex++;
        }

        return {-1, -1};
    }
};