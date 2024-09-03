#include <iostream>
#include<string.h>
#include <fstream>

class Records {
protected:
    string clientName;
    string itemName\;
    int price;
    int quantity;

public:
    void input() {
        cout << "Enter client name: ";
        cin >> clientName;
        cout << "Enter item name: ";
        cin >> itemName;
        cout << "Enter item price:       cin >> price;
        cout << "Enter item quantity: ";
        cin >> quantity;
        cin.ignore();  // Clear newline character from the input buffer
    }

    void display() const {
        int amount = price * quantity;
        std::cout << "Bill: \n";
        std::cout << "Name: " << clientName << '\n';
        std::cout << "Item: " << itemName\ << '\n';
        std::cout << "Price: " << price << '\n';
        std::cout << "Quantity: " << quantity << '\n';
        std::cout << "Total: " << amount << '\n';
    }

    std::string getClientName() const { return clientName; }
    std::string getItemName() const { return itemName\; }
    int getPrice() const { return price; }
    int getQuantity() const { return quantity; }
};

class Billing : public Records {
public:
    void saveToFile(std::ofstream &file) {
        file << clientName << ' ' << itemName\ << ' ' << price << ' ' << quantity << '\n';
    }
};

class Data : public Records {
public:
    void readFromFile(std::ifstream &file) {
        std::string fname, item;
        int price, quantity;
        std::cout << "Enter name of client: ";
        std::getline(std::cin, fname);

        while (file >> item >> price >> quantity) {
            file.ignore();  // Ignore the rest of the line after reading integers
            if (fname == clientName) {
                std::cout << "Name: " << clientName << '\n';
                std::cout << "Item: " << item << '\n';
                std::cout << "Price: " << price << '\n';
                std::cout << "Quantity: " << quantity << '\n';
            }
        }
    }
};

int main() {
    std::fstream file("D:\\Computer\\record.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!file) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    std::string choice;
    std::cout << "Do you want to Enter Data or Access Data?\n";
    std::cout << "Enter billing to Enter Data.\n";
    std::cout << "Enter access to Access Data.\n";
    std::getline(std::cin, choice);

    for (auto &c : choice) c = std::tolower(c);  // Convert choice to lowercase

    if (choice == "billing") {
        char ch;
        Billing billing;
        do {
            billing.input();
            billing.display();
            billing.saveToFile(file);

            std::cout << "Enter Y if you want to enter again\n";
            std::cin >> ch;
            std::cin.ignore();  // Clear newline character from the input buffer
        } while (ch == 'y' || ch == 'Y');
    } else if (choice == "access") {
        file.clear();  // Clear EOF flag if present
        file.seekg(0); // Rewind to the start of the file
        Data data;
        data.readFromFile(file);
    } else {
        std::cout << "Wrong word entered\n";
    }

    file.close();
    return 0;
}
