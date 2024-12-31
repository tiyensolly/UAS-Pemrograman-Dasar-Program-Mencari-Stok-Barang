#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Struktur data untuk menyimpan informasi barang
struct Item {
    string name;
    int quantity;
    string location;
};

// Kelas untuk sistem gudang
class Warehouse {
private:
    unordered_map<string, Item> inventory; // Penyimpanan barang menggunakan map

public:
    // Tambahkan barang ke gudang
    void addItem(const string& itemID, const string& name, int quantity, const string& location) {
        if (inventory.find(itemID) != inventory.end()) {
            inventory[itemID].quantity += quantity;
            cout << "Barang " << name << " berhasil ditambahkan. Stok sekarang: " << inventory[itemID].quantity << endl;
        } else {
            inventory[itemID] = {name, quantity, location};
            cout << "Barang " << name << " berhasil ditambahkan ke lokasi " << location << "." << endl;
        }
    }

    // Cari stok barang berdasarkan ID
    void findItem(const string& itemID) {
        if (inventory.find(itemID) != inventory.end()) {
            const Item& item = inventory[itemID];
            cout << "ID: " << itemID 
                 << " | Nama: " << item.name 
                 << " | Stok: " << item.quantity 
                 << " | Lokasi: " << item.location << endl;
        } else {
            cout << "Barang dengan ID " << itemID << " tidak ditemukan." << endl;
        }
    }

    // Lihat semua stok barang
    void checkAllStock() {
        if (inventory.empty()) {
            cout << "Gudang kosong." << endl;
        } else {
            cout << "\n--- Daftar Stok Gudang ---" << endl;
            for (const auto& item : inventory) {
                cout << "ID: " << item.first 
                     << " | Nama: " << item.second.name 
                     << " | Stok: " << item.second.quantity 
                     << " | Lokasi: " << item.second.location << endl;
            }
        }
    }
};

// Fungsi utama
int main() {
    Warehouse warehouse;
    string itemID, name, location;
    int choice, quantity;

    do {
        cout << "\n=== Sistem Gudang ===" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Cari Barang" << endl;
        cout << "3. Lihat Semua Stok" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Masukkan ID Barang: ";
            cin >> itemID;
            cout << "Masukkan Nama Barang: ";
            cin.ignore(); // Membersihkan buffer input
            getline(cin, name);
            cout << "Masukkan Jumlah Stok: ";
            cin >> quantity;
            cout << "Masukkan Lokasi Barang: ";
            cin >> location;
            warehouse.addItem(itemID, name, quantity, location);
            break;
        case 2:
            cout << "Masukkan ID Barang yang Dicari: ";
            cin >> itemID;
            warehouse.findItem(itemID);
            break;
        case 3:
            warehouse.checkAllStock();
            break;
        case 4:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (choice != 4);

    return 0;
}
