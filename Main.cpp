#include <iostream>
#include <string>
#include <conio.h> 
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std; // komen yang sudah di baca dan di kerjakan mohon di hapus agar tidak penuh teman teman terimakasih ~dewak 3/5/2025 11:31pm


struct katalog{
    string nama;
    string jenis;
    double harga, id;
};

katalog pria[30];
katalog wanita[30];

void loadDataPria() {
    ifstream file("pria.txt");
    string line;
    int index = 0;

    while (getline(file, line) && index < 30) {
        stringstream ss(line);
        string nama, jenis, hargaStr, id;

        getline(ss, id, ',');
        getline(ss, nama, ',');
        getline(ss, jenis, ',');
        getline(ss, hargaStr, ',');

        replace(nama.begin(), nama.end(), '_', ' ');
        replace(jenis.begin(), jenis.end(), '_', ' ');

        pria[index].id = stod(id);
        pria[index].nama = nama;
        pria[index].jenis = jenis;
        pria[index].harga = stod(hargaStr); // konversi string ke double
        index++;
    }

    file.close();
}


void loadDataWanita() {
    ifstream file("wanita.txt");
    string line;
    int index = 0;

    while (getline(file, line) && index < 30) {
        stringstream ss(line);
        string nama, jenis, hargaStr, id;

        getline(ss, id, ',');
        getline(ss, nama, ',');
        getline(ss, jenis, ',');
        getline(ss, hargaStr, ',');

        replace(nama.begin(), nama.end(), '_', ' ');
        replace(jenis.begin(), jenis.end(), '_', ' ');

        wanita[index].id = stod(id);
        wanita[index].nama = nama;
        wanita[index].jenis = jenis;
        wanita[index].harga = stod(hargaStr); // konversi string ke double
        index++;
    }

    file.close();
}


void tampilkanKatalog(const katalog *produk, int jumlah) {
    cout << "+--------------------------------------------+" << endl;
        for (int i = 0; i < jumlah; i++) {
            if (i <= 8){
                cout << "| " << i+1 << "  | " << produk[i].nama <<  " | " << produk[i].harga << " | " << endl;
            } else
                cout << "| " << i+1 << " | " << produk[i].nama <<  " | " << produk[i].harga << " | " << endl;
        }
    cout << "+--------------------------------------------+" << endl;
}

void tampilkanProduk(const katalog& produk) {
    cout << "Nama  : " << produk.nama << endl;
    cout << "Jenis : " << produk.jenis << endl;
    cout << "Harga : " << produk.harga << endl;
    cout << "-----------------------------" << endl;
    }

void cari_nama() {
    bool ketemu = false;
    string cari;

    system("cls");
    cout << "\n+============================+";
    cout << "\n|          CARI NAMA         |";
    cout << "\n+============================+";
    cout << "\nMasukkan nama produk yang ingin Anda cari: ";
        cin.ignore(); 
        getline(cin, cari); 
    cout << "\nHasil pencarian untuk \"" << cari << "\":\n";
    cout << "+--------------------------------------------+" << endl;
    cout << "| Pria                                       |" << endl;
    cout << "+--------------------------------------------+" << endl;
    
    transform(cari.begin(), cari.end(), cari.begin(), ::tolower);
    for (int i = 0; i < 30; i++) {
        transform(pria[i].nama.begin(), pria[i].nama.end(), pria[i].nama.begin(), ::tolower);
        transform(pria[i].jenis.begin(), pria[i].jenis.end(), pria[i].jenis.begin(), ::tolower);
        if (pria[i].nama.find(cari) != string::npos || pria[i].jenis.find(cari) != string::npos) {
            if (i < 9)
                cout << "| " << pria[i].id << "  | " << pria[i].nama <<  " | " << pria[i].harga << " | " << endl;
            else
                cout << "| " << pria[i].id << " | " << pria[i].nama <<  " | " << pria[i].harga << " | " << endl;
            
            ketemu = true;
        }
    }
    
    cout << endl;
    cout << "+--------------------------------------------+" << endl;
    cout << "| Wanita                                     |" << endl;
    cout << "+--------------------------------------------+" << endl;
    for (int i = 0; i < 30; i++) {
        transform(wanita[i].nama.begin(), wanita[i].nama.end(), wanita[i].nama.begin(), ::tolower);
        transform(wanita[i].jenis.begin(), wanita[i].jenis.end(), wanita[i].jenis.begin(), ::tolower);
        if (wanita[i].nama.find(cari) != string::npos || wanita[i].jenis.find(cari) != string::npos) {
            if (i < 9)
                cout << "| " << wanita[i].id << "  | " << wanita[i].nama << " | " << wanita[i].harga << " |" << endl;
            else
                cout << "| " << wanita[i].id << " | " << wanita[i].nama << " | " << wanita[i].harga << " |" << endl;

            ketemu = true;
        }
    }

    cout << "+--------------------------------------------+" << endl;

    if (!ketemu) {
        cout << "\nData tidak ditemukan." << endl;
    }

    getch();
}

void urutkanHarga(katalog *produk, int jumlah, bool ascending = true) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if ((ascending && produk[i].harga > produk[j].harga) ||
                (!ascending && produk[i].harga < produk[j].harga)) {
                swap(produk[i], produk[j]);  // Lebih simpel pakai swap struct
            }
        }
    }
    tampilkanKatalog(produk, jumlah);
}

void urutkannama(katalog *produk, int jumlah, bool ascending = true) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = i + 1; j < jumlah; j++) {
            if ((ascending && produk[i].nama > produk[j].nama) ||
                (!ascending && produk[i].nama < produk[j].nama)) {
                swap(produk[i], produk[j]);  // Lebih simpel pakai swap struct
            }
        }
    }
    tampilkanKatalog(produk, jumlah);
}

struct akun{
    string username, password;
};

akun user[100];
int tot_user = 0;
bool Login = false;

void registerAcc(){
    system("cls");
    cout << "+--------------------+" << endl;
    cout << "|      REGISTER      |" << endl;
    cout << "+--------------------+" << endl << endl;

    cout << "Username : ";
        cin.ignore();
        getline(cin, user[tot_user].username);
    cout << "Password : ";
        getline(cin, user[tot_user].password);

    ofstream akun("akun.txt", ios::app);
    if (akun.is_open()) {
        akun << user[tot_user].username << "-" << user[tot_user].password << endl;
        akun.close();
    }

    tot_user++;
    cout << "Register successful!" << endl;
    getch();
}

void loadakun() {
    ifstream akun("akun.txt");
    string X;
    while (getline(akun, X)) {
        size_t pos = X.find("-");
        if (pos != string::npos) {
            user[tot_user].username = X.substr(0,pos);
            user[tot_user].password = X.substr(pos + 1);
            tot_user++;
        }
    }
    akun.close();
}

bool login(int Log){
    cin.ignore();
    system("cls");
    string username_bnr, password_bnr;
    bool login_success = false;

    if (Log == 0) {
        return false;
    }

    cout << "+--------------------+" << endl;
    cout << "|        LOGIN       |" << endl;
    cout << "+--------------------+" << endl << endl;

        cout << "Masukkan Username anda : ";
        
            getline(cin, username_bnr);
        cout << "Masukkan Password anda : ";
            getline(cin, password_bnr);

        for (int i = 0; i < tot_user; i++) {
            if (username_bnr == user[i].username && password_bnr == user[i].password) {
                login_success = true;
                break;
            }
        }

        if (login_success == true) {
            cout << "Login successful!" << endl;
            getch();
            return true;
        } else {
            cout << "Username or password incorrect." << endl;
            cout << "You have " << Log - 1<< " chances left." << endl;
            return login(Log-1);
    }
}

struct produkdipesan {
    katalog produk;
    int jumlah;
};

struct pesanan {
    string nama;
    string alamat;
    produkdipesan produkpesan[100];
    int jumlahproduk = 0;
};

pesanan data[100];
int jumlahpesan = 0;

void pemesanan(pesanan* data, int* jumlahpesan) {
    int pesan, noproduk;
    char X;
    bool Y = true;
    bool Z = true;
    katalog produk;

    int totalharga = 0;
    int jumlahbeli;

    pesanan* dataPesanan = &data[*jumlahpesan];

    system("cls");
    cout << "+------------------------------------+" << endl;
    cout << "|              PEMESANAN             |" << endl;
    cout << "+------------------------------------+" << endl;
    cout << "Masukkan Nama Pemesan: ";
        cin.ignore();
        getline(cin, dataPesanan->nama);
    cout << "Masukkan Alamat Pemesan: ";
        getline(cin, data[*jumlahpesan].alamat);
    
    do {
        while (Y) {
            system("cls");
            cout << "Pilihan Pemesanan: " << endl;
            cout << "1. Pria" << endl;
            cout << "2. Wanita" << endl;
            cout << "Masukkan Pilihan: ";
                cin >> pesan;

            switch (pesan) {
                case 1:
                while (Z) {
                    tampilkanKatalog(pria, 30);
                    cout << "Masukkan Nomor Produk: ";
                        cin >> noproduk;
                    if (noproduk >=1 && noproduk <= 30) {
                        produk = pria[noproduk - 1];
                        cout << "Masukkan Jumlah : ";
                        cin >> jumlahbeli;
                        dataPesanan->produkpesan[dataPesanan->jumlahproduk].produk = produk;
                        dataPesanan->produkpesan[dataPesanan->jumlahproduk].jumlah = jumlahbeli;
                        dataPesanan->jumlahproduk++;
                        totalharga += produk.harga * jumlahbeli;
                        Z = false;
                        Y = false;
                    } else {
                        cout << "Pilihan Tidak Ada | Ulangi !" << endl;
                        getch();
                        Z = true;
                    }
                }
                break;
                
                case 2:
                while (Z) {
                    tampilkanKatalog(wanita, 30);
                    cout << "Masukkan Nomor Produk: ";
                    cin >> noproduk;
                    if (noproduk >=1 && noproduk <= 30) {
                        produk = wanita[noproduk - 1];
                        cout << "Masukkan Jumlah : ";
                        cin >> jumlahbeli;
                        dataPesanan->produkpesan[dataPesanan->jumlahproduk].produk = produk;
                        dataPesanan->produkpesan[dataPesanan->jumlahproduk].jumlah = jumlahbeli;
                        dataPesanan->jumlahproduk++;
                        totalharga += produk.harga * jumlahbeli;
                        Z = false;
                        Y = false;
                    } else {
                        cout << "Pilihan Tidak Ada | Ulangi !" << endl;
                        getch();
                        Z = true;
                    }
                    break;
                    
                    default:
                    cout << "Pilihan Tidak Ada | Ulangi !" << endl;
                    getch();
                    Y = true;
                    break;
                }
            }
        } Z = true; Y = true;
    cout << "Apakah anda ingin lanjut memesan ?" << endl;
    cout << "Y/N : ";
        cin >> X;
    } while (X == 'y' || X == 'Y');

    system("cls");
    cout << "+------------------------------------+" << endl;
    cout << "|          RINCIAN PESANAN           |" << endl;
    cout << "+------------------------------------+" << endl;
    cout << "Nama    : " << dataPesanan->nama << endl;
    cout << "Alamat  : " << dataPesanan->alamat << endl;
    cout << endl;
    for (int i = 0; i < dataPesanan->jumlahproduk; i++) {
        produkdipesan item = dataPesanan->produkpesan[i];
        tampilkanProduk(item.produk);
        cout << "Jumlah Dibeli : " << item.jumlah << endl;
        cout << "Subtotal : Rp" << item.produk.harga * item.jumlah << endl;
        cout << "------------------------------------" << endl;
    }
    cout << "Total Harga : Rp" << totalharga << endl;
    getch();
    jumlahpesan++;


    ofstream nota("nota.txt", ios::app);
    if (nota.is_open()) {
        nota << right << setw(10) << "+------------------------------------+" << endl;
        nota << right << setw(10) << "|          RINCIAN PESANAN           |" << endl;
        nota << right << setw(10) << "+------------------------------------+" << endl;
        nota << "Nama    : " << dataPesanan->nama << "" << endl;
        nota << "Alamat  : " << dataPesanan->alamat << endl << endl;

        nota << left << setw(25) << "Produk" 
            << setw(8) << "Harga" 
            << setw(8) << "Jumlah" 
            << setw(10) << "Subtotal" << endl;
        nota << "--------------------------------------------------" << endl;

        for (int i = 0; i < dataPesanan->jumlahproduk; i++) {
            produkdipesan item = dataPesanan->produkpesan[i];
            int subtotal = item.produk.harga * item.jumlah;
            nota << left << setw(18) << item.produk.nama
                << setw(8) << item.produk.harga
                << setw(8) << item.jumlah
                << setw(12) << subtotal << endl;
        }

        nota << "--------------------------------------------------" << endl;
        nota << "Total Harga : Rp" << totalharga << "" << endl;
        nota << "==================================================" << endl << endl;
        nota.close();
    }
}

void historyNbayar() {
    system("cls");

    ifstream nota("nota.txt");
    if (!nota.is_open() || nota.peek() == ifstream::traits_type::eof()) {
        cout << "Belum Ada Data Tersimpan!!" << endl;
        getch();
    }
    
    string X;
    while (getline(nota, X)) {
        cout << X << endl;
    }
    nota.close();
    getch();
}
    
bool menengah() {
        int Z, A, B;
        bool D = true;
        bool X = true;
        int pil_nama;
        bool N = true;
        int jumlah = sizeof(pria) / sizeof(pria[0]);
    
    system("cls");
    cout << "+--------------------+" << endl;
    cout << "|      Toko baju     |" << endl;
    cout << "+--------------------+" << endl << endl;
    cout << "1. Tampilkan Katalog" << endl;
    cout << "2. Filter baju" << endl;
    cout << "3. Cari Baju" << endl;
    cout << "4. Buat Pesanan" << endl;
    cout << "5. Lihat History Pesanan" << endl;
    cout << "6. Exit" << endl;
    cout << "Anda mau memilih apa: ";
    cin >> Z;
    
    switch (Z) {
        case 1:
        while (X) {
            system("cls");
            int C;
            cout << "+--------------------+" << endl;
            cout << "|      Toko baju     |" << endl;
            cout << "+--------------------+" << endl << endl;
            cout << "Pilih salah satu" << endl;
            cout << "1. Katalog khusus Pria" << endl;
            cout << "2. Katalog khusus Wanita" << endl;
            cout << "3. Campuran" << endl;
            cout << "4. Back" << endl;
            cout << "Masukkan pilihan: ";
            cin >> C;
            
            switch (C) {
                case 1:
                cout << "Pria" << endl;
                tampilkanKatalog(pria, 30);
                cout << endl;
                getch();
                break;
                
                case 2:
                cout << "wanita" << endl;
                tampilkanKatalog(wanita, 30);
                cout << endl;
                getch();
                break;
                
                case 3:
                cout << "Pria" << endl;
                tampilkanKatalog(pria, 30);
                cout<< endl;
                cout << "wanita" << endl;
                tampilkanKatalog(wanita, 30);
                getch();
                break;

            case 4:
                X = false;
                cout << "Kembali ke menu utama . . .";
                getch();
                break;
                
                default:
                cout << "Pilihan Tidak Ada | Ulangi !" << endl;
                getch();
                break;
            }
        }
        break;
        
        case 2:
        while(D) {
            system("cls");
            cout << "+--------------------+" << endl;
            cout << "|      Toko baju     |" << endl;
            cout << "+--------------------+" << endl << endl;
            cout << "pilihan filter :";
            cout << "\n1.menampilkan katalog dari harga terendah";
            cout << "\n2.menampilkan katalog dari harga tertinggi";
            cout << "\n3.menampilkan katalog dari A sampai Z";
            cout << "\n4.menampilkan katalog dari Z sampai A";
            cout << "\n5.kembali";
            cout << "\npilih filter : ";
                cin >> B;
            switch (B) {
                case 1:
                    urutkanHarga(pria, jumlah, true);
                    getch();
        break;

                case 2:
                    urutkanHarga(pria, jumlah, false);
                    getch();
                break;

                case 3:
                    urutkannama(pria, jumlah, true);
                    getch();
                break;

                case 4:
                    urutkannama(pria, jumlah, false);
                    getch();
                break;

                case 5:
                    D = false;
                    cout << "Kembali ke menu utama . . .";
                    getch();
                break;

                default:
                    cout << "Pilihan Tidak Ada | Ulangi !" << endl;
                    getch();
                break;
            }
        }
        break;

    case 3:
    while (N) {
        cout << "+----------------+" << endl;
        cout << "|    CARI BAJU   |" << endl;
        cout << "+----------------+" << endl;
        cout << "1. Cari Nama" << endl;
        cout << "2. Back" << endl;
        cout << "Pilih Salah Satu : ";
            cin >> pil_nama;
        
        switch (pil_nama) {
            case 1:
                cari_nama();
            break;
            
            case 2:
                N = false;
            break;
            
            default:
                cout << "Pilihan Tidak Ada | Ulangi !" << endl;
                getch();
            break;
        }
    }
    break;

    case 4:
        pemesanan(data, &jumlahpesan);
        break;

    case 5:
        historyNbayar();
        break;

    case 6:
        while (true) {
            system("cls");
            cout << "+--------------------+" << endl;
            cout << "|      Toko baju     |" << endl;
            cout << "+--------------------+" << endl << endl;
            cout << "Apakah anda ingin keluar kemana?" << endl;
            cout << "1. Kembali ke menu Log In" << endl;
            cout << "2. Keluar dari sistem" << endl;
            cout << "Masukkan Pilihan: ";
                cin >> A;
            
            switch (A) {
                case 1:
                    return false;
                break;

            case 2:
                cout << "Exiting . . .";
                getch();
                exit(0);
            break;

            default:
                cout << "Pilihan Tidak Ada | Ulangi !" << endl;
                getch();
            break;
            }
        }
    break;
        
    default:
        cout << "Pilihan Tidak Ada | Ulangi !" << endl;
        getch();
    break;
    }
    return true;
}

int main(){
    int pilihan;
    loadakun();
    loadDataPria();
    loadDataWanita();

    bool Login = false;

    while (true) {
        system("cls");
        cout << "+-----------------------+" << endl;
        cout << "|       Toko baju       |" << endl;
        cout << "+-----------------------+" << endl;

        cout << "| Jumlah Akun Aktif : " << tot_user << " |" << endl;

        cout << "| 1. Login              |" << endl;
        cout << "| 2. Register           |" << endl;
        cout << "| 3. Exit               |" << endl;
        cout << "+-----------------------+" << endl;
        cout << "| Masukkan Pilihan : ";
            cin >> pilihan;
        cout << "+-----------------------+" << endl;
        getch();
        
        switch (pilihan) {
            case 1:
            if (tot_user == 0) {
                cout << endl;
                cout << "Belum Terdapat Akun\nMohon Register Terlebih Dahulu!!" << endl;
                getch();
                registerAcc();
            }else{
                Login = login(3);
                    if (Login == true) {
                        while(menengah()){
                        }
                    } else {
                        cout << "Login failed." << endl;
                        getch();
                    }
                }
            break;
            
            case 2:            
                registerAcc();
            break;
            
            case 3:            
                cout << "Exiting..." << endl;
                getch();
                return 0;
            break;
            
            default:
                cout << "Pilihan Tidak Ada | Ulangi !" << endl;
                getch();
            break;
        }
    }
}