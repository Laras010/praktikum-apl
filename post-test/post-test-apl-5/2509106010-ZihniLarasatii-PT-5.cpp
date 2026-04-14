#include <iostream>
using namespace std;

struct data_sewaBaju {
    string id_baju, ukuran, warna, status;
    int harga_sewa;
};

void tampilMenu(){
    cout << "======================" << endl;
    cout << "|    MENU UTAMA      |" << endl;
    cout << "======================" << endl;
    cout << "(1) Buat Data Baju" << endl;
    cout << "(2) Tampilkan Semua Data" << endl;
    cout << "(3) Cari Data" << endl;
    cout << "(4) Update Data" << endl;
    cout << "(5) Delete" << endl;
    cout << "(6) Sorting" << endl;
    cout << "(7) Keluar" << endl;
    cout << "Pilih menu (1-7): ";
}

int login(string user, string pass){
    return (user == "Larasati" && pass == "010");
}

void tambahData(data_sewaBaju *baju, int *jumlah){
    cout << "=== Tambah Data ===" << endl;
    cout << "ID Baju: "; cin >> baju[*jumlah].id_baju;
    cout << "Ukuran: "; cin >> baju[*jumlah].ukuran;
    cout << "Warna: "; cin >> baju[*jumlah].warna;
    cout << "Harga: "; cin >> baju[*jumlah].harga_sewa;
    cout << "Status: "; cin >> baju[*jumlah].status;
    (*jumlah)++;
}

void tampilkanData(data_sewaBaju *baju, int jumlah){
    cout << "=== Data Baju ===" << endl;
    for(int i = 0; i < jumlah; i++){
        cout << i+1 << ". "
             << (baju+i)->id_baju << " | "
             << (baju+i)->ukuran << " | "
             << (baju+i)->warna << " | "
             << (baju+i)->harga_sewa << " | "
             << (baju+i)->status << endl;
    }
}

int cariData(data_sewaBaju *baju, int jumlah, string id){
    for(int i = 0; i < jumlah; i++){
        if((baju+i)->id_baju == id) return i;
    }
    return -1;
}

void updateData(data_sewaBaju *baju, int jumlah, string id){
    int index = cariData(baju, jumlah, id);

    if(index != -1){
        cout << "Update data:" << endl;
        cout << "Harga: "; cin >> (baju+index)->harga_sewa;
        cout << "Warna: "; cin >> (baju+index)->warna;
        cout << "Ukuran: "; cin >> (baju+index)->ukuran;
        cout << "Status: "; cin >> (baju+index)->status;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}

void hapusData(data_sewaBaju *baju, int *jumlah, string id){
    int index = cariData(baju, *jumlah, id);

    if(index != -1){
        for(int i = index; i < (*jumlah)-1; i++){
            *(baju+i) = *(baju+i+1);
        }
        (*jumlah)--;
        cout << "Data dihapus" << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}

void sorting(data_sewaBaju *baju, int jumlah){
    int pilih;
    char ulang;

    do{
        cout << "=== SORTING ===" << endl;
        cout << "1. Berdasarkan ID" << endl;
        cout << "2. Berdasarkan Harga" << endl;
        cout << "3. Berdasarkan Ukuran" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        for(int i = 0; i < jumlah-1; i++){
            for(int j = i+1; j < jumlah; j++){

                if(pilih == 1 && (baju+i)->id_baju > (baju+j)->id_baju){
                    swap(*(baju+i), *(baju+j));
                }
                else if(pilih == 2 && (baju+i)->harga_sewa > (baju+j)->harga_sewa){
                    swap(*(baju+i), *(baju+j));
                }
                else if(pilih == 3 && (baju+i)->ukuran > (baju+j)->ukuran){
                    swap(*(baju+i), *(baju+j));
                }
            }
        }

        tampilkanData(baju, jumlah);

        cout << "Ulang sorting? (y/n): ";
        cin >> ulang;

    } while(ulang == 'y' || ulang == 'Y');
}

int main(){
    data_sewaBaju baju[100];
    int jumlah = 0;

    string user, pass;
    int percobaan = 0;

    
    while(percobaan < 3){
        cout << "=== LOGIN ===" << endl;
        cout << "Username: "; cin >> user;
        cout << "Password: "; cin >> pass;

        if(login(user, pass)){
            cout << "Login berhasil!" << endl;
            break;
        } else {
            percobaan++;
            cout << "Login salah!" << endl;
        }

        if(percobaan == 3){
            cout << "Program berhenti" << endl;
            return 0;
        }
    }

    int pilih;
    string id;

    do{
        tampilMenu();
        cin >> pilih;

        if(pilih == 1){
            tambahData(baju, &jumlah);
        }
        else if(pilih == 2){
            tampilkanData(baju, jumlah);
        }
        else if(pilih == 3){
            cout << "Masukan ID: ";
            cin >> id;

            int index = cariData(baju, jumlah, id);
            if(index != -1){
                cout << "Data ditemukan" << endl;
            } else {
                cout << "Data tidak ditemukan" << endl;
            }
        }
        else if(pilih == 4){
            cout << "Masukan ID: ";
            cin >> id;
            updateData(baju, jumlah, id);
        }
        else if(pilih == 5){
            cout << "Masukan ID: ";
            cin >> id;
            hapusData(baju, &jumlah, id);
        }
        else if(pilih == 6){
            sorting(baju, jumlah);
        }
        else if(pilih == 7){
            cout << "Keluar..." << endl;
        }
        else {
            cout << "Pilihan tidak valid" << endl;
        }

    } while(pilih != 7);

    return 0;
}