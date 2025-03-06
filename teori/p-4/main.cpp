#include <iostream>
#include <utility> // Include the algorithm header for swap()
using namespace std;

void shellSort(char arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                swap(arr[j], arr[j - gap]); // Use swap() function
            }
        }
    }
}

void printArray(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    char arr[] = {'n', 'b', 't', 'a', 'e'};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array sebelum diurutkan: \n";
    printArray(arr, n);
    shellSort(arr, n);
    cout << "Array setelah diurutkan: \n";
    printArray(arr, n);
    return 0;
}