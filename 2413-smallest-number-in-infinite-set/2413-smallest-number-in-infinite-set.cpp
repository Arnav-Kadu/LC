class SmallestInfiniteSet {
public:
    vector<int> m;
    int start = 1;
    SmallestInfiniteSet() :m(1001,1){
    }

    int popSmallest() {
        for (int i = start; i <= 1000; i++) {
            if (m[i] != -1) {
                m[i] = -1;
                return i;
            }
        }
        return start;
    }

    void addBack(int num) {
        m[num] = 1;
        start = min(start, num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */