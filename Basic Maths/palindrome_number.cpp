/*
Problem: Palindrome Number 
Platform: LeetCode
Difficulty: Easy

Approach:
1. If number is negative, it is not a palindrome 
2. Extract the digits till half and compare it with the remaining number.

Time Complexity: O(log n)
Space Complexity: O(1)

Date Solved: 2026-06-01
*/


#include <iostream>
using namespace std;
    
     bool isPalindrome(long int x) {
        if (x<0|| x%10==0 && x!=0){
            return false;
        }
        long int rev=0;
        while (x>rev){
            rev=rev*10+x%10;  x=x/10;
    }  return x==rev || x==rev/10;
}
 int main(){
   int n;
   cin>> n;
   for (int i=0; i<n; i++){
     long num;
     cin>> num;
     cout<< isPalindrome(num)<< endl;
   }
   return 0;
 }
