#include<iostream>
#include<string>
using namespace std;
/*      Nama  : Bagas Ahmad Sadewa
        Kelas : TI 2020 B
        Nim   : 20051204016
*/
struct data{
    char nama[20];
    int tugas, totalTugas, partisipasi, uts, uas, hasil;
    long long int nim;
};

int nilaiAkhir(int i, data mhs[]){
    int nilai = (mhs[i].totalTugas*0.3) + (mhs[i].partisipasi*0.2) + (mhs[i].uts*0.2) + (mhs[i].uas*0.3);
    return nilai;
}

int main(){
    struct data mhs[100];
    int jumlahSiswa, tugas;
    char lagi;
    do{
        system("cls");
        cout << "===]           PRAKTIKUM 1          [===\n";
        cout << "===] Program Menghitung Nilai Akhir [===\n\n";
        cout << "Jumlah Siswa: ";
        cin >> jumlahSiswa;
        cout << endl;
        for(int i=1; i<=jumlahSiswa; i++){
            int totalTugas = 0;
            cout << "==] Data siswa ke-" << i << endl;
            cout << "Nama       : ";
            cin.ignore();
            gets(mhs[i].nama);
            cout << "Nim        : ";
            cin >> mhs[i].nim;
            cout << endl;
            for(int j=1; j<=3; j++){
                cout << "Tugas " << j << "    : ";
                cin >> tugas;
                totalTugas = totalTugas + tugas;
            }cout << endl;
            mhs[i].totalTugas = totalTugas /3 ;
            cout << "Nilai Tugas: " << mhs[i].totalTugas << endl;
            cout << "Partisipasi: ";
            cin >> mhs[i].partisipasi;
            cout << "Nilai UTS  : ";
            cin >> mhs[i].uts;
            cout << "Nilai UAS  : ";
            cin >> mhs[i].uas;
            mhs[i].hasil = nilaiAkhir(i, mhs);
            cout << "Nilai Akhir: " << mhs[i].hasil << endl;
            cout << "--------------------------\n";
        }
        cout << "Menghitung lagi (y/n) ? ";
        cin >> lagi;
    }while(lagi == 'y' || lagi == 'Y');
    return 0;
}
