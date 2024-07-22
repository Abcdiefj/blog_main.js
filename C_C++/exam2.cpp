#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Product {
public:
    string name;
    string weight;
    string manufacturingDate;
    string expiryDate;
    string address;
    int purchasePrice;
    int sellingPrice;
    int getProfitPerUnit() const { return sellingPrice - purchasePrice; }

    // Constructors (consider adding for initialization)
};

class MilkPowder : public Product {
public:
    MilkPowder() {
        name = "Milk Powder";
        weight = "100g";
    }
};

class PreMadeMilk : public Product {
public:
    PreMadeMilk() {
        name = "Pre-Made Milk";
        weight = "100ml";
    }
};

class CondensedMilk : public Product {
public:
    CondensedMilk() {
        name = "Condensed Milk";
        weight = "100g";
    }
};

class Customer {
public:
    long long phoneNumber;
    string name;
    string address;
    string tier; // "VIP" or "Normal"

    // Getters and setters (consider adding for encapsulation)

    friend istream& operator>>(istream& in, Customer& c) {
        cout << "Enter phone number: ";
        in >> c.phoneNumber;
        cout << "Enter name: ";
        getline(in, c.name); // Handle spaces in name
        cout << "Enter address: ";
        getline(in, c.address);
        cout << "Enter tier (VIP or Normal): ";
        getline(in, c.tier);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Customer& c) {
        out << c.phoneNumber << " " << c.name << " " << c.address << endl;
        out << "Tier: \"" << c.tier << "\"" << endl;
        return out;
    }
};

class Order {
public:
    long long phoneNumber;
    long long totalPrice;
    long long discount;
    long long finalPrice;
    time_t orderDate;

    // Getters and setters (consider adding for encapsulation)

    void calculateDiscount(const Customer& customer, const MilkPowder& mp, int mpQuantity,
                           const PreMadeMilk& pmm, int pmmQuantity, const CondensedMilk& cm, int cmQuantity) {
        totalPrice = mpQuantity * mp.getProfitPerUnit() + pmmQuantity * pmm.getProfitPerUnit() +
                     cmQuantity * cm.getProfitPerUnit();
        discount = 0;

        if (customer.tier == "VIP") {
            discount += totalPrice * 5 / 100; // 5% discount for VIP
        }

        discount += mpQuantity * mp.sellingPrice * 3 / 100 + // Bulk discount for Milk Powder
                    cmQuantity * cm.sellingPrice * 5 / 100 +  // Bulk discount for Condensed Milk
                    pmmQuantity * pmm.sellingPrice * 5 / 100;   // Bulk discount for Pre-Made Milk
    }

    void calculateFinalPrice() {
        finalPrice = totalPrice - discount;
    }

    void printReceipt() const {
        cout << "Order details:" << endl;
        cout << *this; // Use overloaded operator<< for Customer
        cout << "Order date: " << ctime(&orderDate) << endl;
        cout << "Total price: " << totalPrice << endl;
        cout << "Discount: " << discount << endl;
        cout << "Final price: " << finalPrice << endl;
    }
};

class InventoryManager {
private:
    vector<MilkPowder> milkPowders;
    vector<PreMadeMilk> preMadeMilks;
    vector<CondensedMilk> condensedMilks;
    vector<Customer> customers;
    vector<Order> orders;

public:
    void addMilkPowder(const MilkPowder& mp) {
        milkPowders.push_back(mp);
    }

    void addPreMadeMilk(const PreMadeMilk& pmm) {
        preMadeMilks.push_back(pmm);
    }

    void condensedMilks(const CondensedMilk& cdsm ){
        condensedMilks.push_back(cdsm);
    }
