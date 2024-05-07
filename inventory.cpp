#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Product {
private:
    string name;
    string category;
    int price;
    int quantity;
    vector<int> sales;

public:
    Product(string _name, string _category, int _price, int _quantity) {
        name = _name;
        category = _category;
        price = _price;
        quantity = _quantity;
    }

    void updatePrice(int newPrice) {
        price = newPrice;
    }

    void updateQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    void addSale(int quantitySold) {
        sales.push_back(quantitySold);
    }

    string getName() {
        return name;
    }

    string getCategory() {
        return category;
    }

    int getPrice() {
        return price;
    }

    int getQuantity() {
        return quantity;
    }

    vector<int> getSales() {
        return sales;
    }
};

class Inventory {
public:
    vector<Product> products;

    Inventory() {
        // Pre-populate with some initial products
        addProduct("Laptop", "Electronics", 1000, 10);
        addProduct("Phone", "Electronics", 500, 20);
        addProduct("T-shirt", "Clothing", 20, 50);
        addProduct("Shoes", "Footwear", 50, 30);
    }

    void addProduct(string name, string category, int price, int quantity) {
        products.push_back(Product(name, category, price, quantity));
        cout << "Product added successfully!" << endl;
    }

    void removeProduct(string name) {
        for (int i = 0; i < products.size(); ++i) {
            if (products[i].getName() == name) {
                products.erase(products.begin() + i);
                cout << "Product removed successfully!" << endl;
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    void updateProductPrice(string name, int newPrice) {
        for (int i = 0; i < products.size(); ++i) {
            if (products[i].getName() == name) {
                products[i].updatePrice(newPrice);
                cout << "Price updated successfully!" << endl;
                return;
            }
        }
        cout << "Product not found." << endl;
    }

    void updateProductQuantity(string name, int newQuantity) {
        for (int i = 0; i < products.size(); ++i) {
            if (products[i].getName() == name) {
                products[i].updateQuantity(newQuantity);
                cout << "Quantity updated successfully!" << endl;
                return;
            }
        }
        cout << "Product not found." << endl;
    }

   vector<Product> displayProducts() {
    vector<string> productNames;
    cout << "Available Products:" << endl;
    for (int i = 0; i < products.size(); ++i) {
        cout << i + 1 << ". " << products[i].getName() << " (" << products[i].getCategory() << "): $"
             << products[i].getPrice() << " (" << products[i].getQuantity() << " in stock)" << endl;
        productNames.push_back(products[i].getName());
    }
    cout << endl;
    return products;  // Return vector of product names
}



    int getInventoryValue() {
        int totalValue = 0;
        for (int i = 0; i < products.size(); ++i) {
            totalValue += products[i].getPrice() * products[i].getQuantity();
        }
        return totalValue;
    }

    void generateReport() {
        cout << "Inventory Report:" << endl;
        for (int i = 0; i < products.size(); ++i) {
            cout << products[i].getName() << " (" << products[i].getCategory() << "): $"
                 << products[i].getPrice() << " (" << products[i].getQuantity() << " in stock)" << endl;
        }
        cout << "Total Inventory Value: $" << getInventoryValue() << endl;
    }

    void makeSale(int choice, int quantitySold) {
        if (choice >= 1 && choice <= products.size()) {
            string name = products[choice - 1].getName();
            if (products[choice - 1].getQuantity() >= quantitySold) {
                products[choice - 1].updateQuantity(products[choice - 1].getQuantity() - quantitySold);
                products[choice - 1].addSale(quantitySold);
                cout << quantitySold << " units of " << name << " sold successfully!" << endl;
            } else {
                cout << "Insufficient stock to make sale." << endl;
            }
        } else {
            cout << "Invalid product number." << endl;
        }
    }

    map<string, int> calculateCategorySales() {
        map<string, int> categorySales;
        for (int i = 0; i < products.size(); ++i) {
            if (categorySales.find(products[i].getCategory()) == categorySales.end()) {
                categorySales[products[i].getCategory()] = 0;
            }
            vector<int> sales = products[i].getSales();
            for (int j = 0; j < sales.size(); ++j) {
                categorySales[products[i].getCategory()] += sales[j];
            }
        }
        return categorySales;
    }
};

void handleInventory(Inventory &inventory) {
    while (true) {
        cout << "1. Display Products" << endl;
        cout << "2. Add Product" << endl;
        cout << "3. Remove Product" << endl;
        cout << "4. Update Product Price" << endl;
        cout << "5. Update Product Quantity" << endl;
        cout << "6. Make Sale" << endl;
        cout << "7. Generate Report" << endl;
        cout << "8. Category-wise Sales" << endl;
        cout << "9. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.displayProducts();
                break;
            case 2: {
                string name, category;
                int price, quantity;
                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter product category: ";
                cin >> category;
                cout << "Enter product price: ";
                cin >> price;
                cout << "Enter product quantity: ";
                cin >> quantity;
                inventory.addProduct(name, category, price, quantity);
                break;
            }
            case 3: {
                string name;
                cout << "Enter product name to remove: ";
                cin >> name;
                inventory.removeProduct(name);
                break;
            }
            case 4: {
                string name;
                int newPrice;
                cout << "Enter product name to update price: ";
                cin >> name;
                cout << "Enter new price: ";
                cin >> newPrice;
                inventory.updateProductPrice(name, newPrice);
                break;
            }
            case 5: {
                string name;
                int newQuantity;
                cout << "Enter product name to update quantity: ";
                cin >> name;
                cout << "Enter new quantity: ";
                cin >> newQuantity;
                inventory.updateProductQuantity(name, newQuantity);
                break;
            }
            case 6: {
                inventory.displayProducts();
                int productChoice, quantitySold;
                cout << "Enter product number to make sale: ";
                cin >> productChoice;
                cout << "Enter quantity sold: ";
                cin >> quantitySold;
                if (productChoice >= 1 && productChoice <= inventory.products.size()) {
                    string name = inventory.products[productChoice - 1].getName();
                    inventory.makeSale(productChoice, quantitySold);
                } else {
                    cout << "Invalid product number." << endl;
                }
                break;
            }
            case 7:
                inventory.generateReport();
                break;
            case 8: {
                map<string, int> categorySales = inventory.calculateCategorySales();
                cout << "Category-wise Sales:" << endl;
                for (auto it = categorySales.begin(); it != categorySales.end(); ++it) {
                    cout << it->first << ": " << it->second << endl;
                }
                break;
            }
            case 9:
                cout << "Exiting..." << endl;
                return;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 9." << endl;
        }
    }
}

int main() {
    Inventory inventory;

    handleInventory(inventory);
    return 0;
}

