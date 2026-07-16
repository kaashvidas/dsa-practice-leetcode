/* 
Problem: Longest Substring with at most k distinct characters
Approach: 
1. Maintain two pointers- left and right. Increment the value of the right charcater in the map.
2. If the map size exceeds k, shorten the windoww by incrementing left and decrease its map value. If map value equals zero, erase it from the map.
3. Adjust max accordingly. 

*/

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int right=0; int left=0; 
        int maxi= INT_MIN;
        map <int, int> mpp;
        while (right<s.size()){
            mpp[s[right]]++;
            while (mpp.size()>k){
                mpp[s[left]]--;
                if (mpp[s[left]]==0){
                    mpp.erase(s[left]);
                }
                left++;
            }
            maxi= max(maxi, right-left+1);
            right++;
        }
        return maxi;
    }
};
