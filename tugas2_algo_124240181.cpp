#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Pesanan {
    string nama;
    string jenis_roti;
    double total_harga;
};

// Antrean pesanan
queue<Pesanan> antrean;

// History pesanan dilayani (maksimal 100)
Pesanan riwayat[100];
int jumlahRiwayat = 0;

void ambilAntrean() {
    Pesanan p;
    cout << "\n--- Ambil Antrean ---\n";
    cout << "Nama Pembeli     : ";
    getline(cin, p.nama);
    cout << "Jenis Roti       : ";
    getline(cin, p.jenis_roti);
    cout << "Total Harga (Rp) : ";
    cin >> p.total_harga;
    cin.ignore();  // bersihkan newline

    antrean.push(p);
    cout << "Pesanan berhasil ditambahkan ke antrean.\n";
}

void layaniPembeli() {
    if (antrean.empty()) {
        cout << "Tidak ada pesanan dalam antrean.\n";
        return;
    }

    Pesanan p = antrean.front();
    antrean.pop();

    if (jumlahRiwayat < 100) {
        riwayat[jumlahRiwayat++] = p; // Simpan ke riwayat
    } else {
        cout << "Riwayat sudah penuh. Tidak bisa menyimpan lebih banyak data.\n";
    }

    cout << "\n--- Pesanan Dilayani ---\n";
    cout << "Nama     : " << p.nama << endl;
    cout << "Roti     : " << p.jenis_roti << endl;
    cout << "Total Rp : " << p.total_harga << endl;
}

void tampilkanPesanan() {
    if (antrean.empty()) {
        cout << "Antrean kosong.\n";
        return;
    }

    cout << "\n--- Daftar Pesanan dalam Antrean ---\n";
    queue<Pesanan> temp = antrean;
    int nomor = 1;
    while (!temp.empty()) {
        Pesanan p = temp.front();
        temp.pop();
        cout << nomor++ << ". " << p.nama << " - " << p.jenis_roti << " - Rp" << p.total_harga << endl;
    }
}

void batalkanPesanan() {
    if (antrean.empty()) {
        cout << "Tidak ada pesanan untuk dibatalkan.\n";
        return;
    }

    queue<Pesanan> temp;
    while (antrean.size() > 1) {
        temp.push(antrean.front());
        antrean.pop();
    }
    Pesanan dibatalkan = antrean.front();
    antrean.pop();
    antrean = temp;

    cout << "\nPesanan terakhir dari " << dibatalkan.nama << " telah dibatalkan.\n";
}

void tampilkanHistory() {
    if (jumlahRiwayat == 0) {
        cout << "Belum ada pesanan yang dilayani.\n";
        return;
    }

    cout << "\n--- Riwayat Pesanan yang Sudah Dilayani ---\n";
    for (int i = 0; i < jumlahRiwayat; ++i) {
        cout << i + 1 << ". " << riwayat[i].nama << " - " << riwayat[i].jenis_roti
             << " - Rp" << riwayat[i].total_harga << endl;
    }
}

int main() {
    int pilihan;
    do {
        cout << "\n=== Sistem Antrean Toko Roti Manis Lezat ===\n";
        cout << "1. Ambil Antrean\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Tampilkan Pesanan\n";
        cout << "4. Batalkan Pesanan Terakhir\n";
        cout << "5. Tampilkan History Pesanan\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore(); // bersihkan newline

        switch (pilihan) {
            case 1: ambilAntrean(); break;
            case 2: layaniPembeli(); break;
            case 3: tampilkanPesanan(); break;
            case 4: batalkanPesanan(); break;
            case 5: tampilkanHistory(); break;
            case 0: cout << "Terima kasih. Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
