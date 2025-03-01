#include <iostream>
#include <utility>

int main()
{
    int randomArr[] = {3, 2, 5, 4, 1, 7, 8, 6, 9, 10};
    int n = sizeof(randomArr) / sizeof(randomArr[0]);

    for (int i = 0; i < n; i++)
    {
        std::cout << randomArr[i] << " ";
    }
}