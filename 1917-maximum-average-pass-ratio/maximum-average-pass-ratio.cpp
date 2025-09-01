class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Custom comparator: higher gain comes first
        auto cmp = [](const pair<double, pair<int,int>>& a,
                      const pair<double, pair<int,int>>& b) {
            return a.first < b.first; // max-heap
        };
        
        priority_queue<pair<double, pair<int,int>>,
                       vector<pair<double, pair<int,int>>>,
                       decltype(cmp)> pq(cmp);
        
        // Push initial gains
        for (auto &c : classes) {
            int pass = c[0], total = c[1];
            double gain = (double)(pass+1)/(total+1) - (double)pass/total;
            pq.push({gain, {pass, total}});
        }
        
        // Distribute extra students
        while (extraStudents--) {
            auto [gain, p] = pq.top(); pq.pop();
            int pass = p.first, total = p.second;
            pass++; total++;
            double newGain = (double)(pass+1)/(total+1) - (double)pass/total;
            pq.push({newGain, {pass, total}});
        }
        
        // Compute final average
        double sum = 0;
        while (!pq.empty()) {
            auto [gain, p] = pq.top(); pq.pop();
            sum += (double)p.first / p.second;
        }
        
        return sum / classes.size();
    }
};
