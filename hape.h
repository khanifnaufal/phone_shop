#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class HP {
public:
    int id_hp;
    string merk;
    string tipe;
    string harga;
    int stok;
    vector<HP> daftarHP;
    string namaFile = "dataHP.txt";
    void tambahHP() {
        HP data;
        system("cls");
        cout << "==== Input data HP ====" << endl;
        cout << "ID HP\t\t: ";
        cin >> data.id_hp;
        cin.ignore();
        cout << "Merk\t\t: ";
        getline(cin, data.merk);
        cout << "Tipe\t\t: ";
        getline(cin, data.tipe);
        cout << "Harga\t\t: ";
        getline(cin, data.harga);
        cout << "stok\t\t: ";
        cin >> data.stok;

        daftarHP.push_back(data);

        system("cls");
        cout << "HP berhasil ditambahkan!" << endl;
        simpanKeFile();
    }

    void simpanKeFile() {
        ofstream file(namaFile);

        if (!file) {
            cout << "Gagal membuka file!" << endl;
            return;
        }

        for (const HP& data : daftarHP) {
            file << data.id_hp << endl;
            file << data.merk << endl;
            file << data.tipe << endl;
            file << data.harga << endl;
            file << data.stok << endl;
        }

        file.close();
        cout << "Data HP berhasil disimpan dalam file." << endl;
    }

    void tampilkanDaftarHP() {
        if (daftarHP.empty()) {
            cout << "Tidak ada HP dalam daftar!" << endl;
        }
        else {
            system("cls");
            cout << "==== Daftar HP ====\n" << endl;
            for (int i = 0; i < daftarHP.size(); i++) {
                cout << "ID HP\t\t: " << daftarHP[i].id_hp << endl;
                cout << "Merk\t\t: " << daftarHP[i].merk << endl;
                cout << "Tipe\t\t: " << daftarHP[i].tipe << endl;
                cout << "Harga\t\t: " << daftarHP[i].harga << endl;
                cout << "Stok\t\t: " << daftarHP[i].stok << endl;
                cout << endl;
            }
        }
    }

    void bacaDariFile() {
        string merk, tipe, harga,stok;
        int id_hp;
        HP data;

        ifstream file(namaFile);

        if (!file) {
            system("cls");
            cout << "Gagal membuka file!" << endl;
            return;
        }

        daftarHP.clear();

        while (file >> id_hp) {
            getline(file >> ws, merk);
            getline(file >> ws, tipe);
            getline(file >> ws, harga);
            getline(file >> ws, stok);

            data.id_hp = id_hp;
            data.merk = merk;
            data.tipe = tipe;
            data.harga = harga;
            data.harga = stok;

            daftarHP.push_back(data);
        }

        file.close();
        tampilkanDaftarHP();
    }

    void ubahHP() {
        system("cls");
        bacaDariFile();

        if (daftarHP.empty()) {
            system("cls");
            cout << "Tidak ada HP dalam daftar!" << endl;
            return;
        }

        cout << "Masukkan ID HP yang ingin diedit: ";
        int id;
        cin >> id;
        cin.ignore();

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
            int opsiEdit;
            bool selesai = false;

            do {
                system("cls");
                cout << "==== Informasi HP ====\n" << endl;
                cout << "ID HP\t\t: " << daftarHP[index].id_hp << endl;
                cout << "Merk\t\t: " << daftarHP[index].merk << endl;
                cout << "Tipe\t\t: " << daftarHP[index].tipe << endl;
                cout << "Harga\t\t: " << daftarHP[index].harga << endl;
                cout << "Stok\t\t: " << daftarHP[index].stok << endl;

                cout << "\nApa yang ingin diedit?\n";
                cout << "1. Merk\n";
                cout << "2. Tipe\n";
                cout << "3. Harga\n";
                cout << "4. Stok\n";
                cout << "0. Kembali\n";
                cout << "Pilihan: ";
                cin >> opsiEdit;
                cin.ignore();

                switch (opsiEdit) {
                case 1:
                    cout << "Masukkan merk HP baru: ";
                    getline(cin, daftarHP[index].merk);
                    cout << "Merk HP berhasil diedit!" << endl;
                    break;
                case 2:
                    cout << "Masukkan tipe HP baru: ";
                    getline(cin, daftarHP[index].tipe);
                    cout << "Tipe HP berhasil diedit!" << endl;
                    break;
                case 3:
                    cout << "Masukkan harga HP baru: ";
                    getline(cin, daftarHP[index].harga);
                    cout << "Harga HP berhasil diedit!" << endl;
                    break;
                case 4:
                    cout << "Masukkan stok HP baru: ";
                    cin >> daftarHP[index].stok;
                    cout << "stok HP berhasil diedit!" << endl;
                    break;
                case 0:
                    selesai = true;
                    break;
                default:
                    cout << "Pilihan tidak valid!" << endl;
                    break;
                }
            } while (!selesai);

            system("cls");
            cout << "HP berhasil diedit!\n" << endl;
            simpanKeFile();
        }
        else {
            system("cls");
            cout << "HP dengan ID tersebut tidak ditemukan!" << endl;
        }
    }

    void hapusHP() {
        system("cls");
        bacaDariFile();

        if (daftarHP.empty()) {
            system("cls");
            cout << "Tidak ada HP dalam daftar!" << endl;
            return;
        }

        cout << "Masukkan ID HP yang ingin dihapus: ";
        int id;
        cin >> id;
        cin.ignore();

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
            daftarHP.erase(daftarHP.begin() + index);
            system("cls");
            cout << "HP berhasil dihapus!" << endl;
            simpanKeFile();
        }
        else {
            system("cls");
            cout << "HP dengan ID tersebut tidak ditemukan!" << endl;
        }
    }
};
