class Solution {
private:
    void generate(vector<int>& set, unordered_map<string, int>& powerSetMap) {
        int n = set.size();
        int totalSubsets = (1 << n);
        for (int mask = 0; mask < totalSubsets; ++mask) {
            string binaryKey = bitset<16>(mask).to_string().substr(16 - n);                         
            powerSetMap[binaryKey] = 1;
        }
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> set(n);
        iota(set.begin(), set.end(), 1);
        unordered_map<string, int> mapper;
        generate(set, mapper);
        for (auto i : nums) {
            mapper[i] = 0;
        }
        for (auto i : mapper) {
            if (i.second == 1) {
                return i.first;
            }
        }
        return "";
    }
};