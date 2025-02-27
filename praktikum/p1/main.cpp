#include <iostream>
using namespace std;

void func(int *a, int *b)
{
    *b = *a + *b;
}
int main()
{
    // int *p, *x, *s;
    // int n = 10;
    // p = &n;
    // cout << "n = " << n << endl;
    // *p=5;
    // cout << "n = " << n << endl;
    // cout << "p = " << *p << endl;

    // int arr[3] = {1, 2, 3};
    // for (int i = 0; i < 3; i++)
    // cout << *arr+i << endl;

    int a = 5, b = 6;
    char kota[] = "Yogyakarta Halo";
    cout << kota << endl;
    char *i = kota;
    for (; *i != '\0'; i++)
        cout << *i << endl;

    cout << "a = " << a << " b = " << b << endl;
    func(&a, &b);
    cout << "a = " << a << " b = " << b << endl;

    return 0;
}
