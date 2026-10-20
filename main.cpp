#include <iostream>
#include <string>

using namespace std;

struct Price {
    string productName;
    string storeName;
    double price;
};

int main() {
    const int SIZE = 8;
    Price prices[SIZE];

    cout << "=== Введення даних про товари ===" << endl;
    for (int i = 0; i < SIZE; ++i) {
        Price* itemPtr = &prices[i]; 

        cout << "\nТовар №" << i + 1 << ":" << endl;
        cout << "Назва товару: ";
        getline(cin >> ws, itemPtr->productName);

        cout << "Назва магазину: ";
        getline(cin, itemPtr->storeName);

        cout << "Вартість (грн): ";
        cin >> itemPtr->price;
    }

    double minPrice, maxPrice;
    cout << "\n=== Пошук товарів за ціновим діапазоном ===" << endl;
    cout << "Введіть мінімальну вартість: ";
    cin >> minPrice;
    cout << "Введіть максимальну вартість: ";
    cin >> maxPrice;

    cout << "\nТовари у ціновому діапазоні від " << minPrice << " до " << maxPrice << " грн:" << endl;
    bool found = false;

    for (int i = 0; i < SIZE; ++i) {
        Price* itemPtr = &prices[i];
        if (itemPtr->price >= minPrice && itemPtr->price <= maxPrice) {
            cout << "- Товар: " << itemPtr->productName 
                 << " | Магазин: " << itemPtr->storeName 
                 << " | Вартість: " << itemPtr->price << " грн" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Товарів у зазначеному ціновому діапазоні не знайдено." << endl;
    }

    string targetStore;
    cout << "\n=== Застосування 20% знижки ===" << endl;
    cout << "Введіть назву магазину для надання знижки 20%: ";
    getline(cin >> ws, targetStore);

    bool storeFound = false;
    for (int i = 0; i < SIZE; ++i) {
        Price* itemPtr = &prices[i];
        if (itemPtr->storeName == targetStore) {
            itemPtr->price *= 0.8; 
            storeFound = true;
        }
    }

    if (storeFound) {
        cout << "\nОновлений список товарів у магазині \"" << targetStore << "\" зі знижкою 20%:" << endl;
        for (int i = 0; i < SIZE; ++i) {
            Price* itemPtr = &prices[i];
            if (itemPtr->storeName == targetStore) {
                cout << "- Товар: " << itemPtr->productName 
                     << " | Нова вартість: " << itemPtr->price << " грн" << endl;
            }
        }
    } else {
        cout << "Магазин з назвою \"" << targetStore << "\" не знайдено." << endl;
    }

    return 0;
}