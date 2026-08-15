class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq.reserve(nums.size());

        for (int x : nums)
            ++freq[x];

        // bucket[f] = first element having frequency f
        vector<int> head(nums.size() + 1, -1);
        vector<int> next(freq.size(), -1);
        vector<int> values;
        values.reserve(freq.size());

        int id = 0;

        for (auto [num, f] : freq) {
            values.push_back(num);
            next[id] = head[f];
            head[f] = id++;
        }

        vector<int> result;
        result.reserve(k);

        for (int f = nums.size(); f > 0 && result.size() < k; --f) {
            for (int i = head[f]; i != -1 && result.size() < k; i = next[i]) {
                result.push_back(values[i]);
            }
        }

        return result;
    }
};
