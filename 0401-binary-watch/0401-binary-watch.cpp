class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
    vector<string> res;
    for (int mask = 0; mask < (1 << 10); ++mask) {
        if (__builtin_popcount(mask) != turnedOn) continue;
        int h = (mask >> 6) & 0xF;
        int m = mask & 0x3F;
        if (h < 12 && m < 60) {
            ostringstream oss;
            oss << h << ':' << setw(2) << setfill('0') << m;
            res.push_back(oss.str());
        }
    }
    return res;
    }
};