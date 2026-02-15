class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a, b);
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (j >= 0) {
            int sum = (a[i] - '0') + (b[j] - '0') + carry;
            a[i] = char('0' + (sum & 1));
            carry = sum >> 1;
            i--; j--;
        }

        while (i >= 0 && carry) {
            int sum = (a[i] - '0') + carry;
            a[i] = char('0' + (sum & 1));
            carry = sum >> 1;
            i--;
        }

        if (carry) a.insert(a.begin(), '1');
        return a;
    }
};
