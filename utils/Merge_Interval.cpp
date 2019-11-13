// Created by renduo on 19-11-12.
#include <iostream>
#include <vector>

using namespace std;

//// Definition for an interval.
//struct Interval {
//    int start;
//    int end;
//    Interval() : start(0), end(0) {}
//    Interval(int s, int e) : start(s), end(e) {}
//};

vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){return a.start < b.start;});
    vector<Interval> res{intervals[0]};
    for (int i = 1; i < intervals.size(); ++i) {
        if (res.back().end < intervals[i].start) res.push_back(intervals[i]);
        else res.back().end = max(intervals[i].end, res.back().end);
    }
    return res;
}