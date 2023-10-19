#include <iostream>
#include <fstream>
#include <vector>
#include <string>



using namespace std;

class KonterHP {
private:
    vector<HP> daftarHP;
    vector<Pelanggan> daftarPelanggan;

public:

    string namaFile = "dataHP.txt";

    void bacaDariFile() {
        ifstream file(namaFile);

        if (!file) {
            cout << "Gagal membuka file!" << endl;
            return;
        }

        daftarHP.clear();

        HP data;
        while (file >> data.id_hp) {
            file.ignore();
            getline(file, data.merk);
            getline(file, data.tipe);
            getline(file, data.harga);
            file >> data.stok;

            daftarHP.push_back(data);
        }

        file.close();
    }

    void tampilkanDaftarHP() {
        bacaDariFile();
        if (daftarHP.empty()) {
            cout << "Tidak ada HP dalam daftar!" << endl;
        }
        else {
            cout << "==== Daftar HP ====" << endl;
            for (const HP& data : daftarHP) {
                cout << "ID HP\t\t: " << data.id_hp << endl;
                cout << "Merk\t\t: " << data.merk << endl;
                cout << "Tipe\t\t: " << data.tipe << endl;
                cout << "Harga\t\t: " << data.harga << endl;
                cout << "Stok\t\t: " << data.stok << endl;
                cout << endl;
            }
        }
    }

    void simpanDataPelanggan(const Pelanggan& pelanggan) {
        ofstream file("data.pelanggan.txt", ios::app);

        if (!file) {
            cout << "Gagal membuka file data_pelanggan.txt!" << endl;
            return;
        }

        file << "Id: " << pelanggan.id_pelanggan << endl;
        file << "Nama: " << pelanggan.nama << endl;
        file << "Email: " << pelanggan.email << endl;
        file << endl;

        file.close();
    }

        void cariHP() {
        bacaDariFile();
        if (daftarHP.empty()) {
            cout << "Tidak ada HP dalam daftar!" << endl;
            return;
        }

        int opsi;
        cout << "Cari berdasarkan kriteria:\n";
        cout << "1. Merk\n";
        cout << "2. Tipe\n";
        cout << "Pilihan: ";
        cin >> opsi;

        string kriteria;
        cin.ignore();
        cout << "Masukkan kriteria: ";
        getline(cin, kriteria);

        bool ditemukan = false;
        switch (opsi) {
        case 1:
            cout << "==== Hasil Pencarian berdasarkan Merk ====" << endl;
            for (const HP& data : daftarHP) {
                if (data.merk.find(kriteria) != string::npos) {
                    cout << "ID HP\t\t: " << data.id_hp << endl;
                    cout << "Merk\t\t: " << data.merk << endl;
                    cout << "Tipe\t\t: " << data.tipe << endl;
                    cout << "Harga\t\t: " << data.harga << endl;
                    cout << "Stok\t\t: " << data.stok << endl;
                    cout << endl;
                    ditemukan = true;
                }
            }
            break;
        case 2:
            cout << "==== Hasil Pencarian berdasarkan Tipe ====" << endl;
            for (const HP& data : daftarHP) {
                if (data.tipe.find(kriteria) != string::npos) {
                    cout << "ID HP\t\t: " << data.id_hp << endl;
                    cout << "Merk\t\t: " << data.merk << endl;
                    cout << "Tipe\t\t: " << data.tipe << endl;
                    cout << "Harga\t\t: " << data.harga << endl;
                    cout << "Stok\t\t: " << data.stok << endl;
                    cout << endl;
                    ditemukan = true;
                }
            }
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return;
        }

        if (!ditemukan) {
            cout << "HP dengan kriteria tersebut tidak ditemukan!" << endl;
        }
    }

    void jualHP() {
        bacaDariFile(); // Read data from file
        if (daftarHP.empty()) {
            cout << "Tidak ada HP yang tersedia!" << endl;
            return;
        }

        int id;
        cout << "Masukkan ID HP yang ingin dibeli: ";
        cin >> id;

        bool hpKetemu = false;
        int index = -1;

        for (int i = 0; i < daftarHP.size(); i++) {
            if (daftarHP[i].id_hp == id) {
                hpKetemu = true;
                index = i;
                break;
            }
        }

        if (hpKetemu) {
            if (daftarHP[index].stok > 0) {
                cout << "HP dengan ID tersebut tersedia. Harga: " << daftarHP[index].harga << endl;

                char pilihan;
                cout << "Apakah Anda ingin membeli? (y/n): ";
                cin >> pilihan;

                if (pilihan == 'y' || pilihan == 'Y') {
                    daftarHP[index].stok--;
                    cout << "HP berhasil dibeli!" << endl;

                    Pelanggan pelanggan;
                    cin.ignore();
                    cout << "Masukkan ID pelanggan: ";
                    cin >> pelanggan.id_pelanggan;
                    cin.ignore();
                    cout << "Masukkan nama pelanggan: ";
                    getline(cin, pelanggan.nama);
                    cout << "Masukkan email pelanggan: ";
                    getline(cin, pelanggan.email);

                    simpanDataPelanggan(pelanggan); // Save customer data to file

                    ofstream struk("struk.txt");
                    struk << "==== Struk Pembelian ====" << endl;
                    struk << "ID Pelanggan: " << pelanggan.id_pelanggan << endl;
                    struk << "Nama Pelanggan: " << pelanggan.nama << endl;
                    struk << "Email Pelanggan: " << pelanggan.email << endl;
                    struk << "HP yang dibeli:" << endl;
                    struk << "ID HP: " << daftarHP[index].id_hp << endl;
                    struk << "Merk: " << daftarHP[index].merk << endl;
                    struk << "Tipe: " << daftarHP[index].tipe << endl;
                    struk << "Harga: " << daftarHP[index].harga << endl;
                    struk << endl;

                    struk.close();

                    ofstream file(namaFile);
                    for (const HP& data : daftarHP) {
                        file << data.id_hp << endl;
                        file << data.merk << endl;
                        file << data.tipe << endl;
                        file << data.harga << endl;
                        file << data.stok << endl;
                    }
                    file.close();
                    tampilkanStruk();
                }
                else {
                    cout << "Batal pembelian." << endl;
                }
            }
            else {
                cout << "HP dengan ID tersebut sedang kosong!" << endl;
            }
        }
        else {
            cout << "HP dengan ID tersebut tidak ditemukan!" << endl;
        }
    }
        void tampilkanStruk() {
        ifstream file("struk.txt");

        if (!file) {
            cout << "Gagal membuka file struk!" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }
};



