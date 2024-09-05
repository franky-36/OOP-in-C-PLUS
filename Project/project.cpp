#include <iostream>
#include<string>
#include <fstream>

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
        cin>>clientName;
        cout<<"Enter item name:";
        cin>>itemName;
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
    void savetoFile(ofstream &file) {
        file << clientName << ' ' << itemName\ << ' ' << price << ' ' << quantity << '\n';
    }

    void readFromFile(ifstream &file) {
        string fname, item;
        int price, quantity;
        cout << "Enter name of client: ";
        getline(cin, fname);

        while (file >> item >> price >> quantity) {
            file.ignore();  // Ignore the rest of the line after reading integers
            if (fname == clientName) {
                cout << "Name: " << clientName << '\n';
                cout << "Item: " << item << '\n';
                cout << "Price: " << price << '\n';
                cout << "Quantity: " << quantity << '\n';
            }
        }
    }
};

int main() {
    fstream file("D:\\Computer\\record.txt", ios::in | ios::out | ios::app);
    if (!file) {
        cerr << "Failed to open file\n";
        return 1;
    }

    string choice;
    cout<<"Do you want to Enter Data or Access Data?"<<endl;
    cout<<"Enter billing to Enter Data."<<endl;
    cout<<"Enter access to Access Data."<<endl;
    cin>>choice;

    if (choice == "billing") {

        char ch;
        do {
            b.input();
            b.display();
            b.saveToFile(file);

            cout << "Enter Y if you want to enter again\n";
            cin >> ch;
            cin.ignore();
        } while (ch == 'y' || ch == 'Y');

    } else if (choice == "access") {
        file.clear();  // Clear EOF flag if present
        file.seekg(0);
        b.readFromFile(file);
    } else {
        cout << "Wrong word entered\n";
    }

    file.close();
    return 0;
}
