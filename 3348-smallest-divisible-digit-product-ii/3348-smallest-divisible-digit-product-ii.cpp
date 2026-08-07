 class Solution {
  private:
      bool check(long long n) {
          if (n <= 0)
              return false;

          for (int i = 2; i <= 9; i++) {
              while (n % i == 0) {
                  n /= i;
              }
          }
          return n==1;
      }

  public:
      string smallestNumber(string num, long long t) {
          if (!check(t)) {
              return "-1";
          }
          // now the idea is i need to fit t from right to left, starting with
          // small space i need to move big and make sure that all my big numbers
          // should be at first forunately i only have 1 to 9 as my factorizing
          // choices so it makes it easy
          string ans;
          int n = num.size();
          vector<long long> pre(n + 1);
          pre[0] = t;
          int firstZero = n;
          for (int j = 0; j < n; j++) {
              long long d = (long long)(num[j] - '0');
              if (d == 0 && firstZero == n) firstZero = j;
              pre[j + 1] = (d == 0) ? pre[j] : pre[j] / __gcd(pre[j], d);
          }
          if (firstZero == n && pre[n] == 1) {
              ans = num;
          }
          for (int i = 0; i < n && i <= 60; i++) {
              string temp = num;
              int cut = max(0, n - i - 2);
              long long left = pre[cut];
              for (int j = n - 1; j >= cut; j--) { // slice from last
                  for (int k = 9; k >= 2; k--) {
                      if (left % k == 0) {
                          temp[j] = '0'+k;
                          left /= k;
                          break;
                      }
                  }
              }
              if(left==1){
                if (temp.find('0') != string::npos) continue;
                if (temp < num) continue;
                if (ans.empty() || temp < ans) ans = temp;
              }
          }
          for (int p = min(firstZero, n - 1); p >= 0; p--) {
              string best;
              for (int c = num[p] - '0' + 1; c <= 9 && best.empty(); c++) {
                  long long left = pre[p] / __gcd(pre[p], (long long)c);
                  int L = n - p - 1;
                  string tail(L, '1');
                  for (int j = L - 1; j >= 0 && j >= L - 60; j--) {
                      for (int k = 9; k >= 2; k--) {
                          if (left % k == 0) {
                              tail[j] = '0'+k;
                              left /= k;
                              break;
                          }
                      }
                  }
                  if (left == 1) best = num.substr(0, p) + (char)('0' + c) + tail;
              }
              if (!best.empty()) {
                  if (ans.empty() || best < ans) ans = best;
                  break;
              }
          }
          for (int L = n + 1; L <= n + 60 && ans.empty(); L++) {
              string temp(L, '1');
              long long left = t;
              for (int j = L - 1; j >= 0 && j >= L - 60; j--) {
                  for (int k = 9; k >= 2; k--) {
                      if (left % k == 0) {
                          temp[j] = '0'+k;
                          left /= k;
                          break;
                      }
                  }
              }
              if (left == 1) ans = temp;
          }
          return ans.empty() ? "-1" : ans;
      }
  };
