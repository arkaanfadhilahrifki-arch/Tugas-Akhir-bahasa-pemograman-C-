#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;


// ========================================
// FUNGSI CETAK STRUK PEMINJAMAN
// ========================================

void cetakStruk(string nama, string judul, string penulis, int nomor) {
    ofstream file("struk_peminjaman.txt");

    if (!file.is_open()) {
        cout << "Gagal membuat struk!\n";
        return;
    }

    time_t sekarang = time(0);
    tm *waktu = localtime(&sekarang);

    char tanggal[30];
    strftime(tanggal, sizeof(tanggal), "%d-%m-%Y %H:%M:%S", waktu);

    file << "========================================\n";
    file << "         PERPUSTAKAAN SEKOLAH\n";
    file << "            STRUK PEMINJAMAN\n";
    file << "========================================\n";
    file << "Tanggal      : " << tanggal << endl;
    file << "Nomor Buku   : " << nomor << endl;
    file << "Judul Buku   : " << judul << endl;
    file << "Nama Penulis : " << penulis << endl;
    file << "Peminjam     : " << nama << endl;
    file << "Status       : DIPINJAM\n";
    file << "========================================\n";
    file << "Harap mengembalikan buku tepat waktu.\n";
    file << "Terima kasih telah menggunakan\n";
    file << "layanan perpustakaan kami.\n";
    file << "========================================\n";

    file.close();

    cout << "\nStruk berhasil dibuat!\n";
    cout << "File: struk_peminjaman.txt\n";

    cout << "\nApakah ingin mencetak struk? (Y/T): ";
    char cetak;
    cin >> cetak;

    if (cetak == 'Y' || cetak == 'y') {
        int hasil = system("notepad.exe /p struk_peminjaman.txt");

        if (hasil == 0) {
            cout << "\nPerintah cetak telah dijalankan.\n";
            cout << "Silakan periksa printer kamu.\n";
        } else {
            cout << "\nGagal menjalankan perintah cetak.\n";
            cout << "Silakan cetak file secara manual.\n";
        }
    } else {
        cout << "Struk disimpan dan bisa dicetak nanti.\n";
    }
}


// ========================================
// PROGRAM UTAMA
// ========================================

int main() {
    string judul[30], penulis[30], peminjam[30];
    int status[30];
    int pilihan, nomor, tambah;
    char ulang;

    int jumlahBuku = 5;

    judul[0] = "Bumi";
    penulis[0] = "Tere Liye";
    status[0] = 0;
    peminjam[0] = "-";

    judul[1] = "Laskar Pelangi";
    penulis[1] = "Andrea Hirata";
    status[1] = 0;
    peminjam[1] = "-";

    judul[2] = "Dilan 1990";
    penulis[2] = "Pidi Baiq";
    status[2] = 0;
    peminjam[2] = "-";

    judul[3] = "Laut Bercerita";
    penulis[3] = "Leila S. Chudori";
    status[3] = 0;
    peminjam[3] = "-";

    judul[4] = "Negeri 5 Menara";
    penulis[4] = "Ahmad Fuadi";
    status[4] = 0;
    peminjam[4] = "-";

    do {
        system("cls");

        cout << "\n====================================\n";
        cout << "     SISTEM PERPUSTAKAAN SEKOLAH\n";
        cout << "====================================\n";
        cout << "1. Tambah Data Buku\n";
        cout << "2. Lihat Semua Buku\n";
        cout << "3. Cari Buku\n";
        cout << "4. Pinjam Buku\n";
        cout << "5. Kembalikan Buku\n";
        cout << "6. Lihat Buku Tersedia\n";
        cout << "7. Lihat Data Peminjaman\n";
        cout << "8. Statistik Perpustakaan\n";
        cout << "9. Keluar\n";
        cout << "====================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "\nJumlah buku yang ingin ditambahkan: ";
            cin >> tambah;

            if (jumlahBuku + tambah > 30 || tambah < 1) {
                cout << "Jumlah buku tidak valid!\n";
            } else {
                for (int i = 0; i < tambah; i++) {
                    cout << "\nBuku ke-" << jumlahBuku + 1 << endl;
                    cout << "Judul buku   : ";
                    cin >> ws;
                    getline(cin, judul[jumlahBuku]);

                    cout << "Nama penulis : ";
                    getline(cin, penulis[jumlahBuku]);

                    status[jumlahBuku] = 0;
                    peminjam[jumlahBuku] = "-";
                    jumlahBuku++;
                }

                cout << "\nData buku berhasil ditambahkan!\n";
            }

        } else if (pilihan == 2) {
            cout << "\n========== DAFTAR BUKU ==========\n";

            if (jumlahBuku == 0) {
                cout << "Belum ada data buku.\n";
            } else {
                for (int i = 0; i < jumlahBuku; i++) {
                    cout << "\nNo. " << i + 1 << endl;
                    cout << "Judul    : " << judul[i] << endl;
                    cout << "Penulis  : " << penulis[i] << endl;

                    if (status[i] == 0) {
                        cout << "Status   : Tersedia\n";
                    } else {
                        cout << "Status   : Dipinjam\n";
                        cout << "Peminjam : " << peminjam[i] << endl;
                    }
                }
            }

        } else if (pilihan == 3) {
            string cari;
            bool ditemukan = false;

            cout << "\nMasukkan judul buku: ";
            cin >> ws;
            getline(cin, cari);

            for (int i = 0; i < jumlahBuku; i++) {
                if (judul[i] == cari) {
                    cout << "\nBuku ditemukan!\n";
                    cout << "Judul   : " << judul[i] << endl;
                    cout << "Penulis : " << penulis[i] << endl;

                    if (status[i] == 0) {
                        cout << "Status  : Tersedia\n";
                    } else {
                        cout << "Status  : Dipinjam\n";
                        cout << "Peminjam: " << peminjam[i] << endl;
                    }

                    ditemukan = true;
                }
            }

            if (!ditemukan) {
                cout << "Buku tidak ditemukan.\n";
            }

        } else if (pilihan == 4) {
            cout << "\n========== PINJAM BUKU ==========\n";

            if (jumlahBuku == 0) {
                cout << "Belum ada data buku.\n";
            } else {
                cout << "Nomor buku yang ingin dipinjam: ";
                cin >> nomor;

                if (nomor < 1 || nomor > jumlahBuku) {
                    cout << "Nomor buku tidak valid.\n";
                } else if (status[nomor - 1] == 1) {
                    cout << "Buku sedang dipinjam oleh "
                         << peminjam[nomor - 1] << ".\n";
                } else {
                    cout << "Nama peminjam: ";
                    cin >> ws;
                    getline(cin, peminjam[nomor - 1]);

                    status[nomor - 1] = 1;

                    cout << "\nBuku berhasil dipinjam!\n";

                    // FITUR BARU: MEMBUAT DAN MENCETAK STRUK
                    cetakStruk(
                        peminjam[nomor - 1],
                        judul[nomor - 1],
                        penulis[nomor - 1],
                        nomor
                    );
                }
            }

        } else if (pilihan == 5) {
            cout << "\n======= KEMBALIKAN BUKU =======\n";

            if (jumlahBuku == 0) {
                cout << "Belum ada data buku.\n";
            } else {
                cout << "Nomor buku yang dikembalikan: ";
                cin >> nomor;

                if (nomor < 1 || nomor > jumlahBuku) {
                    cout << "Nomor buku tidak valid.\n";
                } else if (status[nomor - 1] == 0) {
                    cout << "Buku tersebut belum dipinjam.\n";
                } else {
                    status[nomor - 1] = 0;
                    peminjam[nomor - 1] = "-";

                    cout << "Buku berhasil dikembalikan!\n";
                }
            }

        } else if (pilihan == 6) {
            cout << "\n========= BUKU TERSEDIA =========\n";
            bool ada = false;

            for (int i = 0; i < jumlahBuku; i++) {
                if (status[i] == 0) {
                    cout << i + 1 << ". " << judul[i] << endl;
                    cout << "   Penulis: " << penulis[i] << endl;
                    ada = true;
                }
            }

            if (!ada) {
                cout << "Tidak ada buku yang tersedia.\n";
            }

        } else if (pilihan == 7) {
            cout << "\n======= DATA PEMINJAMAN =======\n";
            bool ada = false;

            for (int i = 0; i < jumlahBuku; i++) {
                if (status[i] == 1) {
                    cout << "\nBuku     : " << judul[i] << endl;
                    cout << "Penulis  : " << penulis[i] << endl;
                    cout << "Peminjam : " << peminjam[i] << endl;
                    ada = true;
                }
            }

            if (!ada) {
                cout << "Belum ada buku yang dipinjam.\n";
            }

        } else if (pilihan == 8) {
            int tersedia = 0, dipinjam = 0;

            for (int i = 0; i < jumlahBuku; i++) {
                if (status[i] == 0) {
                    tersedia++;
                } else {
                    dipinjam++;
                }
            }

            cout << "\n======= STATISTIK PERPUSTAKAAN =======\n";
            cout << "Total buku    : " << jumlahBuku << endl;
            cout << "Buku tersedia : " << tersedia << endl;
            cout << "Buku dipinjam : " << dipinjam << endl;

        } else if (pilihan == 9) {
            cout << "\nTerima kasih telah menggunakan ";
            cout << "Sistem Perpustakaan!\n";

        } else {
            cout << "\nPilihan menu tidak tersedia!\n";
        }

        if (pilihan != 9) {
            cout << "\nKembali ke menu? (Y/T): ";
            cin >> ulang;
        } else {
            ulang = 'T';
        }

    } while (ulang == 'Y' || ulang == 'y');

    return 0;
}
