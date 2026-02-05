#include<bits/stdc++.h>
using namespace std; 

// PARTITION: Rearranges array so pivot is in correct position
// Returns the final index of pivot
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];  // Choose first element as pivot
    int i = low;           // Left pointer starts at beginning
    int j = high;          // Right pointer starts at end
    
    // Move i and j towards each other until they cross
    while(i < j) {
        
        // Move i right until we find element > pivot
        // Stop before going out of bounds (i <= high-1)
        while(arr[i] <= pivot && i <= high - 1) {
            i++; 
        }
        
        // Move j left until we find element <= pivot
        // Stop before going out of bounds (j >= low+1)
        while(arr[j] > pivot && j >= low + 1) {
            j--; 
        } 
        
        // If i and j haven't crossed, swap the elements
        // This puts smaller element on left, bigger on right
        if(i < j) {
            swap(arr[i], arr[j]);  
        }
    }
    
    // i and j have crossed - put pivot in its correct position
    // Swap pivot with element at j (j is now at correct position for pivot)
    swap(arr[low], arr[j]);
    
    // Return pivot's final position
    return j;
}

// QUICKSORT: Recursively sorts the array
void qS(vector<int> &arr, int low, int high) {
    // Base case: if segment has 1 or 0 elements, it's already sorted
    if(low < high) {
        
        // Partition: place pivot in correct position
        // Get the index where pivot ended up
        int pIndex = partition(arr, low, high);
        
        // Recursively sort LEFT side (elements before pivot)
        qS(arr, low, pIndex - 1);
        
        // Recursively sort RIGHT side (elements after pivot)
        qS(arr, pIndex + 1, high);
    }
}

int main() { 
    int n; 
    cin >> n;
    
    // Create vector of size n
    vector<int> arr(n);
    
    // Read n elements
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Call quicksort on entire array (from index 0 to n-1)
    qS(arr, 0, n - 1);
    
    // Print sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;
    
    return 0;  
}