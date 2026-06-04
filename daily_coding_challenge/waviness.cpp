/*
Problem: Waviness of a number 
Platform: LeetCode #1
Difficulty: Medium

Approach:
1. Waviness is the count of peaks and valleys in a number 
2. Extract and store the digits of each number in a vector 
3. Compare each digit with its adjacent digits and increment count accordingly 

Time Complexity: O(nd)  --d: no of digits in each number, n: numbers in the range 
Space Complexity: O(d)

Date Solved: 2026-06-04
*/

class Solution {
public:
    int wavy (int num){
    if (num<100){
        return 0;
    }
    vector <int> n;
    while (num!=0){
        n.push_back(num%10);
        num=num/10;
    }
    
    int count=0;
    for (int i=1; i<n.size()-1; i++){
        if (n[i]<n[i-1] && n[i]<n[i+1]){
            count++;
        }
        if (n[i]>n[i-1] && n[i]>n[i+1]){
            count++;
        }
    }
    return count;
}
int totalWaviness(int num1, int num2){
    int total=0;
    while (num1<=num2){
        total+=wavy(num1);
        num1++;
    }
    return total;
}
    
};

