 class Solution {
  public:
      vector<int> validSequence(string word1, string word2) {
          int n = word1.size(), m = word2.size();

          vector<int> latest(m + 1, -1);
          latest[m] = n;
          for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--)
              if (word1[i] == word2[j]) latest[j--] = i;

          vector<int> ans;
          bool used = false;
          for (int i = 0, j = 0; i < n && j < m; i++) {
              bool same = word1[i] == word2[j];
              if (same || (!used && i < latest[j + 1])) {
                  used |= !same;
                  ans.push_back(i);
                  j++;
              }
          }
          return (int)ans.size() == m ? ans : vector<int>();
      }
  };