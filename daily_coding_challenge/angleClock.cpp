/*
Problem: Angle between hands of clock
Platform: LeetCode #1344
Difficulty: Easy

Approach:
1. Compute the minute angle and the hour angle.
2. Return the smaller angle between the two hands of the clock.

Time Complexity: O(1)
Space Complexity: O(1)

Date Solved: 2026-06-18
*/


class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle= minutes* 6;
        double hourAngle= (hour*30)+ (minutes*0.5);
        return min(abs(minuteAngle-hourAngle), (360-abs(minuteAngle-hourAngle)));        
    }
};
