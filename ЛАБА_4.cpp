#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

template <typename T1, typename T2>
class Pair {
public:
    Pair() {}
    Pair(const T1& first, const T2& second) : first(first), second(second) {}

    void displayPair() const {
        std::cout << first << ": " << second << std::endl;
    }

    void savePairToFile(std::ofstream& outFile) const {
        outFile << first << " " << second << " ";
    }

private:
    T1 first;
    T2 second;
};

class MenuItem {
public:

    MenuItem(const std::string& name, double& price, const std::string& type)
        : name(name), price(price), type(type) {}

    ~MenuItem() {}

    const std::string& getName() const {
        return name;
    }

    const std::string& getType() const {
        return type;
    }

    const double& getPrice() const {
        return price;
    }

    void setFirstName(const std::string& newName) {
        name = newName;
    }

    void setLastName(const std::string& newType) {
        type = newType;
    }

    void setPrice(const double& newPrice) {
        price = newPrice;
    }

    void saveToFile(std::ofstream& outFile) const {
        outFile << name << " " << price << " " << type << " ";
    }

    static bool compareByPrice(const MenuItem* menuitem1, const MenuItem* menuitem2) {
        return menuitem1->getPrice() < menuitem2->getPrice();
    }

    void displayInfo() const {
        std::cout << "Название: " << name << std::endl;
        std::cout << "Цена: " << price << std::endl;
        std::cout << "Тип: " << type << std::endl;
    }

private:

    std::string name;
    double price;
    std::string type;

};

void saveDishesToFile(const std::vector<MenuItem*>& dishes, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
        return;
    }

    for (const auto* student : dishes) {
        student->saveToFile(outFile);
    }

    outFile.close();
}

/*
void saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto* item : ) {
            file << item.getName() << " " << item.getPrice() << " " << item.getType() << std::endl;
        }
        file.close();
        std::cout << "Меню сохранено в файл: " << filename << std::endl;
    }
    else {
        std::cerr << "Ошибка открытия файла" << std::endl;
    }
}
*/

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<MenuItem*> dishes;

    int choice;
    std::string filename;

    do {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Добавить блюдо" << std::endl;
        std::cout << "2. Найти блюдо" << std::endl;
        std::cout << "3. Огласи меню" << std::endl;
        std::cout << "4. Сохранить в файл" << std::endl;
        std::cout << "5. Сортировать блюда по цене" << std::endl;
        std::cout << "6. Выход" << std::endl;

        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name, type;
            std::double_t price;
            //std::double price;
            std::cout << "Введите данные блюда:" << std::endl;
            std::cout << "Название: ";
            std::cin >> name;
            std::cout << "Цена: ";
            std::cin >> price;
            std::cout << "Тип: ";
            std::cin >> type;

            dishes.push_back(new MenuItem(name, price, type));

            break;
        }

        case 2: {
            std::string name;
            std::cout << "Введите название блюда:" << std::endl;
            std::cout << "Название: ";
            std::cin >> name;

            auto it = std::find_if(dishes.begin(), dishes.end(), [&](const MenuItem* dish) {
                return dish->getName() == name;
                });

            if (it != dishes.end()) {
                (*it)->displayInfo();
            }
            else {
                std::cout << "Такого блюда нет в меню." << std::endl;
            }

            break;
        }
        case 3: {
            std::cout << "Меню:" << std::endl;
            for (const auto* dish : dishes) {
                dish->displayInfo();
            }
            break;
        }
        case 4: {
            std::cout << "Введите имя файла для сохранения данных: ";
            std::cin >> filename;
            saveDishesToFile(dishes, filename);
            break;
        }
        case 5: {
            std::sort(dishes.begin(), dishes.end(), MenuItem::compareByPrice);
            std::cout << "Меню отсортировано по цене." << std::endl;
            break;
        }
        case 6:
            std::cout << "Выход." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор." << std::endl;
        }
    } while (choice != 8);

    for (const auto* dish : dishes) {
        delete dish;
    }

    return 0;
}