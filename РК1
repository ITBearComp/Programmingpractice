#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

struct Tovar {
	std::string name;
	int count;
	float oneTovar;
};

void printTovars(const Tovar* tovars, int size) {         // править
	std::cout << "Список товаров:\n";
	for (int i = 0; i < size; i++) {
		std::cout << i+1 << ". " << tovars[i].name << " - Количество:" << tovars[i].count << ", Цена за единицу: " << tovars[i].oneTovar << "\n";
	}
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int numTovar;
	std::cout << "Введите количество заказанных блюд: ";
	std::cin >> numTovar;
	cin.ignore();
	float SUMM = 0;

	// Выделение памяти для массивов с именами и возрастом студентов
	Tovar* tovars = new Tovar[numTovar];

	// Ввод имён и возрастов студентов
	for (int i = 0; i < numTovar; i++) {
		std::cout << "Введите название блюда " << i + 1 << ": ";
		std::cin >> tovars[i].name;
		std::cout << "Введите количество порций блюда " << i + 1 << ": ";
		std::cin >> tovars[i].count;
		std::cout << "Введите стоимость за порцию блюда " << i + 1 << ": ";
		std::cin >> tovars[i].oneTovar;
		std::cout << "Общая стоимость заказа: " << tovars[i].oneTovar * tovars[i].count << "\n";
		SUMM += tovars[i].oneTovar * tovars[i].count;
		cin.ignore();
	}
	// Сортировка студентов по алфавитному порядку
	std::sort(tovars, tovars + numTovar, [](const Tovar& s1, const Tovar& s2) {
		return s1.name < s2.name;
		});

	// Вывод списка студентов
	printTovars(tovars, numTovar);
	std::cout << "Общая сумма всех заказов: " << SUMM;
	/*/ Поиск студента по имени
	std::string searchName;
	std::cout << "Введите имя студента для поиска: ";
	std::cin >> searchName;

	// Проверка наличия студента в списке и вывод возраста, если он присутствует
	bool found = false;
	for (int i = 0; i < numTovar; i++) {
		if (tovars[i].name == searchName) {
			std::cout << "Возраст студента " << students[i].name << ": " << students[i].age << " лет\n";
			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "Студент с именем " << searchName << " не найден\n";
	}

	// Освобождение памяти, выделенной для массивов */
	delete[] tovars;

	return 0;
}
