/*
Problem: Selection Sort Algorithm
Difficulty: Easy

Approach:
1. Scan the array to find smallest element 
2. Place the smallest element at the beginning 

Time Complexity: O(n^2)
Space Complexity: O(n)

Date Solved: 2026-05-30
*/



#include <iostream>
using namespace std;
void selection_sort(int arr[], int n){
  for (int i=0; i<=n-2; i++){
    int min= i;
    for (int j=i; j<=n-1; j++){
    if (arr[j]<arr[min]){
    min=j;
  }
}
      int temp= arr[min];
      arr[min]=arr[i];
      arr[i]= temp;
}
}

int main(){
  int n; 
  cin >> n;
  int arr[n]
  for (int i=0; i<n; i++){
    cin >> arr[n];
  }
  selection_sort(arr, n);
  for (int i=0; i<n; i++){
    cout<< arr[i]<< " ";
  }

  return 0;
}
