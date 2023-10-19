#include <iostream>
#include "pelanggan.h"
#include "hape.h"
#include "konter.h"

using namespace std;

KonterHP konter;
Pelanggan pelanggan;
HP hpManager;
int pilU;
int pilihan;

int main()
{
    do
    {
        system("cls");
        cout << "=== Sistem Penjualan HP ===" << endl;
        cout << "1. Manajemen Data Pelanggan" << endl;
        cout << "2. Manajemen Data HP" << endl;
        cout << "3. Konter HP" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilU;
        system("cls");

        switch (pilU)
        {
            case 1:
                do
                {
                    cout << "=========== Pelanggan ===========" << endl;
                    cout << "1. Tambah Pelanggan" << endl;
                    cout << "2. Tampilkan Daftar Pelanggan" << endl;
                    cout << "3. Hapus Pelanggan" << endl;
                    cout << "0. Keluar" << endl;
                    cout << "Pilihan: ";
                    cin >> pilihan;
                    cin.ignore();

                    switch (pilihan)
                    {
                        case 1:
                            pelanggan.tambahPelanggan();
                            break;
                        case 2:
                            pelanggan.tampilkanDaftarPelanggan();
                            break;
                        case 3:
                            pelanggan.hapusPelanggan();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                            break;
                    }

                    cout << endl;
                } while (pilihan != 0);

                break;

            case 2:
                do
                {
                    system("cls");
                    cout << "===== Manajemen HP =====" << endl;
                    cout << "1. Tambah HP" << endl;
                    cout << "2. Tampilkan Daftar HP" << endl;
                    cout << "3. Edit HP" << endl;
                    cout << "4. Hapus HP" << endl;
                    cout << "0. Keluar" << endl;
                    cout << "Pilih menu: ";
                    cin >> pilihan;
                    cin.ignore();

                    switch (pilihan)
                    {
                        case 1:
                            hpManager.tambahHP();
                            break;
                        case 2:
                            hpManager.tampilkanDaftarHP();
                            break;
                        case 3:
                            hpManager.ubahHP();
                            break;
                        case 4:
                            hpManager.hapusHP();
                            break;
                        case 0:
                            cout << "Program selesai." << endl;
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                            break;
                    }

                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.ignore();
                    cin.get();
                } while (pilihan != 0);

                break;

            case 3:
                do
                {
                    cout << "==== Konter HP ====" << endl;
                    cout << "1. Tampilkan Daftar HP" << endl;
                    cout << "2. Beli HP" << endl;
                    cout << "3. Cari HP" << endl;
                    cout << "0. Keluar" << endl;
                    cout << "Pilihan: ";
                    cin >> pilihan;

                    switch (pilihan)
                    {
                        case 1:
                            konter.tampilkanDaftarHP();
                            break;
                        case 2:
                            konter.jualHP();
                            break;
                        case 3:
                            konter.cariHP();
                            break;
                        case 0:
                            cout << "Terima kasih!" << endl;
                            break;
                        default:
                            cout << "Pilihan tidak valid!" << endl;
                            break;
                    }

                    cout << endl;
                } while (pilihan != 0);

                break;

            case 0:
                cout << "Terima kasih! Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }

        cout << endl;
    } while (pilU != 0);

    return 0;
}
