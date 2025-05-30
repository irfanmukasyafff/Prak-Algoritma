#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Lagu {
    string judul;
    string penyanyi;
    string album;
};

Lagu daftarLagu[100];
int jumlahLagu = 0;

queue<Lagu> antrianLagu;
stack<Lagu> riwayatHapus;

void tambahLagu() {
    if (jumlahLagu >= 100) {
        cout << "Daftar lagu penuh.\n";
        return;
    }
    Lagu lagu;
    cout << "Judul: ";
    getline(cin >> ws, lagu.judul);
    cout << "Penyanyi: ";
    getline(cin, lagu.penyanyi);
    cout << "Album: ";
    getline(cin, lagu.album);
    daftarLagu[jumlahLagu++] = lagu;
    cout << "Lagu berhasil ditambahkan.\n";
}

void cariLagu() {
    string judul;
    cout << "Masukkan judul yang dicari: ";
    getline(cin >> ws, judul);
    for (int i = 0; i < jumlahLagu; i++) {
        if (daftarLagu[i].judul == judul) {
            cout << "Judul: " << daftarLagu[i].judul << "\nPenyanyi: " << daftarLagu[i].penyanyi
                 << "\nAlbum: " << daftarLagu[i].album << endl;
            return;
        }
    }
    cout << "Lagu tidak ditemukan.\n";
}

void tampilkanDaftarLagu() {
    if (jumlahLagu == 0) {
        cout << "Tidak ada lagu dalam daftar.\n";
        return;
    }

    for (int i = 0; i < jumlahLagu - 1; i++) {
        for (int j = 0; j < jumlahLagu - i - 1; j++) {
            if (daftarLagu[j].judul > daftarLagu[j + 1].judul) {
                Lagu temp = daftarLagu[j];
                daftarLagu[j] = daftarLagu[j + 1];
                daftarLagu[j + 1] = temp;
            }
        }
    }

    cout << "Daftar Lagu:\n";
    for (int i = 0; i < jumlahLagu; i++) {
        cout << "- " << daftarLagu[i].judul << " oleh " << daftarLagu[i].penyanyi << endl;
    }
}

void tambahAntrian() {
    string judul;
    cout << "Masukkan judul lagu yang ingin diantrikan: ";
    getline(cin >> ws, judul);
    for (int i = 0; i < jumlahLagu; i++) {
        if (daftarLagu[i].judul == judul) {
            antrianLagu.push(daftarLagu[i]);
            cout << "Lagu berhasil ditambahkan ke antrian.\n";
            return;
        }
    }
    cout << "Lagu tidak ditemukan.\n";
}

void putarLagu() {
    if (antrianLagu.empty()) {
        cout << "Antrian kosong.\n";
        return;
    }
    Lagu l = antrianLagu.front();
    antrianLagu.pop();
    cout << "Memutar: " << l.judul << " oleh " << l.penyanyi << endl;
}

void hapusLagu() {
    string judul;
    cout << "Masukkan judul lagu yang ingin dihapus: ";
    getline(cin >> ws, judul);
    for (int i = 0; i < jumlahLagu; i++) {
        if (daftarLagu[i].judul == judul) {
            riwayatHapus.push(daftarLagu[i]);
            for (int j = i; j < jumlahLagu - 1; j++) {
                daftarLagu[j] = daftarLagu[j + 1];
            }
            jumlahLagu--;
            cout << "Lagu berhasil dihapus.\n";
            return;
        }
    }
    cout << "Lagu tidak ditemukan.\n";
}

void undoHapus() {
    if (riwayatHapus.empty()) {
        cout << "Tidak ada lagu yang bisa di-undo.\n";
        return;
    }
    if (jumlahLagu >= 100) {
        cout << "Daftar lagu penuh, tidak bisa undo.\n";
        return;
    }
    daftarLagu[jumlahLagu++] = riwayatHapus.top();
    riwayatHapus.pop();
    cout << "Lagu berhasil dikembalikan.\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n--- Spotify KW 100 ---\n";
        cout << "1. Tambah Lagu\n2. Cari Lagu\n3. Lihat Daftar Lagu\n4. Tambah Antrian\n5. Putar Lagu\n6. Hapus Lagu\n7. Undo Hapus\n0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: tambahLagu(); break;
            case 2: cariLagu(); break;
            case 3: tampilkanDaftarLagu(); break;
            case 4: tambahAntrian(); break;
            case 5: putarLagu(); break;
            case 6: hapusLagu(); break;
            case 7: undoHapus(); break;
            case 0: cout << "Terima kasih!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
