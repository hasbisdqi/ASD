#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

struct Song
{
    char title[100], artist[50], genre[12];
    int year;
};

const int MAX_SONGS = 100;

int readSongs(const string &filename, Song songs[])
{
    FILE *file = fopen(filename.c_str(), "rb");
    if (!file)
        return 0;

    int count = 0;
    while (count < MAX_SONGS && fread(&songs[count], sizeof(Song), 1, file))
    {
        count++;
    }
    fclose(file);
    return count;
}

void writeSongs(const string &filename, Song songs[], int count)
{
    FILE *file = fopen(filename.c_str(), "wb");
    if (!file)
        return;

    fwrite(songs, sizeof(Song), count, file);
    fclose(file);
}

void createSong(string filename)
{
    Song songs[MAX_SONGS];
    int count = readSongs(filename, songs);

    if (count >= MAX_SONGS)
    {
        cout << "Database penuh!";
        return;
    }

    Song &song = songs[count];
    cout << "\nMasukkan Judul : ";
    cin.ignore();
    cin.getline(song.title, 100);
    cout << "Masukkan Artis : ";
    cin.getline(song.artist, 50);
    cout << "Masukkan Genre : ";
    cin.getline(song.genre, 12);
    cout << "Masukkan Tahun : ";
    cin >> song.year;
    cin.ignore();

    count++;
    writeSongs(filename, songs, count);
    cout << "Berhasil ditambah!";
}

void showSongs(string filename)
{
    Song songs[MAX_SONGS];
    int count = readSongs(filename, songs);
    if (count == 0)
    {
        cout << "Tidak ada lagu dalam database.\n";
        return;
    }
    for (int i = 0; i < count; i++)
    {
        cout << "\nJudul  : " << songs[i].title;
        cout << "\nArtis  : " << songs[i].artist;
        cout << "\nGenre  : " << songs[i].genre;
        cout << "\nTahun  : " << songs[i].year << "\n";
    }
}

void searchSong(string filename)
{
    Song songs[MAX_SONGS];
    int count = readSongs(filename, songs);
    if (count == 0)
    {
        cout << "Database kosong!\n";
        return;
    }

    char title[100];
    cout << "Masukkan judul lagu yang ingin dicari: ";
    cin.ignore();
    cin.getline(title, 100);

    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(title, songs[i].title) == 0)
        {
            cout << "\nLagu ditemukan!\n";
            cout << "Judul  : " << songs[i].title << "\n";
            cout << "Artis  : " << songs[i].artist << "\n";
            cout << "Genre  : " << songs[i].genre << "\n";
            cout << "Tahun  : " << songs[i].year << "\n";
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Lagu \"" << title << "\" tidak ditemukan dalam database.\n";
}

void editSong(string filename)
{
    Song songs[MAX_SONGS];
    int count = readSongs(filename, songs);
    if (count == 0)
    {
        cout << "Database kosong!\n";
        return;
    }

    char title[100];
    cout << "Masukkan judul lagu yang akan diedit: ";
    cin.ignore();
    cin.getline(title, 100);

    bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(title, songs[i].title) == 0)
        {
            cout << "Lagu ditemukan! Masukkan data baru.\n";
            cout << "Judul Baru     : ";
            cin.getline(songs[i].title, 100);
            cout << "Artis Baru     : ";
            cin.getline(songs[i].artist, 50);
            cout << "Genre Baru     : ";
            cin.getline(songs[i].genre, 12);
            cout << "Tahun Rilis Baru: ";
            cin >> songs[i].year;
            cin.ignore();
            found = true;
            break;
        }
    }
    if (found)
    {
        writeSongs(filename, songs, count);
        cout << "Lagu berhasil diperbarui!\n";
    }
    else
    {
        cout << "Lagu \"" << title << "\" tidak ditemukan.\n";
    }
}

int main()
{
    string filename = "songs.dat";
    int choice;
    do
    {
        cout << "\n Playlist Lagu\n";
        cout << "=====================\n";
        cout << "1. Tambah Lagu\n2. Edit Lagu\n3. Tampilkan Lagu\n4. Cari Lagu\n5. Keluar\n Pilih Menu: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            createSong(filename);
            break;
        case 2:
            editSong(filename);
            break;
        case 3:
            showSongs(filename);
            break;
        case 4:
            searchSong(filename);
            break;
        case 5:
            cout << "Keluar dari program...";
            break;
        default:
            cout << "Pilihan tidak valid!";
        }
    } while (choice != 5);
}
