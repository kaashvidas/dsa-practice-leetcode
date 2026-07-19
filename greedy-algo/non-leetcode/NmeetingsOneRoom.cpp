/*
Problem: N Meetings in One Room 
Approach: 
1. Store the start and end time of the meeting along with its index into a structure.
2. Sort the vector of structures on the basis of their end times.
3. Iterate through the sorted vector and if the start time of the meeting is after the lastEndtime, add it to the result and increment the no of meetings possible, else skip.
*/


class Solution{
    public:
    struct meetings{
        int start;
        int end;
        int idx;
    };
    static bool compare(meetings a, meetings b){
        if (a.end==b.end){
            return a.idx< b.idx;
        }
        return a.end< b.end;
    }
    int maxMeetings(vector<int>& start, vector<int>& end){
        int n= start.size();
        vector <meetings> Meeting;
        for (int i=0; i<n; i++){
            Meeting.push_back({start[i], end[i], i+1});
        }
        sort(Meeting.begin(), Meeting.end(), compare);
        int lastTime=-1; int cnt=0;
        vector <int> results;
        for (meetings meeting: Meeting ){
            if (meeting.start>lastTime){
                results.push_back(meeting.idx);
                cnt++;
                lastTime= meeting.end;
            }
        }
        return cnt;

        
    }
};
