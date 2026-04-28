#include <iostream>
#include <stdexcept>
using namespace std;

struct data_sewaBaju {
    string id_baju, nama_baju, ukuran, warna, status;
    int harga_sewa;
};

int login(string user, string pass){
    return (user == "Larasati" && pass == "010");
}

void tampilMenu(){
    cout << endl;
    cout << "===== MENU =====" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Tampilkan Data" << endl;
    cout << "3. Cari Data" << endl;
    cout << "4. Update Data" << endl;
    cout << "5. Hapus Data" << endl;
    cout << "6. Sorting ID" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilih: ";
}

void tambahData(data_sewaBaju *baju, int *jumlah){
    try{
        cout << endl << "===== INPUT DATA =====" << endl;

        cout << "ID Baju   : ";
        cin >> baju[*jumlah].id_baju;

        cout << "Nama Baju : ";
        cin >> baju[*jumlah].nama_baju;

        cout << "Ukuran    : ";
        cin >> baju[*jumlah].ukuran;

        cout << "Warna     : ";
        cin >> baju[*jumlah].warna;

        cout << "Harga     : ";
        cin >> baju[*jumlah].harga_sewa;
        if(cin.fail()) throw "Harga harus angka";

        cout << "Status    : ";
        cin >> baju[*jumlah].status;

        (*jumlah)++;
        cout << endl << "Data berhasil ditambahkan!" << endl;
    }
    catch(const char* err){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: " << err << endl;
    }
}

void tampilkanData(data_sewaBaju *baju, int jumlah){
    cout << endl << "=== DATA ===" << endl;
    for(int i = 0; i < jumlah; i++){
        cout << i+1 << ". "
             << baju[i].id_baju << " | "
             << baju[i].nama_baju << " | "
             << baju[i].ukuran << " | "
             << baju[i].warna << " | "
             << baju[i].harga_sewa << " | "
             << baju[i].status << endl;
    }
}

int main(){
    data_sewaBaju baju[100];
    int jumlah = 0;

    string user, pass;
    int percobaan = 0;

    while(percobaan < 3){
        try{
            cout << "Username: ";
            cin >> user;

            cout << "Password: ";
            cin >> pass;

            if(user == "" || pass == "")
                throw "Input tidak boleh kosong";

            if(!login(user, pass))
                throw "Username / Password salah";

            cout << "Login berhasil!" << endl;
            break;
        }
        catch(const char* err){
            percobaan++;
            cout << "Error: " << err << endl;
        }

        if(percobaan == 3){
            cout << "Program berhenti!" << endl;
            return 0;
        }
    }

    int pilih;

    do{
        try{
            tampilMenu();
            cin >> pilih;

            if(cin.fail()) throw "Input harus angka";
            if(pilih < 1 || pilih > 7)
                throw "Pilihan tidak valid";

            if(pilih == 1){
                tambahData(baju, &jumlah);
            }
            else if(pilih == 2){
                tampilkanData(baju, jumlah);
            }
            else if(pilih == 7){
                cout << "Keluar program..." << endl;
            }

        }
        catch(const char* err){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: " << err << endl;
        }

    } while(pilih != 7);

    return 0;
}