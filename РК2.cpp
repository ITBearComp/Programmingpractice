#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FoodItem
{

public:
    string name;
    string date;
    FoodItem(string f_name, string f_date)
    {
        name = f_name;
        date = f_date;
    }
    virtual void display() const
    {
        cout << "Name: " << name << std::endl;
        cout << "Date: " << date << std::endl;
    }
};


class Vegetable : public FoodItem
{
private:
    string type;

public:
    Vegetable(const string name, const string date, const string type)
        : FoodItem(name, date), type(type) {}
    void display() const
    {
        cout << "Vegetable - Name: " << name << ", Date: " << date << ", Type: " << type << endl;
    }
    ~Vegetable();
};

class DairyProduct : public FoodItem {
private:
    double fat;

public:
    DairyProduct(const string name, const string date, double fat)
        : FoodItem(name, date), fat(fat) {}
    void display() const
    {
        cout << "Dairy Product - Name: " << name << ", Date: " << date << ", Fat: " << fat << "%" << endl;
    }
    ~DairyProduct();
};
void modifyFoodItem(FoodItem* item, const string& newName, const string& newdate)
{
    item->name = newName;
    item->date = newdate;
}

int main()
{
    //1
    FoodItem milk("Milk", "17.12.2023");
    milk.display();
    cout << "///////////////////" << endl;

    //2
    FoodItem* item1 = new Vegetable("Cucamber", "16.10.2024", "Vegetable");
    FoodItem* item2 = new DairyProduct("Milk", "20.12.2023", 3.5);
    item1->display();
    item2->display();
    delete item1;
    delete item2;
    cout << "///////////////////" << endl;

    //3-5
    vector<FoodItem*> foodItems;
    foodItems.push_back(new Vegetable("Carrot", "31.10.2023", "Root Vegetable"));
    foodItems.push_back(new DairyProduct("Milk", "15.12.2023", 2));
    foodItems.push_back(new DairyProduct("Yogurt", "10.01.2024", 5));
    for (const auto& item : foodItems) {
        item->display();
    }


    cout << "///////////////////" << endl;

    for (auto& item : foodItems) {
        modifyFoodItem(item, "Modified Product", "01.11.2023");
        item->display();
    }

    // Освобождаем память, выделенную для объектов
    for (const auto& item : foodItems) {
        delete item;
    }
}