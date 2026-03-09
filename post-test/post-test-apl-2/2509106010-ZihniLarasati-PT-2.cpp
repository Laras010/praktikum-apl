#include <iostream>
using namespace std;

int main() {
    string Username;
    string Password;
    string Usernamecorrect = "Larasati";
    string Passwordcorrect = "010";
    int percobaan = 0;


     while (percobaan < 3){
        cout << "===========================" << endl;
        cout << "           LOGIN          " << endl;
        cout << "===========================" << endl;
        cout << "Masukan Username Anda : ";
        cin >> Username;
        cout << "Masukan Password (3 digit NIM terakhir) : ";
        cin >> Password;
        cout << endl;

    if (Username == Usernamecorrect && Password == Passwordcorrect){
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

}
}

