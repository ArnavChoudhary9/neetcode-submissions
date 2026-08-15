struct VectorHash {
    size_t operator()(const array<int, 26>& v) const {
        size_t h = 0;

        for (int x : v)
            h = h * 31 + x;

        return h;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, VectorHash> mp;

        for (const string& s : strs) {
            array<int, 26> freq{};

            for (char c : s)
                ++freq[c - 'a'];

            mp[freq].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(mp.size());

        for (auto& [key, group] : mp)
            result.push_back(std::move(group));

        return result;
    }
};
