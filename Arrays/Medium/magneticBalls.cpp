/*
Problem: Maximise minimum distance between magnetic balls
Platform: LeetCode #1552
Difficulty: Medium

Approach:
1. Use the binary search algorithm to find the appropriate distance.
2. PLace the balls accordingly and check if allocation is possible within the given distance, if possible, increase it, else decrease it.

Time Complexity: O(n log n)
Space Complexity: O(1)

Date Solved: 2026-06-23
*/


class Solution {
public:
    bool canPlace(vector <int>&position, int dist, int m ){
        int numBalls=1; 
        int last= position[0];
        for (int i=1; i<position.size(); i++){
            if ((position[i]-last)>=dist){
                last= position[i];
                numBalls++;
            }
        }
        return numBalls>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low=1;
        int high= position.back()-position.front();
        while (low<=high){
            int mid= low+(high-low)/2;
            if (canPlace(position, mid, m)){
                low=mid+1;
            }
            else {
                high= mid-1;
            }
        }
        return high;
        
    }
};
