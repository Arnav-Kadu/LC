class Solution {
private:
    void generate(int n, int& k, string& curr, string& result) {
        if (curr.size() == n) {
            k--;
            if (k == 0) {
                result = curr;
            }
            return;
        }
        
        for (char temp : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != temp) {
                curr.push_back(temp);
                generate(n, k, curr, result);
                curr.pop_back();
                if (k == 0) return;
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if (k > total)
            return "";
        
        string curr;
        string result;
        generate(n, k, curr, result);
        return result;
    }
};
