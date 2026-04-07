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
    cout << "(6) Keluar" << endl;
    cout << "Pilih menu (1-6): ";
}

int login(string user, string pass){
    if(user == "Larasati" && pass == "010"){
        return 1;
    } else {
        return 0;
    }
}

void tambahData(data_sewaBaju *baju, int *jumlah){
    cout << "======================" << endl;
    cout << "|    Tambah Data      |" << endl;
    cout << "======================" << endl;

    cout << "ID Baju: ";
    cin >> baju[*jumlah].id_baju;

    cout << "Ukuran: ";
    cin >> baju[*jumlah].ukuran;

    cout << "Warna: ";
    cin >> baju[*jumlah].warna;

    cout << "Harga: ";
    cin >> baju[*jumlah].harga_sewa;

    cout << "Status: ";
    cin >> baju[*jumlah].status;

    (*jumlah)++;
}

void tampilkanData(data_sewaBaju *baju, int jumlah){
    cout << "======================" << endl;
    cout << "|    Semua Data      |" << endl;
    cout << "======================" << endl;

    for(int i = 0; i < jumlah; i++){
        cout << "ID: " << (baju+i)->id_baju << endl;
        cout << "Ukuran: " << (baju+i)->ukuran << endl;
        cout << "Warna: " << (baju+i)->warna << endl;
        cout << "Harga: " << (baju+i)->harga_sewa << endl;
        cout << "Status: " << (baju+i)->status << endl;
    }
}

int cariData(data_sewaBaju *baju, int jumlah, string id){
    for(int i = 0; i < jumlah; i++){
        if((baju+i)->id_baju == id){
            return i;
        }
    }
    return -1;
}

void updateData(data_sewaBaju *baju, int jumlah, string id){
    int index = cariData(baju, jumlah, id);

    if(index != -1){
        cout << "Data ditemukan, update: " << endl;

        cout << "Harga: ";
        cin >> (baju+index)->harga_sewa;

        cout << "Warna: ";
        cin >> (baju+index)->warna;

        cout << "Ukuran: ";
        cin >> (baju+index)->ukuran;

        cout << "Status: ";
        cin >> (baju+index)->status;

        cout << "Data berhasil diupdate." << endl;
    
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

void hapusData(data_sewaBaju *baju, int *jumlah, string id){
    int index = cariData(baju, *jumlah, id);

    if(index != -1){
        for(int i = index; i < (*jumlah)-1; i++){
            *(baju+i) = *(baju+i+1);
        }
        (*jumlah)--;
        cout << "Data berhasil dihapus" << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}

void ulang(int n){
    if(n == 0) return;
    cout << "Terimakasih..." << endl;
}

int main(){
    data_sewaBaju baju[100];
    int jumlah = 0;

    string user, pass;
    int percobaan = 0;

    while(percobaan < 3){
        cout << "=================" << endl;
        cout << "|    Login      |" << endl;
        cout << "=================" << endl;
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if(login(user, pass) == 1){
            cout << "Login berhasil!" << endl;
            break;
        } else {
            percobaan++;
            cout << "Login salah! Percobaan ke-" << percobaan << endl;
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
                cout << "ID: " << baju[index].id_baju << endl;
                cout << "Ukuran: " << baju[index].ukuran << endl;
                cout << "Warna: " << baju[index].warna << endl;
                cout << "Harga: " << baju[index].harga_sewa << endl;
                cout << "Status: " << baju[index].status << endl;
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
            cout << "Keluar..." << endl;
        }
        else {
            cout << "Pilihan tidak valid" << endl;
        }
    } while(pilih != 6);

    ulang(2);

    return 0;

}