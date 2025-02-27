#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;

    // print
    for (int i = 0; i < 5; i++)
    {
        cout << *(p + i) << endl;
    }
    
    // min max
    int nilaiSebelum, min, max;
    for (int i = 0; i < 5; i++)
    {
        if (nilaiSebelum < *(p + i)) {
            nilaiSebelum = *(p + i);
        } else {
            min = *(p + i);
        }
        if (nilaiSebelum > *(p + i)) {
            nilaiSebelum = *(p + i);
        } else {
            max = *(p + i);
        }
    }

    cout << "Min: " << min;
    cout << "max: " << max;


    int avg, sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum += *(p + i);
    }
    avg = sum/5;

    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;
    return 0;
}