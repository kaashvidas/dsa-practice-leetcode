/*
Problem: Bubble Sorting Algorithm 
Difficulty: Easy

Approach:
1. Check if two consecutive elements are sorted 
2. Swap if not sorted 
3.  Automatically places the max element at the end 

Time Complexity: O(n^2)- Average Case, O{n}- Best Case
Space Complexity: O(n)

Date Solved: 2026-05-30
*/
#include <iostream>
using namespace std;
void bubble_sort(int arr[], int n){
  int did_swap=0;
    for (int i= n-1; i>=1; i++){
        for (int j=0; j<=i-1; j++){
            if (arr[j]>arr[j+1]){
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]= temp;
                did_swap=1;
            }
        }
      if (did_swap==0){
      break;
    }
}
int main() {
   int n;
   cin>>n;
   int arr[n];
   for (int i=0; i<n; i++){
       cin >> arr[i];
   }
   
   bubble_sort(arr, n);
   
   for (int i=0; i<n; i++){
       cout<< arr[i]<< " ";
   }
    return 0;
}
