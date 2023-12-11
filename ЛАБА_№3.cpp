#include <iostream>
#include <fstream>
#include <string>

struct Bludo {
    std::string fullName;
    std::string type;
    int cost;
};

void addBludoToFile(const Bludo& bludo) {
    std::ofstream outFile("bludoo.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << bludo.fullName << "," << bludo.type << "," << bludo.cost << std::endl;
        outFile.close();
        std::cout << "Блюдо добавлено." << std::endl;
    }
    else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }
}

void searchBludoByName(const std::string& name) {
    std::ifstream inFile("bludoo.txt");
    if (inFile.is_open()) {
        std::string line;
        bool found = false;
        while (std::getline(inFile, line)) {
            size_t pos = line.find(',');
            std::string fullName = line.substr(0, pos);
            if (fullName == name) {
                std::cout << "Найдено блюдо: " << line << std::endl;
                found = true;
                break;
            }
        }
        inFile.close();
        if (!found) {
            std::cout << "Блюдо с таким именем не найдено" << std::endl;
        }
    }
    else {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
    }
}

void sortBludoByCost() {
    std::ifstream inFile("bludoo.txt");
    if (inFile.is_open()) {
        std::string lines[100]; 
        int count = 0;
        std::string line;
        while (std::getline(inFile, line)) {
            lines[count] = line;
            count++;
        }
        inFile.close();
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                size_t pos1 = lines[j].find_last_of(',');
                size_t pos2 = lines[j + 1].find_last_of(',');
                double grade1 = std::stod(lines[j].substr(pos1 + 1));
                double grade2 = std::stod(lines[j + 1].substr(pos2 + 1));
                if (grade1 < grade2) {
                    std::swap(lines[j], lines[j + 1]);
                }
            }
        }
        // Запись отсортированных данных обратно в файл
        std::ofstream outFile("bludoo.txt");
        if (outFile.is_open()) {
            for (int i = 0; i < count; i++) {
                outFile << lines[i] << std::endl;
            }
            outFile.close();
            std::cout << "Блюдо отсортированы по стоимости." << std::endl;
        }
        else {
            std::cerr << "Не удалось открыть файл для записи." << std::endl;
        }
    }
    else {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    std::string name;

    do {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Добавить блюдо" << std::endl;
        std::cout << "2. Поиск блюда по названию" << std::endl;
        std::cout << "3. Сортировать блюда по цене" << std::endl;
        std::cout << "0. Выйти" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cin.ignore();
            std::string fullName, type;
            int cost;
            std::cout << "Введите название блюда: ";
            std::getline(std::cin, fullName);
            if (fullName.empty()) {
                std::cout << "Ввод прерван." << std::endl;
                break;
            }
            std::cout << "Введите тип блюда: ";
            std::getline(std::cin, type);
            std::cout << "Введите стоимость блюда: ";
            std::cin >> cost;
            Bludo newBludo = { fullName, type, cost};
            addBludoToFile(newBludo);
            break;
        }
        case 2: {
            std::cin.ignore();
            std::cout << "Введите название блюда для поиска: ";
            std::getline(std::cin, name);
            searchBludoByName(name);
            break;
        }
        case 3: {
            sortBludoByCost();
            break;
        }
        case 0: {
            std::cout << "Программа завершена." << std::endl;
            break;
        }
        default: {
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
