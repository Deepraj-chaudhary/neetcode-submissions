/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool comp(Interval &a,Interval &b){
        return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        priority_queue<int,vector<int>,greater<>> q;
        for(auto i:intervals){
            if(q.empty()){
                q.push(i.end);
                continue;
            }
            if(q.top()<=i.start) q.pop();
            q.push(i.end);
        }
        return q.size();
    }
};
