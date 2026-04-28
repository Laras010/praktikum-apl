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

void tambahData(data_sewaBaju *baju, int *jumlah) {

    try {
        cout << "\n===== INPUT DATA =====" << endl;

        cout << "ID Baju   : ";
        cout.flush(); 
        cin >> baju[*jumlah].id_baju;

        cout << "Nama Baju : ";
        cout.flush();
        cin >> baju[*jumlah].nama_baju;

        cout << "Ukuran    : ";
        cout.flush();
        cin >> baju[*jumlah].ukuran;

        cout << "Warna     : ";
        cout.flush();
        cin >> baju[*jumlah].warna;

        cout << "Harga     : ";
        cout.flush();
        cin >> baju[*jumlah].harga_sewa;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw "Harga harus angka";
        }

        cout << "Status    : ";
        cout.flush();
        cin >> baju[*jumlah].status;

        (*jumlah)++;
        cout << "Data berhasil ditambahkan!" << endl;
    }
    catch(const char* err) {
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

int sequentialSearch(data_sewaBaju *baju, int jumlah, string nama){
    for(int i = 0; i < jumlah; i++){
        if(baju[i].nama_baju == nama){
            return i;
        }
    }
    return -1;
}

int binarySearch(data_sewaBaju *baju, int jumlah, string id){
    int left = 0, right = jumlah - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(baju[mid].id_baju == id) return mid;
        else if(id < baju[mid].id_baju) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

void sortingID(data_sewaBaju *baju, int jumlah){
    for(int i = 0; i < jumlah-1; i++){
        for(int j = i+1; j < jumlah; j++){
            if(baju[i].id_baju > baju[j].id_baju){
                swap(baju[i], baju[j]);
            }
        }
    }
    cout << "Data sudah diurutkan!" << endl;
}

void updateData(data_sewaBaju *baju, int jumlah, string id){
    try{
        for(int i = 0; i < jumlah; i++){
            if(baju[i].id_baju == id){
                cout << "Data ditemukan, input ulang:" << endl;

                cout << "Nama Baju : ";
                cin >> baju[i].nama_baju;

                cout << "Ukuran    : ";
                cin >> baju[i].ukuran;

                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Warna     : ";
                cin >> baju[i].warna;

                cout << "Harga     : ";
                cin >> baju[i].harga_sewa;
                if(cin.fail()) throw "Harga harus angka";

                cin.clear();
                cin.ignore(1000, '\n');

                cout << "Status    : ";
                cin >> baju[i].status;

                cout << "Update berhasil!" << endl;
                return;
            }
        }
        throw "Data tidak ditemukan";
    }
    catch(const char* err){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: " << err << endl;
    }
}

void hapusData(data_sewaBaju *baju, int *jumlah, string id){
    try{
        for(int i = 0; i < *jumlah; i++){
            if(baju[i].id_baju == id){
                for(int j = i; j < *jumlah - 1; j++){
                    baju[j] = baju[j+1];
                }
                (*jumlah)--;
                cout << "Data berhasil dihapus!" << endl;
                return;
            }
        }
        throw "Data tidak ditemukan";
    }
    catch(const char* err){
        cout << "Error: " << err << endl;
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
            else if(pilih == 3){
                int p;
                cout << endl << "1. Cari ID" << endl;
                cout << "2. Cari Nama" << endl;
                cout << "Pilih: ";
                cin >> p;

                if(p < 1 || p > 2) throw "Pilihan search tidak valid";

                if(p == 1){
                    sortingID(baju, jumlah);
                    string id;
                    cout << "Masukkan ID: ";
                    cin >> id;

                    int idx = binarySearch(baju, jumlah, id);

                    if(idx != -1)
                        cout << "Data ditemukan: " << baju[idx].nama_baju << endl;
                    else
                        cout << "Data tidak ditemukan" << endl;
                }
                else{
                    string nama;
                    cout << "Masukkan Nama: ";
                    cin >> nama;

                    int idx = sequentialSearch(baju, jumlah, nama);

                    if(idx != -1)
                        cout << "Data ditemukan: " << baju[idx].nama_baju << endl;
                    else
                        cout << "Data tidak ditemukan" << endl;
                }
            }
            else if(pilih == 4){
                string id;
                cout << "Masukkan ID: ";
                cin >> id;
                updateData(baju, jumlah, id);
            }
            else if(pilih == 5){
                string id;
                cout << "Masukkan ID: ";
                cin >> id;
                hapusData(baju, &jumlah, id);
            }
            else if(pilih == 6){
                sortingID(baju, jumlah);
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