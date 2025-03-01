#include <iostream>
#include <utility>
using namespace std;
void quickSort(string arr[], int low, int high)
{
    int awal = low;
    int akhir = high;
    string pivot = arr[(awal + akhir) / 2];
    do
    {
        while (arr[awal] < pivot)
        {
            awal++;
        }
        while (arr[akhir] > pivot)
        {
            akhir--;
        }
        if (awal <= akhir)
        {
            swap(arr[awal], arr[akhir]);
            awal++;
            akhir--;
        }
    } while (awal <= akhir);
    if (low < akhir)
    {
        quickSort(arr, low, akhir);
    }
    if (awal < high)
    {
        quickSort(arr, awal, high);
    }
}
void bubbleSort(string arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main()
{
    string randomArr[] = {"3", "2", "5", "4", "1", "7", "8", "6", "9", "10"};
    int n = sizeof(randomArr) / sizeof(randomArr[0]);
    for (int k = 0; k < n; k++)
    {
        cout << randomArr[k] << " ";
    }
    cout << endl;
    quickSort(randomArr, 0, n - 1);
    for (int k = 0; k < n; k++)
    {
        cout << randomArr[k] << " ";
    }
    cout << endl;
    bubbleSort(randomArr, n);
    for (int k = 0; k < n; k++)
    {
        cout << randomArr[k] << " ";
    }
}