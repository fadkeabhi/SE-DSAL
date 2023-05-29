#include <iostream>
using namespace std;

// Heapify a subtree rooted at index 'root' in the 'size' array
void heapify(int arr[], int size, int root)
{
    int largest = root;       // Initialize the largest as root
    int left = 2 * root + 1;  // Left child
    int right = 2 * root + 2; // Right child

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root
    if (largest != root)
    {
        swap(arr[root], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

// Main function to perform heap sort
void heapSort(int arr[], int size)
{
    // Build a max-heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // Extract elements one by one from the heap
    for (int i = size - 1; i >= 0; i--)
    {
        // Move the current root to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Print an array of size 'size'
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    heapSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
