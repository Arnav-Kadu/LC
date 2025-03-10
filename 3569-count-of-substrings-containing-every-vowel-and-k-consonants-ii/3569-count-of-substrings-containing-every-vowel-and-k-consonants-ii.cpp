class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long response = 0;
        int currentK = 0, vowels = 0, extraLeft = 0, left = 0;
        set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
        map<char, int> freq;
        for (int right = 0; right < word.size(); right++) {
            char ch = word[right];
            if (vowelSet.count(ch)) {
                freq[ch]++;
                if (freq[ch] == 1) vowels++;
            } else {
                currentK++;
            }
            while (currentK > k) {
                char leftChar = word[left++];
                if (vowelSet.count(leftChar)) {
                    freq[leftChar]--;
                    if (freq[leftChar] == 0) vowels--;
                } else {
                    currentK--;
                }
                extraLeft = 0;
            }
            while (vowels == 5 && currentK == k && left < right && vowelSet.count(word[left]) && freq[word[left]] > 1) {
                extraLeft++;
                freq[word[left]]--;
                left++;
            }
            if (currentK == k && vowels == 5) {
                response += (1 + extraLeft);
            }
        }
        return response;
    }
};
