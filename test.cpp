#include <iostream>
using namespace std;

int main() {
    cout << "Tes ANSI Escape Code\n";
    cout << "\033[31mTeks ini berwarna merah\033[0m\n";
    cout << "\033[32mTeks ini berwarna hijau\033[0m\n";
    cout << "\033[2J\033[H"; // Clear screen dengan ANSI
    cout << "Jika layar bersih, terminal mendukung ANSI Escape Code!\n";
    return 0;
}
