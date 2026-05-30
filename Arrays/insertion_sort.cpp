/*
Problem: Insertion Sort Algorithm 
Difficulty: Easy

Approach: Iterate through the array from the second to the last element and at each point, place the element at its correct position by performing consecutive swaps backwards.

Time Complexity: Average Case- O(n^2), Best Case (sorted input array)- O(n)
Space Complexity: O(n)

Date Solved: 2026-05-30
*/




#include <iostream>
using namespace std;
void insertion_sort(int arr[], int n){
    for (int i=1; i<=n-1; i++){
        int j=i;
        while (j>0 and arr[j-1]>arr[j]){
            int temp= arr[j];
            arr[j]= arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    insertion_sort(arr, n);
    for (int i=0; i<n; i++){
        cout<< arr[i]<< " ";
    }
    
    return 0;
    
}
