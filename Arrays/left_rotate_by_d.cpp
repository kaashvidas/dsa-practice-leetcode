/*
Problem: Left Rotate Array by d Places 
Difficulty: Easy

Approach:
1. Store the first d elements in a temporary array
2. Left shift the elements in the actual array
3. Place the first d elements from the temp array at the last 

Time Complexity: O(n+d)
Space Complexity: O(n)

Date Solved: 2026-06-03
*/

#include <iostream>
#include <vector>
using namespace std;

void left_rotate(int arr[], int n, int d){
    d=d%n;
    int temp[d];
    for (int i=0; i<d; i++){
        temp[i]= arr[i];
    }
    for (int i=d; i<n; i++){
        arr[i-d]= arr[i];
    }
    for (int i= n-d; i<n; i++){
        arr[i]= temp[i-(n-d)];
    }
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
