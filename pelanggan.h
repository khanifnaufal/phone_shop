#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Pelanggan{
public:
    int id_pelanggan;
    string nama;
    string email;
    string tanggalBeli;
    int lamaKeanggotaan;
    vector<Pelanggan> daftarPelanggan;
    vector<string> dataPeminjaman;
    string namaFile = "datapelanggan.txt";

    void tambahPelanggan(){
        Pelanggan info;
        system("cls");
        cout << "==== Input data pelanggan ====" << endl;
        cout << "ID Pelanggan\t\t: "; cin >> info.id_pelanggan;
        cin.ignore();
        cout << "Nama\t: ";
        getline(cin, info.nama);
        cout << "Email\t: ";
        getline(cin, info.email);
        cout << "Tanggal Beli (DD-MM-YYYY)\t: ";
        getline(cin, info.tanggalBeli);
        daftarPelanggan.push_back(info);
        system("cls");
        cout << "Pelanggan berhasil ditambahkan!" << endl;
        simpanKeFile();
    }

    void simpanKeFile(){
        ofstream file(namaFile);
        if (!file){
            cout << "Gagal membuka file!" << endl;
            return;
        }
        for (const Pelanggan &info : daftarPelanggan)
        {
            file << info.id_pelanggan << endl;
            file << info.nama << endl;
            file << info.email << endl;
            file << info.tanggalBeli << endl;
        }
        file.close();
        cout << "Data pelanggan berhasil disimpan dalam file." << endl;
    }

    void tampilkanDaftarPelanggan() {
        if (daftarPelanggan.empty()){
            cout << "Tidak ada pelanggan dalam daftar!" << endl;
        }
        else{
            system("cls");
            cout << "==== Daftar pelanggan ====\n" << endl;
            for (int i = 0; i < daftarPelanggan.size(); i++)
            {
                cout << "ID Pelanggan\t: " << daftarPelanggan[i].id_pelanggan << endl;
                cout << "Nama\t\t: " << daftarPelanggan[i].nama << endl;
                cout << "Email\t\t: " << daftarPelanggan[i].email << endl;
                cout << "Tanggal Beli\t: " << daftarPelanggan[i].tanggalBeli << endl;
                cout << endl;
            }
        }
    }

    void bacaDariFile(){
        string nama, email, tanggalBeli;
        int id_pelanggan;
        Pelanggan info;
        ifstream file(namaFile);
        if (!file){
            system("cls");
            cout << "Gagal membuka file!" << endl;
            return;
        }
        daftarPelanggan.clear();
        while (file >> id_pelanggan){
            getline(file >> ws, nama);
            getline(file >> ws, email);
            getline(file >> ws, tanggalBeli);
            info.id_pelanggan = id_pelanggan;
            info.nama = nama;
            info.email = email;
            info.tanggalBeli = tanggalBeli;
            daftarPelanggan.push_back(info);
        }
        file.close();
        tampilkanDaftarPelanggan();
    }
    
    void ubahPelanggan(){
        system("cls");
        bacaDariFile();
        if (daftarPelanggan.empty()){
            system("cls");
            cout << "Tidak ada pelanggan dalam daftar!" << endl;
            return;
        }
        cout << "Masukkan ID pelanggan yang ingin diedit: ";
        int id;
        cin >> id;
        cin.ignore();
        bool pelangganKetemu = false;
        for (Pelanggan &info : daftarPelanggan){
            if (info.id_pelanggan == id){
                pelangganKetemu = true;
                int opsiEdit;
                bool selesai = false;
                do{
                    system("cls");
                    cout << "==== Informasi pelanggan ====\n" << endl;
                    cout << "ID pelanggan\t: " << info.id_pelanggan << endl;
                    cout << "Nama\t\t: " << info.nama << endl;
                    cout << "Email\t\t: " << info.email << endl;
                    cout << "Tanggal Beli\t: " << info.tanggalBeli << endl;
                    cout << "\nApa yang ingin diedit?\n";
                    cout << "1. Nama\n";
                    cout << "2. Email\n";
                    cout << "3. Tanggal Beli\n";
                    cout << "0. Kembali\n";
                    cout << "Pilihan: ";
                    cin >> opsiEdit;
                    cin.ignore();
                    switch (opsiEdit){
                    case 1:
                        cout << "Masukkan nama pelanggan baru: ";
                        getline(cin, info.nama);
                        cout << "Nama pelanggan berhasil diedit!" << endl;
                        break;
                    case 2:
                        cout << "Masukkan email pelanggan baru: ";
                        getline(cin, info.email);
                        cout << "Email pelanggan berhasil diedit!" << endl;
                        break;
                    case 3:
                        cout << "Masukkan tanggal Beli baru: ";
                        getline(cin, info.tanggalBeli);
                        cout << "Tanggal beli berhasil diedit!" << endl;
                        break;
                    case 0:
                        selesai = true;
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                        break;
                    }
                }while (!selesai);
                system("cls");
                cout << "Data pelanggan berhasil diedit!\n" << endl;
                simpanKeFile();
                break;
            }
        }
        if (!pelangganKetemu){
            system("cls");
            cout << "Pelanggan dengan ID tersebut tidak ditemukan!" << endl;
        }   
    }

    void hapusPelanggan(){
        system("cls");
        bacaDariFile();
        if (daftarPelanggan.empty()){
            system("cls");
            cout << "Tidak ada data pelanggan dalam daftar!" << endl;
            return;
        }
        cout << "Masukkan ID pelanggan yang ingin dihapus: ";
        int id;
        cin >> id;
        cin.ignore();
        bool pelangganKetemu = false;
        int index = -1;
        for (int i = 0; i < daftarPelanggan.size(); i++){
            if (daftarPelanggan[i].id_pelanggan == id){
                pelangganKetemu = true;
                index = i;
                break;
            }
        }
        if (pelangganKetemu){
            daftarPelanggan.erase(daftarPelanggan.begin() + index);
            system("cls");
            cout << "Pelanggan berhasil dihapus!" << endl;
            simpanKeFile();
        }
        else{
            system("cls");
            cout << "Pelanggan dengan ID tersebut tidak ditemukan!" << endl;
        }
    }
};