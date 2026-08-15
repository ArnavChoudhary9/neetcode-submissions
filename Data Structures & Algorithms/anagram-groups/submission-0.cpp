struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        size_t h = 0;

        for (int x : v) {
            h = h * 31 + std::hash<int>{}(x);
        }

        return h;
    }
};

class Solution {
public:
    vector<int> toKey(const string& s) {
        std::vector<int> freq(26, 0);
        
        for (const char& i : s) {
            freq[i - 'a']++;
        }
        
        return freq;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, VectorHash> mp;

        for (auto& a : strs) {
            mp[toKey(a)].push_back(a);
        }

        vector<vector<string>> result;

        for (auto& [key, group] : mp) {
            result.push_back(group);
        }

        return result;
    }
};
