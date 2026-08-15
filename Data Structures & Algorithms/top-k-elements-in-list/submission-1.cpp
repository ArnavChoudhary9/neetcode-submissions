class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int x : nums)
            mp[x]++;

        vector<pair<int, int>> freq;

        for (auto [num, count] : mp)
            freq.push_back({count, num});

        sort(freq.rbegin(), freq.rend());

        vector<int> result;

        for (int i = 0; i < k; i++)
            result.push_back(freq[i].second);

        return result;
    }
};
