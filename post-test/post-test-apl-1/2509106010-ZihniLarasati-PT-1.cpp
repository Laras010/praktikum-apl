#include <iostream>
using namespace std;


int main(){
    string nama;
    string namacorect = "Laras";
    string password;
    string passwordcorect = "010";
    int percobaan = 0;

    while (percobaan < 3){
        cout << "===========================" << endl;
        cout << "           LOGIN          " << endl;
        cout << "===========================" << endl;
        cout << "Masukan Nama Anda : ";
        cin >> nama;
        cout << "Masukan Password (3 digit NIM terakhir) : ";
        cin >> password;
        cout << endl;

    if (nama == namacorect && password == passwordcorect){
        cout << "===== LOGIN BERHASIL =====" << endl;
        break;
    }else {
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

do {
    cout << "===== MENU UTAMA =====" << endl;
    cout << "(1) Konversi jam ke menit dan detik" << endl;
    cout << "(2) Konversi menit ke jam dan detik" << endl;
    cout << "(3) Konversi detik ke jam dan menit" << endl;
    cout << "(4) Keluar" << endl;

    cout << "Pilih menu (1-4) : ";
    cin >> pilih;

    if (pilih == 1) {
        int jam;
        cout << "Masukkan jam : ";
        cin >> jam;
        cout << "Hasil : " << jam*60 << " menit dan " << jam*3600 << " detik " << endl;
    }
    else if (pilih == 2) {
        int menit;
        cout << "Masukan menit : ";
        cin >> menit;
        cout << "Hasil : " << menit/60 << " jam dan " << menit*60 << " detik " << endl;
    }
    else if (pilih == 3) {
        int detik;
        cout << "Masukan detik : ";
        cin >> detik;
        cout << "Hasil : " << detik/3600 << " jam dan " << detik/60 << " menit " << endl;
    }
    else if (pilih == 4) {
        cout << "Selesai..." << endl;
    }
    else {
        cout << "Pilihan tidak ada..." << endl;
    }

} while (pilih !=4);

    return 0;
}