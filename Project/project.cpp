#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Records {
protected:
    string clientName;
    string itemName;
    int price;
    int quantity;
    int amount;

public:
    void input() {
        cout<<"Enter client name: ";
        getline(cin, clientName);
        cout<<"Enter item name:";
        getline(cin, itemName);
        cout<<"Enter item price:";
        cin>>price;
        cout<<"Enter item quantity:";
        cin>>quantity;
    }

    void display() {
        amount = price * quantity;
        cout<<"Bill:"<<endl;
        cout<<"Name:"<<clientName<<endl;
        cout<<"Item:"<<itemName<<endl;
        cout<<"Price:"<<price<<endl;
        cout<<"Quantity:"<<quantity<<endl;
        cout<<"Total:"<<amount<<endl;
    }
};

class Billing : public Records {
public:
    void savetoFile(fstream &file) {

        file.seekp(0, ios::end);
        file<<clientName<<" "<<itemName<<" "<<price<<" "<<quantity<<endl;
    }

    void readFromFile(fstream &file) {
        string fname, item;
        int price, quantity;

        cout<<"Enter name of client:";
        getline(cin, fname);

        while (file) {

            file>>clientName;
            file>>itemName;
            file>>price;
            file>>quantity;

            if (fname == clientName) {
                cout<<"Name:"<<clientName<<endl;
                cout<<"Item:"<<itemName<<endl;
                cout<<"Price:"<<price<<endl;
                cout<<"Quantity:"<<quantity<<endl;
            }
        }
    }
};

int main() {
    string choice;
    char ch;

    Billing b;

    fstream file;
    file.open("record.txt", ios::in | ios::out | ios::app);

    cout<<"Do you want to Enter Data or Access Data?"<<endl;
    cout<<"Enter billing to Enter Data."<<endl;
    cout<<"Enter access to Access Data."<<endl;
    cin>>choice;

    if (choice == "billing") {
        do {
            b.input();
            b.display();
            b.savetoFile(file);

            cout << "Enter Y if you want to enter again\n";
            cin >> ch;
            cin.ignore();
        } while (ch == 'y' || ch == 'Y');

    } else if (choice == "access") {

        file.seekg(0);
        b.readFromFile(file);
        
    } else {
        cout << "Wrong word entered\n";
    }

    file.close();
    return 0;
}
