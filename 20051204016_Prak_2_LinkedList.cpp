#include <iostream>
#include <string>
using namespace std;
/*  NAMA  : BAGAS AHMAD SADEWA
    NIM   : 20051204016
    KELAS : TIB 2020
*/
struct node{
    long nim;
    string nama;
    string prodi;
    node *next;
};

node *head; 

void awal(){
    head = NULL;
}

void inputData(long inputNim, string inputNama, string inputProdi){
    node *cur  = new node;
    node *prev = new node;

    node *baru = new node;
    baru -> nim   = inputNim;
    baru -> nama  = inputNama;
    baru -> prodi = inputProdi;

    prev = NULL; cur = head; 

    if(head == NULL){   //jika list masih kosong
        head =  baru;   //var baru sebagai head
        baru -> next = NULL;
    }
    //jika list tidak kosong
    else{
        while(cur != NULL && cur -> nim < inputNim){
            prev = cur;
            cur  = cur -> next; 
        }

        if(cur == NULL){
            prev -> next = baru;
            baru -> next = NULL;
        }

        else if(prev == NULL){
            baru -> next = cur;
            head = baru;
        }

        else{
            prev -> next = baru;
            baru -> next = cur;
        }
    }
}
void hapus(long inputNim){
    node *cur = new node;
    node *prev = new node;

    prev = NULL; cur = head;

    while(cur != NULL){
        if(cur -> nim == inputNim){
            if(prev == NULL){
                head = head -> next;
                delete cur;
                break;
            }
            prev -> next = cur -> next;
            delete cur;
            break;
        }
        else{
            prev = cur;
            cur  = cur -> next; 
        }
    }

    if(cur == NULL){
        cout << "\n ----[x]   Maaf, Data tidak ada   [x]---- \n";
    }
}

void tampilkan(){
    if(head == NULL){
        cout << "\n ----[x]   Data masih kosong   [x]---- \n";
    }
    for(node *cur = head; cur != NULL ; cur = cur -> next){
        cout << "Nim   : " << cur -> nim << endl;
        cout << "Prodi : " << cur -> prodi << endl << endl; 
        cout << "Nama  : " << cur -> nama << endl;
    }
}

int main(){
    awal(); 
    char menu;
    while(true){
        cout << "=====]   DATA MAHASISWA   [=====\n";
        cout " 2. Delete Data \n";
        cout " 1. Input Data \n";
        cout " 3. Lihat Data \n";
        cout " ketik x untuk keluar \n";
        cout "================================\n";
        cin >> menu;
        cout << endl;
        int jml; long inputNim; string inputNama, inputProdi;
        switch(menu){
            case '1':
                cout << "Jumlah mahasiswa yg diinputkan : ";
                cin >> jml;
                for(int i=1; i<=jml; i++){
                    cout << "Data [" << i <<"] \n";
                    cout << "Masukkan Nim   : ";
                    cin >> inputNim;
                    cout << "Masukkan Nama  : ";
                    cin >> inputNama;
                    cout << "Masukkan Prodi : ";
                    cin >> inputProdi;
                    cout << endl;
                    inputData(inputNim, inputNama, inputProdi);
                }
                break;

            case '2':
                cout << "Masukkan NIM untuk menghapus data : ";
                cin >> inputNim;
                hapus(inputNim);
                break;

            case '3':
                tampilkan();
                break;

            case 'x': 
                cout << "=====]     Terimakasih    [===== \n";
                return 0;
                break;
            
            default :
                cout << "    [x] Salah memilih menu [x] \n\n";
                break;
        } 
    }
    return 0;
}