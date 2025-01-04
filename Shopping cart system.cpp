#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
using namespace std;

struct Item {
    int id;
    string name;
    double price;
    int quantity;
};
void addItem(vector<Item>& cart);
void viewCart(const vector<Item>& cart);
void calculateTotal(const vector<Item>& cart);
void removeItem(vector<Item>& cart);

int main() {
    vector<Item> cart; 
    int choice;

    do {
        cout << "\nShopping Cart System\n";
        cout << "1. Add Item to Cart\n";
        cout << "2. View Cart\n";
        cout << "3. Calculate Total\n";
        cout << "4. Remove Item from Cart\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addItem(cart);
            break;
        case 2:
            viewCart(cart);
            break;
        case 3:
            calculateTotal(cart);
            break;
        case 4:
            removeItem(cart);
            break;
        case 5:
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
void addItem(vector<Item>& cart) {
    Item item;
    cout << "Enter Item ID: ";
    cin >> item.id;
    cin.ignore(); 
    cout << "Enter Item Name: ";
    getline(cin, item.name);
    cout << "Enter Item Price: $";
    cin >> item.price;
    cout << "Enter Quantity: ";
    cin >> item.quantity;

    cart.push_back(item); 
    cout << "Item added to cart successfully!\n";
}
void viewCart(const vector<Item>& cart) {
    if (cart.empty()) {
        cout << "The cart is empty.\n";
        return;
    }

    cout << "\nItems in Your Cart:\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Quantity" << "\n";
    cout << "-------------------------------------------------\n";
    for (const auto& item : cart) {
        cout << left << setw(10) << item.id << setw(20) << item.name << "$" << setw(9) << item.price << item.quantity << "\n";
    }
}
void calculateTotal(const vector<Item>& cart) {
    if (cart.empty()) {
        cout << "The cart is empty. Total: $0.00\n";
        return;
    }

    double total = 0;
    for (const auto& item : cart) {
        total += item.price * item.quantity;
    }

    cout << "Total Price of Items in Cart: $" << fixed << setprecision(2) << total << "\n";
}
void removeItem(vector<Item>& cart) {
    if (cart.empty()) {
        cout << "The cart is empty. Nothing to remove.\n";
        return;
    }

    int id;
    cout << "Enter Item ID to Remove: ";
    cin >> id;

    for (auto it = cart.begin(); it != cart.end(); ++it) {
        if (it->id == id) {
            cout << "Item \"" << it->name << "\" removed from the cart.\n";
            cart.erase(it); 
            return;
        }
    }

    cout << "Item with ID " << id << " not found in the cart.\n";
}
