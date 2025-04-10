struct Point {
    int x, y;
    double dist;
    Point(int x, int y) : x(x), y(y), dist(sqrt(x * x + y * y)) {}

     bool operator>(const Point& other) const {
        return dist > other.dist;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point, vector<Point>, greater<Point>> pq;

        for (auto& p : points) {
            pq.push(Point(p[0], p[1]));
        }

        vector<vector<int>> ans;
        for (int i = 0; i < k && !pq.empty(); ++i) {
            Point top = pq.top();
            pq.pop();
            ans.push_back({top.x, top.y});
        }

        return ans;
    }
};
