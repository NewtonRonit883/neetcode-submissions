class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_set<float> st;
        int n = speed.size();
        //int cnt = 0;
        vector<pair<int,double>> p;

        for(int i = 0;i<n;i++){
            double time = (double)(target-position[i])/speed[i];
            p.push_back({position[i],time});
        }
        sort(p.rbegin(),p.rend()); //sorting the arr in descending order 
        int cnt = 0;
        double max_time = 0.0;
        for(int i = 0;i<n;i++){
            if (p[i].second > max_time){
                cnt++;
                max_time = p[i].second;
            }
        }
        return cnt;
    }
};
