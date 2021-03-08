/*  Nama : Bagas Ahmad Sadewa
    Nim  : 20051204016
    Kelas: TI 2020 B          */

#include <iostream>
#include <string>
using namespace std;

const int maks = 10;
string arrData[maks];
int top = 0;

bool isFull(){
    if(top == maks){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(){
    if(top == 0){
        return true;
    }else{
        return false;
    }
}

int countArr(){
    if(isEmpty()){
        return 0;
    }else{
        return top;
    }
}

void pushArr(string data){
    if(isFull()){
        cout << "Data penuh \n";
    }else{
        arrData[top] = data;
        top++;
    }
}

void changeArr(int posisi, string data){
    if(isEmpty()){
        cout << " Data Kosong \n";
    }else{
        int index = top;
        for(int i=0; i < posisi; i++){
            index--;
        }
        arrData[index] = data;
    }
}

void displayArr(){
    cout << " Data Stack : \n";
    for(int i=(maks-1); i>=0; i--){
        if(arrData[i] != ""){
            cout << "data : " << arrData[i] << endl;
        }
    }
}

void popArr(){
    if(isEmpty()){
        cout << " Data Kosong \n";
    }else{
        arrData[top-1] = "";
        top--;
    }
}

void destroyArr(){
    for(int i=0; i < top; i++){
        arrData[i] = "";
    }
}

int main(){
    int menu, index;
    string data;
    while(true){
        cout << endl;
        cout << "=====================================\n"
             << "  Struktur Data dan Algoritma Stack  \n"
             << "=====================================\n"
             << "1. Input Data \n"
             << "2. Delete Data \n"
             << "3. Display Data \n"
             << "4. Delete All Data \n"
             << "5. Change Data \n"
             << "6. Exit \n"
             << "Pilih Menu : ";
        cin >> menu;
        cout << endl;

        switch(menu){
            case 1:
                cout << "Input Data : ";
                cin >> data;
                pushArr(data);
                break;

            case 2:
                cout << "Delete data : " << arrData[top];
                popArr();
                break;

            case 3:
                cout << "Display Data : \n";
                displayArr();
                break;
            
            case 4:
                cout << "Delete All \n";
                destroyArr();
                break;
            
            case 5:
                cout << "Change data \n";
                cout << "Masukkan index     : "; cin >> index;
                cout << "Masukkan data baru : "; cin >> data;
                changeArr(index, data);
                break;

            case 6:
                return 0;
        }

        cout << "Data kosong : " << isEmpty() << endl;
        cout << "Data penuh  : " << isFull() <<endl;
        cout << "Total data  : " << countArr() << endl;
    }
    
    cin.get();
    return 0;
}