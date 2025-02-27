#include <iostream>
using namespace std;

struct Book
{
    string title;
    int price;
};

int main()
{
    Book book[5] = {
        {"Si Kancil dan Buaya", 15000},
        {"Jogja dan kota", 16000},
        {"Rito dan Gara", 17000},
        {"Memakan monas", 18000},
        {"Laptop ajaib", 19000},
    };

    string cari_judul;
    int cari_harga;
    int menu;
    int first = 0;
    int last = 5;
    int mid;
    bool search_harga = false;
    int i = 0;
    bool search_judul = false;
    cout << "Pilih menu : \n1. cari judul\n2. cari harga\npilih= ";
    cin >> menu;

    switch (menu)
    {
    case 1:
        cout << "Cari = ";
        cin.ignore();
        getline(cin, cari_judul);

        while (!search_judul && i < 5)
        {
            if (book[i].title == cari_judul)
            {
                cout << "Harga = " << book[i].price << endl;
                search_judul = true;
            }
            i++;
        }
        if (!search_judul)
        {
            cout << "Buku tidak ditemukan";
        }
        break;
    case 2:
        cout << "Cari = ";
        cin >> cari_harga;
        while (!search_harga && first <= last)
        {
            mid = (first + last) / 2;

            if (book[mid].price == cari_harga)
            {
                cout << "Judul Buku = " << book[mid].title;
            }
            else
            {
                if (book[mid].price >= cari_harga)
                {
                    last = mid - 1;
                }
                else
                {
                    first = mid + 1;
                }
            }
        }
        if (!search_harga)
        {
            cout << "Buku tidak ditemukan";
        }
        break;
    default:
        cout << "Menu tidak valid";
        break;
    }
    return 0;
}
