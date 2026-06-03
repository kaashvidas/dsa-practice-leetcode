/*
Problem: Left Rotate Array by d Places 
Difficulty: Easy

Approach:
1. Store the first d elements in a temporary array
2. Left shift the elements in the actual array
3. Place the first d elements from the temp array at the last 

Time Complexity: O(2n)
Space Complexity: O(1)

Date Solved: 2026-06-03
*/

#include <iostream>
#include <vector>
using namespace std;
void reverse(int arr[], int start, int end){
    while (start<=end){
        int temp= arr[start];
        arr[start]=arr[end];
        arr[end]= temp;
        start++;
        end--;
    }
}
void left_rotate(int arr[], int n, int d){
    d=d%n;
    reverse(arr, 0, d);
    reverse (arr, d+1, n-1);
    reverse (arr, 0, n-1);
}

int main(){
    int n;
    cin>> n;
    int arr[n];
    for (int i=0; i<n; i++){
     cin>> arr[i];
    }
    int d;
    cin >> d;
    d=d%n;
    left_rotate(arr, n, d);
    
    
    for (int j=0; j<n; j++){
        cout << arr[j]<< " ";
    }
    return 0;
}
