class Solution {
public:
    int minMaxDifference(int num) {
        string temp = to_string(num), temp2 = temp;
        int first_non_nine = -1;
        for (char c : temp) {
            if (c != '9') {
                first_non_nine = c - '0';
                break;
            }
        }
        for (char &c : temp) {
            if (c - '0' == first_non_nine) c = '9';
        }
        int maxv = stoi(temp);
        char f = temp2[0];
        for (char &c : temp2) {
            if (c == f) c = '0';
        }
        int minv = stoi(temp2);
        return maxv - minv;
    }
};
