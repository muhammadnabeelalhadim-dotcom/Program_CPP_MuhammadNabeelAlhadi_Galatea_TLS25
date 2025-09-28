#include <iostream>  
#include <string>    

using namespace std;  

// Fungsi untuk membalik string
string balikString(string kata) {
    int panjang = kata.length();  
    for (int i = 0; i < panjang / 2; i++) {
        char simpan = kata[i];  
        kata[i] = kata[panjang - 1 - i];  // Tukar dengan akhir
        kata[panjang - 1 - i] = simpan;  
    }
    return kata; 
}

// Fungsi untuk cek huruf vokal
bool vokal(char huruf) {
    return (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u' ||
            huruf == 'A' || huruf == 'E' || huruf == 'I' || huruf == 'O' || huruf == 'U');
}

// Fungsi untuk buat kata sandi dari kata asli
string buatSandi(string kataAsli) {
    if (kataAsli.empty()) return "";  // Jika kosong

    //Hilangkan vokal
    string konsonan = "";  
    for (char h : kataAsli) {  
        if (!vokal(h)) {  
            konsonan += h;  
        }
    }

    // Balik konsonan
    konsonan = balikString(konsonan);

    //Ambil kode ASCII huruf pertama
    int kodeAscii = (int)kataAsli[0];  // ASCII sebagai integer

    // Memasukkan kode ASCII di tengah
    int panjang = konsonan.length();
    int tengah = panjang / 2;  // Posisi tengah
    string sandi = konsonan.substr(0, tengah) + to_string(kodeAscii) + konsonan.substr(tengah);

    return sandi;  
}

// Fungsi untuk dapatkan konsonan dari sandi
string dapatkanKonsonan(string sandi) {
    if (sandi.length() < 2) return "";  

    int panjang = sandi.length();
    int tengah = panjang / 2;

    // Ambil kode ASCII (2 digit)
    string kodeStr = sandi.substr(tengah - 1, 2);
    int kodeAscii = stoi(kodeStr);  // Ubah ke integer

    // Hapus kode dari sandi
    string konsonanBalik = sandi.substr(0, tengah - 1) + sandi.substr(tengah + 1);

    // Balik kembali
    string konsonan = balikString(konsonanBalik);

    return konsonan; 
}

int main() {
    cout << "Masukkan kata asli: ";
    string kata;
    cin >> kata; 
    string sandi = buatSandi(kata);  // Buat sandi
    cout << "Kata asli: " << kata << endl;
    cout << "Sandi: " << sandi << endl;

    return 0;
}
