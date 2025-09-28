#include <iostream>
#include <string>

using namespace std;

string getLampuWarna(int detik) {
    int offset = 48;
    int siklus = 103;
    int pos = (detik - offset) % siklus;
    if (pos < 0) pos += siklus;
    return (pos < 80) ? "Merah" : (pos < 100) ? "Hijau" : "Kuning";
}

int main() {
    int detik[] = {80, 135, 150, 212};
    int n = sizeof(detik) / sizeof(detik[0]);
    
    for (int i = 0; i < n; i++) {
        cout << "Pada detik ke-" << detik[i] << ", lampu menunjukkan warna: " << getLampuWarna(detik[i]) << endl;
    }
    
    return 0;
}
