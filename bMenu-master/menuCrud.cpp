#include <iostream>
#include <string>
#include <limits> // untuk numeric_limits
using namespace std;

struct mahasiswa {
    string nim;
    string nama;
    string alamat;
    float ipk;
};

mahasiswa sikc[30];
int pos = -1;

// Fungsi untuk membersihkan layar (cross-platform)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Fungsi untuk memasukkan satu data mahasiswa
void masukanData() {
    if (pos >= 29) { // Membatasi jumlah maksimal data
        cout << "Data penuh! Tidak bisa menambahkan data baru.\n";
        return;
    }
    pos++;
    clearScreen();
    cout << "Masukan NIM: ";
    getline(cin, sikc[pos].nim);
    cout << "Masukan Nama: ";
    getline(cin, sikc[pos].nama);
    cout << "Masukan Alamat: ";
    getline(cin, sikc[pos].alamat);
    cout << "Masukan IPK: ";
    cin >> sikc[pos].ipk;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer
    cout << "Data berhasil ditambahkan!\n";
}

// Fungsi untuk memasukkan banyak data mahasiswa
void masukanBanyakData() {
    int jumlah;
    cout << "Masukan jumlah data yang ingin ditambahkan: ";
    cin >> jumlah;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer

    for (int i = 0; i < jumlah; i++) {
        if (pos >= 29) { // Membatasi jumlah maksimal data
            cout << "Data penuh! Tidak bisa menambahkan lebih banyak data.\n";
            return;
        }
        cout << "\nData ke-" << i + 1 << ":\n";
        masukanData();
    }
}

// Fungsi untuk menampilkan semua data mahasiswa
void tampilkanSemuaData() {
    clearScreen();
    if (pos == -1) { // Jika tidak ada data
        cout << "Belum ada data yang dimasukkan.\n";
        return;
    }
    cout << "Data Mahasiswa:\n";
    cout << "------------------------------------\n";
    for (int i = 0; i <= pos; i++) {
        cout << "Data ke-" << i + 1 << ":\n";
        cout << "NIM     : " << sikc[i].nim << endl;
        cout << "Nama    : " << sikc[i].nama << endl;
        cout << "Alamat  : " << sikc[i].alamat << endl;
        cout << "IPK     : " << sikc[i].ipk << endl;
        cout << "------------------------------------\n";
    }
}
int main() {
    int pilihan;
    do {
        clearScreen();
        cout << "Menu Crud :\n";
        cout << "1. Masukkan Data\n";
        cout << "2. Masukkan Banyak Data\n";
        cout << "3. Keluar\n";
        cout << "3. Tampilkan Semua Data\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer

        switch (pilihan) {
        case 1:
            masukanData();
            break;
        case 2:
            masukanBanyakData();
            break;
        case 3:
            tampilkanSemuaData();
            break;
        case 4:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }

        if (pilihan != 3) {
        if (pilihan != 4) {
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.get();
        }
    } while (pilihan != 3);
    } while (pilihan != 4);

    return 0;
}