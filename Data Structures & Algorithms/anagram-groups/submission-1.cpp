#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    struct CustomHash {
        size_t operator()(const array<int, 26>& arr) const {
            size_t h = 0;
            for (int x : arr) {
                h ^= hash<int>{}(x) + 0x9e3779b9
                     + (h << 6) + (h >> 2);
            }
            return h;
        }
    };

    unordered_map<array<int, 26>, vector<string>, CustomHash> mp;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    for (string& s : strs) {
    // 1. 建立新的 array，26 個元素都是 0
    array<int, 26> count{};

    // 2. 統計這個字串的字母頻率
    for (char c : s) {
        count[c - 'a']++;
    }

    // 3. 將 count 當作 Hash Map 的 Key
    mp[count].push_back(s);

    }
    
    for (auto& [key, group] : mp) {
        result.push_back(group);
    }

    return result;


    }
};
