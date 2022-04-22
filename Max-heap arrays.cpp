//*****************************************************
//Noah Stern
//CS 355
//Assignment 13
//11/08/20
//Heaps
//*****************************************************

#include <iostream> 
using namespace std; 

//***************************************************
//Name: heapify
//Purpose: To heapify a subtree rooted with node i
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************
void heapify(int arr[], int n, int i) 
{ 
    int largest = i;
    int l = 2*i + 1;  
    int r = 2*i + 2; 
   
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
   
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
   
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
//***************************************************
//Name: heap sort
//Purpose: sort the heap in ascending order
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//*************************************************** 
void heapSort(int arr[], int n) 
{  
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>0; i--) 
    { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
} 
//***************************************************
//Name: displayArray
//Purpose: Display the array on one line
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************  
void displayArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
//***************************************************
//Name: buildHeap
//Purpose: to build a Max-Heap from the given array 
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************
void buildHeap(int arr[], int n) 
{  
    int startIdx = (n / 2) - 1; 
    for (int i = startIdx; i >= 0; i--) 
	{ 
        heapify(arr, n, i); 
    } 
} 
//***************************************************
//Name: printHeap
//Purpose: To print the array representation of the heap
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************
void printHeap(int arr[], int n) 
{ 
    cout << "Array representation of Heap is:\n"; 
	for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
}
//***************************************************
//Name: heapDeque
//Purpose: delete the root from Heap 
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************
void heapDeque(int arr[], int& n) 
{  
    int lastElement = arr[n - 1]; 
    arr[0] = lastElement;  
    n = n - 1; 
    heapify(arr, n, 0); 
} 
//***************************************************
//Name: heapEnque
//Purpose: insert a new node to the Heap 
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************
void heapEnque(int arr[], int& n, int Key) 
{ 
    n = n + 1; 
    arr[n - 1] = Key; 
    heapify(arr, n, n - 1); 
} 
  
// Driver program 
int main() 
{ 
    int arr[] = {1, 54, 9, 23, 35, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    displayArray(arr, n); 
	
	buildHeap(arr, n);
	printHeap(arr, n);
	
	heapDeque(arr, n);
	printHeap(arr, n);
	
	heapEnque(arr, n, 23);
	printHeap(arr, n);
} 
