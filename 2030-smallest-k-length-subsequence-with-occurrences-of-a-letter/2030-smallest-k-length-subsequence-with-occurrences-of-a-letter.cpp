class Solution {
  public:
      string smallestSubsequence(string s, int k, char letter, int rep) {
          int n = s.size();

          vector<int> cnt(n + 1, 0);
          for (int i = n - 1; i >= 0; --i) cnt[i] = cnt[i + 1] + (s[i] == letter);

          vector<vector<int>> pos(26);
          for (int i = 0; i < n; ++i) pos[s[i] - 'a'].push_back(i);
          vector<int> ptr(26, 0); // which index to use for which character while seeing pos

          string ans;
          int need = rep, start = 0;

          for (int j = 0; j < k; ++j) {
              for (int ch = 0; ch < 26; ++ch) {
                  while (ptr[ch] < (int)pos[ch].size() && pos[ch][ptr[ch]] < start) ptr[ch]++;
                  if (ptr[ch] == (int)pos[ch].size()) continue;

                  int i = pos[ch][ptr[ch]];
                  bool isL = (ch + 'a' == letter);

                  if (j + n - i < k) continue;
                  if (cnt[i] < need) continue;
                  if (need - isL > k - j - 1) continue;

                  ans += char('a' + ch);
                  need -= isL;
                  start = i + 1;
                  break;
              }
          }
          return ans;
      }
  };