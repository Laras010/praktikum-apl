#include <iostream>
using namespace std;

struct data_sewaBaju{
    string id_baju, ukuran, warna, status;
    int harga_sewa;
};

int main() {

    data_sewaBaju baju [100];
    int jumlah = 0;

    string Username;
    string Password;
    string Usernamecorrect = "Larasati";
    string Passwordcorrect = "010";
    int percobaan = 0;

     while (percobaan < 3){
        cout << "===========================" << endl;
        cout << "|           LOGIN          |" << endl;
        cout << "===========================" << endl;
        cout << "Masukan Username Anda : ";
        cin >> Username;
        cout << "Masukan Password (3 digit NIM terakhir) : ";
        cin >> Password;
        cout << endl;

    if (Username == Usernamecorrect && Password == Passwordcorrect){
        cout << "===== LOGIN BERHASIL =====" << endl;
        break;
    }
    else {
        percobaan++;
        cout << "LOGIN SALAH! percobaan ke-" << percobaan << endl;

        if (percobaan == 3){
            cout << "Anda salah 3x." << endl;
            cout << "Program berhenti." << endl;
            return 0;
        }
    }
    cout << endl;
}

cout << "Masuk ke Program....." << endl;

int pilih;
string cari_id;

do {
    cout << endl;
    cout << "===== MENU UTAMA =====" << endl;
    cout << "(1) Buat Data Baju" << endl;
    cout << "(2) Tampilkan Semua Data" << endl;
    cout << "(3) Cari Data" << endl;
    cout << "(4) Update Data" << endl;
    cout << "(5) Delete" << endl;
    cout << "(6) Keluar" << endl;

    cout << "Pilih menu (1-6) : ";
    cin >> pilih;

    if (pilih == 1){
        cout << "========================" << endl;
        cout << "|   Tambah Data Baju   |" << endl;
        cout << "========================" << endl;

        cout << "ID Baju : ";
        cin >> baju[jumlah].id_baju;

        cout << "Ukuran : ";
        cin >> baju[jumlah].ukuran;

        cout << "Warna : ";
        cin >> baju[jumlah].warna;

        cout << "Harga Sewa :";
        cin >> baju[jumlah].harga_sewa;

        cout << "Status (Tersedia/Disewa) : ";
        cin >> baju[jumlah].status;

        jumlah++;
    }
    else if (pilih == 2){
        cout << "========================" << endl;
        cout << "|   Semua Data Baju    |" << endl;
        cout << "========================" << endl;

        for(int i = 0; i < jumlah; i++){
            cout << "ID Baju : " << baju[i].id_baju << endl;
            cout << "Ukuran : " << baju[i].ukuran << endl;
            cout << "Warna : " << baju[i].warna << endl;
            cout << "Harga Sewa : " << baju[i].harga_sewa << endl;
            cout << "Status : " << baju[i].status << endl;
            cout << "-------------------------" << endl;
         }

    }

    else if (pilih == 3){
        cout << "Masukan ID Baju yang dicari : ";
        cin >> cari_id;

        bool ditemukan = false;

        for(int i = 0; i < jumlah; i++){
            if(baju[i].id_baju == cari_id){
                cout << "=== Data ditemukan! ===" << endl;
                cout << "Ukuran : " << baju[i].ukuran << endl;
                cout << "Warna : " << baju[i].warna << endl;
                cout << "Harga Sewa : " << baju[i].harga_sewa << endl;
                cout << "Status : " << baju[i].status << endl;

                ditemukan = true;
            }
        }

        if(!ditemukan){
            cout << "Data tidak ditemukan." << endl;
        }
    }

    else if (pilih == 4){
        cout << "Masukan ID Baju yang ingin diupdate : ";
        cin >> cari_id;

        for(int i = 0; i < jumlah; i++){
            if(baju[i].id_baju == cari_id){

                cout << "Harga : ";
                cin >> baju[i].harga_sewa;

                cout << "Warna : ";
                cin >> baju[i].warna;

                cout << "Ukuran : ";
                cin >> baju[i].ukuran;

                cout << "Status : ";
                cin >> baju[i].status;

                cout << "Data berhasil diupdate." << endl;
            }
        }
    }

    else if (pilih == 5){
        cout << "Masukan ID Baju yang akan dihapus : ";
        cin >> cari_id;

        for(int i = 0; i < jumlah; i++){
            if(baju[i].id_baju == cari_id){

                for(int j = i; j < jumlah - 1; j++){
                    baju[j] = baju[j+1];
                }
                
                jumlah--;
                cout << "Data berhasil dihapus." << endl;
            }
        }
    }

} while (pilih != 6);

cout << "Program selesai." << endl;

return 0;

} 