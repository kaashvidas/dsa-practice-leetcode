/*
Problem: Quick Sort Algorithm
Difficulty: Easy

Approach:
1. Decide a pivot element (can be first, last, median or random)
2. Rearrange the other elements of the array around the pivot such that smaller elements are on the left and greater elements are on the right 
3. Perform the same with the two arrays created till you get singular elements 

Advantage over Merge Sort: Although time complexity is the same for both algorithms, creation of temporary array is not required in quick sort which lowers 
the space complexity.

Time Complexity: O(n log n )
Space Complexity: O(1)

Date Solved: 2026-06-03
*/
#include <iostream>
using namespace std;

int f(int arr[], int low, int high){
    int i= low; 
    int j= high;
    int pivot= arr[low];
    while (i<j){
        while (arr[i]<=pivot && i<high){
            i++;
        }
        while (arr[j]> pivot && j>low){
            j--;
        }
        if (i<j){
            int temp= arr[j];
            arr[j]= arr[i];
            arr[i]= temp;
        }
    }
    int temp= arr[low];
    arr[low]= arr[j];
    arr[j]= temp;
    return j;
}

void quick_sort(int arr[], int low, int high){
    if (low<high){
         int p_index= f(arr, low, high);
         quick_sort(arr, low, p_index-1);
         quick_sort(arr, p_index+1, high);
    }
}
int main() {
    int n;
    cin>> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    quick_sort(arr, 0, n-1);
    for (int i=0; i<n; i++){
        cout<< arr[i]<< " ";
    }
    return 0;
}
