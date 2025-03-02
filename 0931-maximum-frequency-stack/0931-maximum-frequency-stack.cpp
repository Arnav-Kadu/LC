class FreqStack {
public:
    map<int, int> m;
    map<int, vector<int>> group;
    int mx;
    
    FreqStack() {
        mx = 0;
    }
    
    void push(int val) {
        m[val]++;
        int f = m[val];
        if (f > mx) mx = f;
        group[f].push_back(val);
    }
    
    int pop() {
        int ans = group[mx].back();
        group[mx].pop_back();
        m[ans]--;
        if (group[mx].empty()) mx--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */