/*
Problem: Merge Sort Algorithm
Difficulty: Easy

Approach:
1. Divide the initial array into two
2. Keep dividing each array until you get singular elements 
3. Merge the singular elements to get sorted arrays at each step

Time Complexity: O(n log n)
Space Complexity: O(1)

Date Solved: 2026-06-03
*/



#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int left= low;
    int right= mid+1;
    vector <int> temp;
    while(left<=mid && right<=high){
        if (arr[left]>arr[right]){
            temp.push_back(arr[right]);
            right++;
        }
        else {
            temp.push_back(arr[left]);
            left++;
        }
    }
    while (left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while (right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for (int i= low; i<=high; i++){
        arr[i]= temp[i-low];
    }
    
}
void merge_sort(int arr[], int low, int high){
    if (low==high)return;
    int mid= (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main() {
    int n;
    cin>> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    merge_sort(arr, 0, n-1);
    for (int i=0; i<n; i++){
        cout<< arr[i]<< endl;
    }
    return 0;
   
}
