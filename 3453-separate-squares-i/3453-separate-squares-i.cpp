class Solution {
private:
    bool check(double mid, const vector<vector<int>>& squares, double totalArea){
        double area = 0.0;
        for (const auto &square : squares) {
            double y = square[1];
            double l = square[2];
            double overlap = mid - y;
            if (overlap < 0) overlap = 0;
            if (overlap > l) overlap = l;
            area += l * overlap;
        }
        return area >= totalArea / 2.0;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double mx_y = 0.0;
        for (const auto &square : squares) {
            double y = square[1];
            double l = square[2];
            totalArea += l * l;
            mx_y = max(mx_y, y + l);
        }
        double down = 0.0, up = mx_y;
        double error = 1e-5;
        while (up - down > error) {
            double mid = (up + down) / 2.0;
            if (check(mid, squares, totalArea)) up = mid;
            else down = mid;
        }
        return up;
    }
};
