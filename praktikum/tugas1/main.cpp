#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct song
{
    string title;
    string artist;
    string genre;
    int year;
};

int menu(song songs[], int &n, int capacity);
void addSong(song songs[], int &n, int capacity)
{
    cout << "Masukkan jumlah lagu yang ingin ditambahkan: ";
    int jumlah;
    cin >> jumlah;
    cin.ignore();
    cout << "\n";

    if (n + jumlah > capacity)
    {
        cout << "Jumlah lagu melebihi kapasitas. Maksimum lagu yang bisa ditambahkan: " << capacity - n << "\n\n";
        return;
    }

    for (int i = n; i < jumlah + n; i++)
    {
        cout << "Judul: ";
        getline(cin, songs[i].title);
        cout << "Artis: ";
        getline(cin, songs[i].artist);
        cout << "Genre: ";
        getline(cin, songs[i].genre);
        cout << "Tahun: ";
        cin >> songs[i].year;
        cin.ignore();
        cout << "\n";
    }
    n += jumlah;
    cout << "\n";
}

void searchSong(song songs[], int n)
{
    string keyword;
    bool founded = false;
    cout << "Masukkan judul lagu yang ingin dicari: ";
    cin.ignore();
    getline(cin, keyword);

    for (int i = 0; i < n; i++)
    {
        if (songs[i].title == keyword)
        {
            cout << "Lagu ditemukan" << endl;
            cout << "Judul: " << songs[i].title << endl;
            cout << "Artis: " << songs[i].artist << endl;
            cout << "Genre: " << songs[i].genre << endl;
            cout << "Tahun: " << songs[i].year << endl;
            founded = true;
            break;
        }
    }
    if (!founded)
    {
        cout << "Lagu tidak ditemukan" << endl;
    }
}

int menu(song songs[], int &n, int capacity)
{
    int menu;
    cout << "   Playlist Lagu" << endl;
    cout << "====================" << "\n\n";

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (songs[j].title > songs[j + 1].title)
            {
                swap(songs[j], songs[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << songs[i].title << " - " << songs[i].artist << "\n\n";
    }

    cout << "1. Tambah Lagu" << endl;
    cout << "2. Cari Lagu" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> menu;
    cout << "\n";
    return menu;
}

int main()
{
    const int capacity = 10;
    song songs[capacity];
    int n = 0; // Jumlah lagu saat ini
    int choice;
    int pilih;
    do
    {
        choice = menu(songs, n, capacity);
        switch (choice)
        {
        case 1:
            cout << "Tambah Lagu" << endl;
            addSong(songs, n, capacity);
            break;
        case 2:
            cout << "Cari Lagu" << endl;
            searchSong(songs, n);
            while (pilih != 1)
            {
                cout << "1. Kembali" << endl;
                cout << "Pilih menu: ";
                cin >> pilih;
                cout << "\n";
                if (pilih == 1)
                {
                    #if defined(_WIN32) || defined(_WIN64)
                                        system("CLS");
                    #else
                                        system("clear");
                    #endif
                    pilih = 0;
                    break;
                }
            }

            break;
        case 3:
            cout << "Keluar" << endl;
            break;
        default:
            cout << "Menu tidak tersedia" << endl;
            break;
        }
    } while (choice != 3);

    return 0;
}
