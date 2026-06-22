class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector <int> frequency(26, 0);
        for (char c: text){
            frequency[c-'a']++;
        }
        int ans= INT_MAX;
        ans= min(ans, frequency['b'-'a']/1);
        ans= min(ans, frequency['a'-'a']/1);
        ans= min(ans, frequency['l'-'a']/2);
        ans= min(ans, frequency['o'-'a']/2);
        ans= min(ans, frequency['n'-'a']/1);

        return ans;        
    }
};
