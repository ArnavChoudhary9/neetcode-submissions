class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for (int x : nums)
            ++count[x];

        // bucket[f] = elements occurring f times
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& [num, freq] : count)
            bucket[freq].push_back(num);

        vector<int> result;
        result.reserve(k);

        for (int freq = nums.size(); freq >= 1 && result.size() < k; --freq) {
            for (int num : bucket[freq]) {
                result.push_back(num);

                if (result.size() == k)
                    break;
            }
        }

        return result;
    }
};
