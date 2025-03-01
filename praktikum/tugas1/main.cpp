#include <iostream>
#include <vector>
using namespace std;

struct song
{
    string title;
    string artist;
    string genre;
    int year;
};

void menu(vector<song> &songs);
void addSong(vector<song> &songs)
{
    cout << "Masukkan jumlah lagu yang ingin ditambahkan: ";
    int jumlah;
    cin >> jumlah;
    cin.ignore();
    cout << "\n";

    for (int i = 0; i < jumlah; i++)
    {
        song newSong;
        cout << "Judul: ";
        getline(cin, newSong.title);
        cout << "Artis: ";
        getline(cin, newSong.artist);
        cout << "Genre: ";
        getline(cin, newSong.genre);
        cout << "Tahun: ";
        cin >> newSong.year;
        cin.ignore();

        songs.push_back(newSong);
    }
    cout << "\n";
}

void searchSong(vector<song> &songs)
{
    string keyword;
    bool founded = false;
    cout << "Masukkan judul lagu yang ingin dicari: ";
    cin.ignore();
    getline(cin, keyword);

    for (const auto &s : songs)
    {
        if (s.title == keyword)
        {
            cout << "Lagu ditemukan" << endl;
            cout << "Judul: " << s.title << endl;
            cout << "Artis: " << s.artist << endl;
            cout << "Genre: " << s.genre << endl;
            cout << "Tahun: " << s.year << endl;
            founded = true;
            break;
        }
    }
    if (!founded)
    {
        cout << "Lagu tidak ditemukan" << endl;
    }

    cout << endl
         << "Kembali ke menu? (y/n): ";
    char back;
    cin >> back;
    if (back == 'y' || back == 'Y')
    {
        menu(songs);
    }
    else
    {
        cout << "Terima kasih" << endl;
    }
}

void menu(vector<song> &songs)
{
    int menu;
    do
    {
        cout << "   Playlist Lagu" << endl;
        cout << "====================" << "\n\n";
        for (size_t i = 0; i < songs.size(); i++)
        {
            cout << i + 1 << ". " << songs[i].title << " - " << songs[i].artist << "\n\n";
        }

        cout << "1. Tambah Lagu" << endl;
        cout << "2. Cari Lagu" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cout << "Tambah Lagu" << endl;
            addSong(songs);
            break;
        case 2:
            cout << "Cari Lagu" << endl;
            searchSong(songs);
            break;
        case 3:
            cout << "Keluar" << endl;
            break;
        default:
            cout << "Menu tidak tersedia" << endl;
            break;
        }
    } while (menu != 3);
}

int main()
{
    vector<song> songs;
    menu(songs);
    return 0;
}
