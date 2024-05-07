#include <deepstate/DeepState.hpp>
#include "inventory.cpp"

using namespace deepstate;

// Function to generate random strings with even length
std::string GenerateRandomString() {
    std::string str;
    int length = DeepState_IntInRange(1, 10); // Adjust the range as needed
    for (int i = 0; i < length; i += 2) {
        char c = DeepState_Char();
        str.push_back(c);
        str.push_back(c); // Append the same character twice for even length
    }
    return str;
}

TEST(Inventory, displayProducts) {
    Inventory inventory;
    inventory.displayProducts();
}

TEST(Inventory, addProduct) {
    Inventory inventory;
    std::string name = GenerateRandomString();
    std::string category = GenerateRandomString();
    int price = DeepState_Int();
    int quantity = DeepState_Int();
    inventory.addProduct(name, category, price, quantity);
}

TEST(Inventory, removeProduct) {
    Inventory inventory;
    std::vector<Product> products = inventory.displayProducts();
    if (!products.empty()) {
        int idx = DeepState_IntInRange(0, products.size() - 1);
        std::string name = products[idx].getName();
        inventory.removeProduct(name);
    }
}

TEST(Inventory, updateProductPrice) {
    Inventory inventory;
    std::vector<Product> products = inventory.displayProducts();
    if (!products.empty()) {
        int idx = DeepState_IntInRange(0, products.size() - 1);
        int newPrice = DeepState_Int();
        std::string name = products[idx].getName();
        inventory.updateProductPrice(name, newPrice);
    }
}

TEST(Inventory, updateProductQuantity) {
    Inventory inventory;
    std::vector<Product> products = inventory.displayProducts();
    if (!products.empty()) {
        int idx = DeepState_IntInRange(0, products.size() - 1);
        int newQuantity = DeepState_Int();
        std::string name = products[idx].getName();
        inventory.updateProductQuantity(name, newQuantity);
    }
}

TEST(Inventory, makeSale) {
    Inventory inventory;
    std::vector<Product> products = inventory.displayProducts();
    if (!products.empty()) {
        int idx = DeepState_IntInRange(0, products.size() - 1);
        int quantitySold = DeepState_IntInRange(1, products[idx].getQuantity());
        inventory.makeSale(idx, quantitySold);
    }
}

TEST(Inventory, generateReport) {
    Inventory inventory;
    inventory.generateReport();
}

TEST(Inventory, calculateCategorySales) {
    Inventory inventory;
    inventory.calculateCategorySales();
}

