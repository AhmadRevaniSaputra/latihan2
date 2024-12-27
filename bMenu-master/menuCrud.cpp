#include <iostream>
#include <string>
#include <limits> // untuk numeric_limits
using namespace std;

struct mahasiswa {
@@ -12,50 +13,84 @@ struct mahasiswa {
mahasiswa sikc[30];
int pos = -1;

void tampilkanData(int p) {
    cout << sikc[p].nim << " , " << sikc[p].nama << " , " << sikc[p].alamat << " , " << sikc[p].ipk << endl;
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
    system("cls");
    fflush(stdin);
    cout << "masukan nim: ";
    clearScreen();
    cout << "Masukan NIM: ";
    getline(cin, sikc[pos].nim);
    cout << "masukan nama: ";
    cout << "Masukan Nama: ";
    getline(cin, sikc[pos].nama);
    cout << "masukan alamat: ";
    cout << "Masukan Alamat: ";
    getline(cin, sikc[pos].alamat);
    cout << "masukan ipk: ";
    cout << "Masukan IPK: ";
    cin >> sikc[pos].ipk;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer
    cout << "Data berhasil ditambahkan!\n";
}

void perbaikanData(int p) {
    system("cls");
    fflush(stdin);
    cout << "masukan nama: ";
    getline(cin, sikc[p].nama);
    cout << "masukan alamat: ";
    getline(cin, sikc[p].alamat);
    cout << "masukan ipk: ";
    cin >> sikc[p].ipk;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

int main() {
    // ujicoba memasukan data di array index pertama
    masukanData();
    // ujicoba memasukan data di array index kedua
    masukanData();
    // ujicoba tampilkan data terakhir input
    tampilkanData(pos);
    // ujicoba tampilkan data pada array pertama
    tampilkanData(0);
    // ujicoba merubah data pada array pertama
    perbaikanData(0);
    // ujicoba merubah data pada array kedua
    tampilkanData(0);
    int pilihan;
    do {
        clearScreen();
        cout << "Menu Crud :\n";
        cout << "1. Masukkan Data\n";
        cout << "2. Masukkan Banyak Data\n";
        cout << "3. Keluar\n";
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
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
        if (pilihan != 3) {
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.get();
        }
    } while (pilihan != 3);
    return 0;
}