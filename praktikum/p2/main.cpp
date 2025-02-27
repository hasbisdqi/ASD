#include <iostream>
using namespace std;
#define MAX 30

int unsentinel(int arr[MAX], int data)
{
    int i = 0;
    arr[MAX] = data;
    bool search = false;

    while (!search && i < MAX)
    {
        if (arr[i] == data)
        {
            // cout << "Data ditemukan pada indeks ke-" << i << endl;
            search = true;
            return i;
        }
        i++;
    }
    if (!search)
    {
        return -1;
    }
    return -1;
}

int sentinel(int arr[MAX], int data)
{
    bool search = false;
    int i = 0;
    arr[MAX] = data;
    while (!search)
    {
        if (arr[i] == data)
        {
            // cout << "Data ditemukan pada indeks ke-" << i << endl;
            search = true;
            if (i < MAX)
            {
                return i;
            }
            else
            {
                return -1;
            }
        }
        i++;
    }
    return -1;
}
int binary(int arr[], int w)
{
    int first = 0;
    int last = MAX;
    int mid;
    bool search = false;

    while (!search && first <= last)
    {
        mid = (first + last) / 2;

        if (arr[mid] == w)
        {
            return mid;
        }
        else
        {
            if (arr[mid] >= w)
            {
                last = mid - 1;
            }
            else
            {
                first = mid + 1;
            }
        }
    }

    return -1;
}
int main()
{
    int arr[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int wanted = 32;
    cout << binary(arr, 8);
    // int index_s = sentinel(arr, 7);
    // int index_u = unsentinel(arr, 8);
    // cout << "Data S ditemukan pada indeks ke-" << index_s << endl;
    // cout << "Data ditemukan pada indeks ke-" << index_u << endl;
    return 0;
}
