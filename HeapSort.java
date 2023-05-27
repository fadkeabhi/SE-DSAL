class HeapSort{
    public static void heapSort(int[] arr) {
        int n = arr.length;
  
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
  
        // Heap sort
        for (int i = n - 1; i >= 0; i--) {
            // Swap root with current element
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
  
            // Heapify the reduced heap
            heapify(arr, i, 0);
        }
    }
  
    public static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
  
        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;
  
        // If right child is larger than the largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;
  
        // If the largest is not the root
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
  
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    public static void main(String[] args){
        int[] arr1 = {9, 2, 7, 5, 4, 1, 6, 8, 3};
  
        System.out.println("Original array:");
        printArray(arr1);
  
        heapSort(arr1);
        System.out.println("\nArray sorted using Heap Sort:");
        printArray(arr1);

    }

    public static void printArray(int[] arr) {
        for (int num : arr)
            System.out.print(num + " ");
        System.out.println();
    }

}