#include "MaxHeap.h"
using namespace std;

int altmain() {
  const int size = 5;
  int numbers[size] = { 10, 2, 5, 18, 22 };
  MaxHeap maxHeap(numbers, size); // add code to MaxHeap.h
  cout << maxHeap << endl; // output like [22, 18, 5, 2, 10]
  return 0;
}

int main() {
//    MaxHeap maxHeap;
//    int numbers[] = { 10, 2, 5, 18, 22 };
      
//    // Add all numbers to the heap
//    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
//       maxHeap.Insert(numbers[i]);
//       cout << "   --> array: " << maxHeap.GetHeapArrayString() << endl;
//    }
      
//    while (maxHeap.GetHeapSize() > 0) {
//       int removedValue = maxHeap.Remove();
//       cout << "   --> removed " << removedValue << ", array: ";
//       cout << maxHeap.GetHeapArrayString() << endl;
//    }
    return altmain();
}

